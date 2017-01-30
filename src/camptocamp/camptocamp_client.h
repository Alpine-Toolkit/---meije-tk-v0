// -*- mode: c++ -*-

/***************************************************************************************************
**
** $QTCARTO_BEGIN_LICENSE:GPL3$
**
** Copyright (C) 2017 Fabrice Salvaire
** Contact: http://www.fabrice-salvaire.fr
**
** This file is part of the QtCarto library.
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
** $QTCARTO_END_LICENSE$
**
***************************************************************************************************/

/**************************************************************************************************/

#ifndef __CAMPTOCAMP_H__
#define __CAMPTOCAMP_H__

/**************************************************************************************************/

#include "camptocamp_login.h"
#include "camptocamp_constant.h"

#include <QDateTime>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QPointer>
#include <QString>
#include <QStringList>
#include <QUrl>

/**************************************************************************************************/

class C2cLoginData
{
public:
  C2cLoginData();
  C2cLoginData(const C2cLoginData & other);
  ~C2cLoginData();

  C2cLoginData & operator=(const C2cLoginData & other);

  void from_json(const QJsonDocument * json_document);
  void reset();

  bool is_valid() const { return m_id > 0; }
  explicit operator bool() const { return is_valid(); }
  bool is_expired() const { return QDateTime::currentDateTime() >= m_expire; }

  const QString & language() const { return m_language; }
  void set_language(const QString & language) { m_language = language; }

  const QDateTime & expire() const { return m_expire; }
  void set_expire(const QDateTime & expire) { m_expire = expire; }

  unsigned int id() const { return m_id; }
  void set_id(unsigned int id) { m_id = id; }

  const QString & token() const { return m_token; }
  void set_token(const QString & token) { m_token = token; }

  const QString & forum_username() const { return m_forum_username; }
  void set_forum_username(const QString & forum_username) { m_forum_username = forum_username; }

  const QString & name() const { return m_name; }
  void set_name(const QString & name) { m_name = name; }

  const QString & roles() const { return m_roles; }
  void set_roles(const QString & roles) { m_roles = roles; }

  const QString & redirect_internal() const { return m_redirect_internal; }
  void set_redirect_internal(const QString & redirect_internal) { m_redirect_internal = redirect_internal; }

  const QString & username() const { return m_username; }
  void set_username(const QString & username) { m_username = username; }

private:
  QString m_language;
  QDateTime m_expire;
  unsigned int m_id;
  QString m_token;
  QString m_forum_username;
  QString m_name;
  QString m_roles;
  QString m_redirect_internal;
  QString m_username;
};

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug debug, const C2cLoginData & login_data);
#endif

/**************************************************************************************************/

class C2cSearchSettings
{
public:
  C2cSearchSettings();
  C2cSearchSettings(const C2cSearchSettings & other);
  ~C2cSearchSettings();

  C2cSearchSettings & operator=(const C2cSearchSettings & other);

  const QString & language() const { return m_language; }
  void set_language(const QString & language) { m_language = language; }

  unsigned int limit() const { return m_limit; }
  void set_limit(unsigned int limit) { m_limit = limit; }

  bool area() const { return m_area; }
  void set_area(bool area) { m_area = area; }

  bool article() const { return m_article; }
  void set_article(bool article) { m_article = article; }

  bool book() const { return m_book; }
  void set_book(bool book) { m_book = book; }

  bool image() const { return m_image; }
  void set_image(bool image) { m_image = image; }

  bool map() const { return m_map; }
  void set_map(bool map) { m_map = map; }

  bool outing() const { return m_outing; }
  void set_outing(bool outing) { m_outing = outing; }

  bool route() const { return m_route; }
  void set_route(bool route) { m_route = route; }

  bool userprofile() const { return m_userprofile; }
  void set_userprofile(bool userprofile) { m_userprofile = userprofile; }

  bool waypoint() const { return m_waypoint; }
  void set_waypoint(bool waypoint) { m_waypoint = waypoint; }

  bool xreport() const { return m_xreport; }
  void set_xreport(bool xreport) { m_xreport = xreport; }

  QString type_letters() const;

private:
  QString m_language;
  unsigned int m_limit;
  bool m_area;
  bool m_article;
  bool m_book;
  bool m_image;
  bool m_map;
  bool m_outing;
  bool m_route;
  bool m_userprofile;
  bool m_waypoint;
  bool m_xreport;
};

/**************************************************************************************************/

class C2cClient;

class C2cRequest : public QObject
{
  Q_OBJECT

public:
  C2cRequest(const QNetworkRequest & request); // parent
  ~C2cRequest(); // Fixme: delete this and m_reply

  const QUrl url() const { return m_request.url(); }
  const QNetworkRequest & request() const { return m_request; }

  void set_reply(C2cClient * client, QNetworkReply * network_reply);

  C2cClient * client() const { return m_client; }

  virtual void handle_reply(const QJsonDocument * json_data) = 0; // Fixme: const
  virtual void handle_error(const QJsonDocument * json_data) = 0;
  virtual void handle_network_error() = 0;

private slots:
  void finished();
  // Fixme: void error(Error error, const QString & error_string = QString());

private:
  QJsonDocument * reply_to_json() const;
  static bool check_json_response(const QJsonDocument * json_data);

private:
  QNetworkRequest m_request;
  QPointer<QNetworkReply> m_network_reply;
  QPointer<C2cClient> m_client;
};

/**************************************************************************************************/

class C2cClient : public QObject
{
  Q_OBJECT

public:
  C2cClient(const QString & api_url = c2c::OFFICIAL_API_URL, int port = -1);

  void login(const C2cLogin & login, bool remember = true, bool discourse = true);
  void update_login();
  bool is_logged() const { return m_login_data.is_valid(); }

  void health();

  void area(unsigned int document_id);
  void image(unsigned int document_id);
  void map(unsigned int document_id);
  void outing(unsigned int document_id);
  void user_profile(unsigned int user_id = 0);
  void route(unsigned int document_id);
  void xreport(unsigned int document_id);
  void waypoint(unsigned int document_id);

  void search(const QString & search_string, const C2cSearchSettings & settings);

  void post(const QJsonDocument * json_document);
  void update(const QJsonDocument * json_document, const QString & message = "");

signals:
  void logged();
  void login_failed();
  void received_health_status(const QJsonDocument * json_document);
  void get_health_failed(const QJsonDocument * json_document);
  void received_search(const QJsonDocument * json_document);
  void search_failed(const QJsonDocument * json_document);
  void received_document(const QJsonDocument * json_document);
  void get_document_failed(const QJsonDocument * json_document);

private:
  QUrl make_url(const QString & url) const;
  QUrl make_url(const QStringList & strings) const;
  QNetworkRequest create_network_request(const QUrl & url, bool token = false) const;
  QNetworkRequest create_network_request(const QStringList & strings, bool token = false) const;
  void get(C2cRequest * request);
  void get_document(const QString & document_type, unsigned int document_id);
  QUrl make_url_for_document(const QJsonDocument * json_document) const;
  void post(C2cRequest * request, const QJsonDocument * json_document, bool check_login = true);

public: // Fixme: wrong design
  void handle_login_reply(const QJsonDocument * json_data);
  void handle_login_error(const QJsonDocument * json_data);
  void handle_health_reply(const QJsonDocument * json_data);
  void handle_health_error(const QJsonDocument * json_data);
  void handle_search_reply(const QJsonDocument * json_data);
  void handle_search_error(const QJsonDocument * json_data);
  void handle_document_reply(const QJsonDocument * json_data);
  void handle_document_error(const QJsonDocument * json_data);

private:
  QString m_api_url;
  int m_port;
  C2cLogin m_login;
  C2cLoginData m_login_data;
  QNetworkAccessManager m_network_manager;
};

/**************************************************************************************************/

#endif /* __CAMPTOCAMP_H__ */

/***************************************************************************************************
 *
 * End
 *
 **************************************************************************************************/
