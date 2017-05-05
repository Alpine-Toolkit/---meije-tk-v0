// -*- mode: c++ -*-
// This file was automatically generated by SqlOrm
/***************************************************************************************************
 *
 * $QTCARTO_BEGIN_LICENSE:GPL3$
 *
 * Copyright (C) 2016 Fabrice Salvaire
 * Contact: http://www.fabrice-salvaire.fr
 *
 * This file is part of the QtCarto library.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $QTCARTO_END_LICENSE$
 *
 **************************************************************************************************/

/**************************************************************************************************/

#ifndef __BLEAUDB_GENERATED_H__
#define __BLEAUDB_GENERATED_H__

/**************************************************************************************************/

#include <QDataStream>
#include <QGeoCoordinate>
#include <QJsonObject>
#include <QSharedPointer>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QVariantList>
#include <QtDebug>

#include "database/schema.h"
#include "database/database_schema.h"
#include "database/database_row.h"

/**************************************************************************************************/

class BBleauPlace;

class BBleauPlaceSchema : public QcSchema
{
public:
  enum Fields {
    COORDINATE,
    NAME,
    CATEGORY,
    NOTE
  };
  static const int NUMBER_OF_FIELDS = 4;

public:
  static BBleauPlaceSchema & instance()
  {
    static BBleauPlaceSchema m_instance;
    return m_instance;
  }

  // delete copy and move constructors and assign operators
  BBleauPlaceSchema(const BBleauPlaceSchema &) = delete;
  BBleauPlaceSchema(BBleauPlaceSchema &&) = delete;
  BBleauPlaceSchema & operator=(const BBleauPlaceSchema &) = delete;
  BBleauPlaceSchema & operator=(BBleauPlaceSchema &&) = delete;

protected:
  BBleauPlaceSchema();
  ~BBleauPlaceSchema();
};

/**************************************************************************************************/

class BBleauPlace : public QObject, public QcRowWithId<BBleauPlaceSchema>
{
  Q_OBJECT
  Q_PROPERTY(QGeoCoordinate coordinate READ coordinate WRITE set_coordinate NOTIFY coordinateChanged)
  Q_PROPERTY(QString name READ name WRITE set_name NOTIFY nameChanged)
  Q_PROPERTY(QString category READ category WRITE set_category NOTIFY categoryChanged)
  Q_PROPERTY(QString note READ note WRITE set_note NOTIFY noteChanged)

public:
  BBleauPlace();
  BBleauPlace(const BBleauPlace & other);
  BBleauPlace(const QJsonObject & json_object); // JSON deserializer
  BBleauPlace(const QVariantHash & variant_hash);
  BBleauPlace(const QVariantList & variants);
  BBleauPlace(const QSqlRecord & record); // SQL deserializer
  BBleauPlace(const QSqlQuery & query); // SQL deserializer
  ~BBleauPlace();

  BBleauPlace & operator=(const BBleauPlace & other);

  bool operator==(const BBleauPlace & other);

  // Getter/Setter

  const QGeoCoordinate & coordinate() const { return m_coordinate; }
  void set_coordinate(const QGeoCoordinate & value);

  const QString & name() const { return m_name; }
  void set_name(const QString & value);

  const QString & category() const { return m_category; }
  void set_category(const QString & value);

  const QString & note() const { return m_note; }
  void set_note(const QString & value);

  // JSON Serializer
  QJsonObject to_json(bool only_changed = false) const;

  // Generic Variant Serializer
  QVariantHash to_variant_hash(bool only_changed = false) const;
  QVariantList to_variant_list() const;

  // SQL Serializer
  QVariantHash to_variant_hash_sql(bool only_changed = false) const;
  QVariantList to_variant_list_sql() const;

  // Query for update
  bool is_coordinate_modified() const { return bit_status(Schema::Fields::COORDINATE); }
  bool is_name_modified() const { return bit_status(Schema::Fields::NAME); }
  bool is_category_modified() const { return bit_status(Schema::Fields::CATEGORY); }
  bool is_note_modified() const { return bit_status(Schema::Fields::NOTE); }

  // Field accessor by position
  QVariant field(int position) const;
  void set_field(int position, const QVariant & value);

  void load_foreign_keys();

signals:
  void coordinateChanged();
  void nameChanged();
  void categoryChanged();
  void noteChanged();

private:
  QGeoCoordinate m_coordinate;
  QString m_name;
  QString m_category;
  QString m_note;
};

QDataStream & operator<<(QDataStream & out, const BBleauPlace & obj);
QDataStream & operator>>(QDataStream & in, BBleauPlace & obj);
// qRegisterMetaTypeStreamOperators<BBleauPlace>("BBleauPlace");

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug debug, const BBleauPlace & obj);
#endif

/**************************************************************************************************/

class BBleauMassif;

class BBleauMassifSchema : public QcSchema
{
public:
  enum Fields {
    COORDINATE,
    NAME,
    ACCESS,
    ALTERNATIVE_NAME,
    CHAOS_TYPE,
    NOTE,
    PARCELLES,
    RDV,
    SECTEUR,
    VELO
  };
  static const int NUMBER_OF_FIELDS = 10;

public:
  static BBleauMassifSchema & instance()
  {
    static BBleauMassifSchema m_instance;
    return m_instance;
  }

  // delete copy and move constructors and assign operators
  BBleauMassifSchema(const BBleauMassifSchema &) = delete;
  BBleauMassifSchema(BBleauMassifSchema &&) = delete;
  BBleauMassifSchema & operator=(const BBleauMassifSchema &) = delete;
  BBleauMassifSchema & operator=(BBleauMassifSchema &&) = delete;

protected:
  BBleauMassifSchema();
  ~BBleauMassifSchema();
};

/**************************************************************************************************/

class BBleauMassif : public QObject, public QcRowWithId<BBleauMassifSchema>
{
  Q_OBJECT
  Q_PROPERTY(QGeoCoordinate coordinate READ coordinate WRITE set_coordinate NOTIFY coordinateChanged)
  Q_PROPERTY(QString name READ name WRITE set_name NOTIFY nameChanged)
  Q_PROPERTY(QString access READ access WRITE set_access NOTIFY accessChanged)
  Q_PROPERTY(QString alternative_name READ alternative_name WRITE set_alternative_name NOTIFY alternative_nameChanged)
  Q_PROPERTY(QString chaos_type READ chaos_type WRITE set_chaos_type NOTIFY chaos_typeChanged)
  Q_PROPERTY(QString note READ note WRITE set_note NOTIFY noteChanged)
  Q_PROPERTY(QString parcelles READ parcelles WRITE set_parcelles NOTIFY parcellesChanged)
  Q_PROPERTY(QString rdv READ rdv WRITE set_rdv NOTIFY rdvChanged)
  Q_PROPERTY(QString secteur READ secteur WRITE set_secteur NOTIFY secteurChanged)
  Q_PROPERTY(QString velo READ velo WRITE set_velo NOTIFY veloChanged)

public:
  BBleauMassif();
  BBleauMassif(const BBleauMassif & other);
  BBleauMassif(const QJsonObject & json_object); // JSON deserializer
  BBleauMassif(const QVariantHash & variant_hash);
  BBleauMassif(const QVariantList & variants);
  BBleauMassif(const QSqlRecord & record); // SQL deserializer
  BBleauMassif(const QSqlQuery & query); // SQL deserializer
  ~BBleauMassif();

  BBleauMassif & operator=(const BBleauMassif & other);

  bool operator==(const BBleauMassif & other);

  // Getter/Setter

  const QGeoCoordinate & coordinate() const { return m_coordinate; }
  void set_coordinate(const QGeoCoordinate & value);

  const QString & name() const { return m_name; }
  void set_name(const QString & value);

  const QString & access() const { return m_access; }
  void set_access(const QString & value);

  const QString & alternative_name() const { return m_alternative_name; }
  void set_alternative_name(const QString & value);

  const QString & chaos_type() const { return m_chaos_type; }
  void set_chaos_type(const QString & value);

  const QString & note() const { return m_note; }
  void set_note(const QString & value);

  const QString & parcelles() const { return m_parcelles; }
  void set_parcelles(const QString & value);

  const QString & rdv() const { return m_rdv; }
  void set_rdv(const QString & value);

  const QString & secteur() const { return m_secteur; }
  void set_secteur(const QString & value);

  const QString & velo() const { return m_velo; }
  void set_velo(const QString & value);

  // JSON Serializer
  QJsonObject to_json(bool only_changed = false) const;

  // Generic Variant Serializer
  QVariantHash to_variant_hash(bool only_changed = false) const;
  QVariantList to_variant_list() const;

  // SQL Serializer
  QVariantHash to_variant_hash_sql(bool only_changed = false) const;
  QVariantList to_variant_list_sql() const;

  // Query for update
  bool is_coordinate_modified() const { return bit_status(Schema::Fields::COORDINATE); }
  bool is_name_modified() const { return bit_status(Schema::Fields::NAME); }
  bool is_access_modified() const { return bit_status(Schema::Fields::ACCESS); }
  bool is_alternative_name_modified() const { return bit_status(Schema::Fields::ALTERNATIVE_NAME); }
  bool is_chaos_type_modified() const { return bit_status(Schema::Fields::CHAOS_TYPE); }
  bool is_note_modified() const { return bit_status(Schema::Fields::NOTE); }
  bool is_parcelles_modified() const { return bit_status(Schema::Fields::PARCELLES); }
  bool is_rdv_modified() const { return bit_status(Schema::Fields::RDV); }
  bool is_secteur_modified() const { return bit_status(Schema::Fields::SECTEUR); }
  bool is_velo_modified() const { return bit_status(Schema::Fields::VELO); }

  // Field accessor by position
  QVariant field(int position) const;
  void set_field(int position, const QVariant & value);

  void load_foreign_keys();

signals:
  void coordinateChanged();
  void nameChanged();
  void accessChanged();
  void alternative_nameChanged();
  void chaos_typeChanged();
  void noteChanged();
  void parcellesChanged();
  void rdvChanged();
  void secteurChanged();
  void veloChanged();

private:
  QGeoCoordinate m_coordinate;
  QString m_name;
  QString m_access;
  QString m_alternative_name;
  QString m_chaos_type;
  QString m_note;
  QString m_parcelles;
  QString m_rdv;
  QString m_secteur;
  QString m_velo;
};

QDataStream & operator<<(QDataStream & out, const BBleauMassif & obj);
QDataStream & operator>>(QDataStream & in, BBleauMassif & obj);
// qRegisterMetaTypeStreamOperators<BBleauMassif>("BBleauMassif");

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug debug, const BBleauMassif & obj);
#endif

/**************************************************************************************************/

class BBleauBoulder;

class BBleauBoulderSchema : public QcSchema
{
public:
  enum Fields {
    COORDINATE,
    NAME,
    COMMENT,
    GRADE,
    NUMBER
  };
  static const int NUMBER_OF_FIELDS = 5;

public:
  static BBleauBoulderSchema & instance()
  {
    static BBleauBoulderSchema m_instance;
    return m_instance;
  }

  // delete copy and move constructors and assign operators
  BBleauBoulderSchema(const BBleauBoulderSchema &) = delete;
  BBleauBoulderSchema(BBleauBoulderSchema &&) = delete;
  BBleauBoulderSchema & operator=(const BBleauBoulderSchema &) = delete;
  BBleauBoulderSchema & operator=(BBleauBoulderSchema &&) = delete;

protected:
  BBleauBoulderSchema();
  ~BBleauBoulderSchema();
};

/**************************************************************************************************/

class BBleauBoulder : public QObject, public QcRowWithId<BBleauBoulderSchema>
{
  Q_OBJECT
  Q_PROPERTY(QGeoCoordinate coordinate READ coordinate WRITE set_coordinate NOTIFY coordinateChanged)
  Q_PROPERTY(QString name READ name WRITE set_name NOTIFY nameChanged)
  Q_PROPERTY(QString comment READ comment WRITE set_comment NOTIFY commentChanged)
  Q_PROPERTY(QString grade READ grade WRITE set_grade NOTIFY gradeChanged)
  Q_PROPERTY(QString number READ number WRITE set_number NOTIFY numberChanged)

public:
  BBleauBoulder();
  BBleauBoulder(const BBleauBoulder & other);
  BBleauBoulder(const QJsonObject & json_object); // JSON deserializer
  BBleauBoulder(const QVariantHash & variant_hash);
  BBleauBoulder(const QVariantList & variants);
  BBleauBoulder(const QSqlRecord & record); // SQL deserializer
  BBleauBoulder(const QSqlQuery & query); // SQL deserializer
  ~BBleauBoulder();

  BBleauBoulder & operator=(const BBleauBoulder & other);

  bool operator==(const BBleauBoulder & other);

  // Getter/Setter

  const QGeoCoordinate & coordinate() const { return m_coordinate; }
  void set_coordinate(const QGeoCoordinate & value);

  const QString & name() const { return m_name; }
  void set_name(const QString & value);

  const QString & comment() const { return m_comment; }
  void set_comment(const QString & value);

  const QString & grade() const { return m_grade; }
  void set_grade(const QString & value);

  const QString & number() const { return m_number; }
  void set_number(const QString & value);

  // JSON Serializer
  QJsonObject to_json(bool only_changed = false) const;

  // Generic Variant Serializer
  QVariantHash to_variant_hash(bool only_changed = false) const;
  QVariantList to_variant_list() const;

  // SQL Serializer
  QVariantHash to_variant_hash_sql(bool only_changed = false) const;
  QVariantList to_variant_list_sql() const;

  // Query for update
  bool is_coordinate_modified() const { return bit_status(Schema::Fields::COORDINATE); }
  bool is_name_modified() const { return bit_status(Schema::Fields::NAME); }
  bool is_comment_modified() const { return bit_status(Schema::Fields::COMMENT); }
  bool is_grade_modified() const { return bit_status(Schema::Fields::GRADE); }
  bool is_number_modified() const { return bit_status(Schema::Fields::NUMBER); }

  // Field accessor by position
  QVariant field(int position) const;
  void set_field(int position, const QVariant & value);

  void load_foreign_keys();

signals:
  void coordinateChanged();
  void nameChanged();
  void commentChanged();
  void gradeChanged();
  void numberChanged();

private:
  QGeoCoordinate m_coordinate;
  QString m_name;
  QString m_comment;
  QString m_grade;
  QString m_number;
};

QDataStream & operator<<(QDataStream & out, const BBleauBoulder & obj);
QDataStream & operator>>(QDataStream & in, BBleauBoulder & obj);
// qRegisterMetaTypeStreamOperators<BBleauBoulder>("BBleauBoulder");

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug debug, const BBleauBoulder & obj);
#endif

/**************************************************************************************************/

class BBleauCircuit;

class BBleauCircuitSchema : public QcSchema
{
public:
  enum Fields {
    COORDINATE,
    COLOUR,
    CREATION_DATE,
    GESTION,
    GRADE,
    MASSIF_SQL,
    NOTE,
    NUMBER,
    OPENER,
    REFECTION_DATE,
    REFECTION_NOTE,
    STATUS,
    TOPOS
  };
  static const int NUMBER_OF_FIELDS = 13;

public:
  static BBleauCircuitSchema & instance()
  {
    static BBleauCircuitSchema m_instance;
    return m_instance;
  }

  // delete copy and move constructors and assign operators
  BBleauCircuitSchema(const BBleauCircuitSchema &) = delete;
  BBleauCircuitSchema(BBleauCircuitSchema &&) = delete;
  BBleauCircuitSchema & operator=(const BBleauCircuitSchema &) = delete;
  BBleauCircuitSchema & operator=(BBleauCircuitSchema &&) = delete;

protected:
  BBleauCircuitSchema();
  ~BBleauCircuitSchema();
};

/**************************************************************************************************/

class BBleauCircuit : public QObject, public QcRowWithId<BBleauCircuitSchema>
{
  Q_OBJECT
  Q_PROPERTY(QGeoCoordinate coordinate READ coordinate WRITE set_coordinate NOTIFY coordinateChanged)
  Q_PROPERTY(QString colour READ colour WRITE set_colour NOTIFY colourChanged)
  Q_PROPERTY(int creation_date READ creation_date WRITE set_creation_date NOTIFY creation_dateChanged)
  Q_PROPERTY(QString gestion READ gestion WRITE set_gestion NOTIFY gestionChanged)
  Q_PROPERTY(QString grade READ grade WRITE set_grade NOTIFY gradeChanged)
  Q_PROPERTY(int massif_sql READ massif_sql WRITE set_massif_sql NOTIFY massif_sqlChanged)
  Q_PROPERTY(QString note READ note WRITE set_note NOTIFY noteChanged)
  Q_PROPERTY(int number READ number WRITE set_number NOTIFY numberChanged)
  Q_PROPERTY(QString opener READ opener WRITE set_opener NOTIFY openerChanged)
  Q_PROPERTY(int refection_date READ refection_date WRITE set_refection_date NOTIFY refection_dateChanged)
  Q_PROPERTY(QString refection_note READ refection_note WRITE set_refection_note NOTIFY refection_noteChanged)
  Q_PROPERTY(QString status READ status WRITE set_status NOTIFY statusChanged)
  Q_PROPERTY(QStringList topos READ topos WRITE set_topos NOTIFY toposChanged)

public:
  BBleauCircuit();
  BBleauCircuit(const BBleauCircuit & other);
  BBleauCircuit(const QJsonObject & json_object); // JSON deserializer
  BBleauCircuit(const QVariantHash & variant_hash);
  BBleauCircuit(const QVariantList & variants);
  BBleauCircuit(const QSqlRecord & record); // SQL deserializer
  BBleauCircuit(const QSqlQuery & query); // SQL deserializer
  ~BBleauCircuit();

  BBleauCircuit & operator=(const BBleauCircuit & other);

  bool operator==(const BBleauCircuit & other);

  // Getter/Setter

  const QGeoCoordinate & coordinate() const { return m_coordinate; }
  void set_coordinate(const QGeoCoordinate & value);

  const QString & colour() const { return m_colour; }
  void set_colour(const QString & value);

  int creation_date() const { return m_creation_date; }
  void set_creation_date(int value);

  const QString & gestion() const { return m_gestion; }
  void set_gestion(const QString & value);

  const QString & grade() const { return m_grade; }
  void set_grade(const QString & value);

  int massif_sql() const { return m_massif_sql; }
  void set_massif_sql(int value);

  const QString & note() const { return m_note; }
  void set_note(const QString & value);

  int number() const { return m_number; }
  void set_number(int value);

  const QString & opener() const { return m_opener; }
  void set_opener(const QString & value);

  int refection_date() const { return m_refection_date; }
  void set_refection_date(int value);

  const QString & refection_note() const { return m_refection_note; }
  void set_refection_note(const QString & value);

  const QString & status() const { return m_status; }
  void set_status(const QString & value);

  const QStringList & topos() const { return m_topos; }
  void set_topos(const QStringList & value);

  // JSON Serializer
  QJsonObject to_json(bool only_changed = false) const;

  // Generic Variant Serializer
  QVariantHash to_variant_hash(bool only_changed = false) const;
  QVariantList to_variant_list() const;

  // SQL Serializer
  QVariantHash to_variant_hash_sql(bool only_changed = false) const;
  QVariantList to_variant_list_sql() const;

  // Query for update
  bool is_coordinate_modified() const { return bit_status(Schema::Fields::COORDINATE); }
  bool is_colour_modified() const { return bit_status(Schema::Fields::COLOUR); }
  bool is_creation_date_modified() const { return bit_status(Schema::Fields::CREATION_DATE); }
  bool is_gestion_modified() const { return bit_status(Schema::Fields::GESTION); }
  bool is_grade_modified() const { return bit_status(Schema::Fields::GRADE); }
  bool is_massif_sql_modified() const { return bit_status(Schema::Fields::MASSIF_SQL); }
  bool is_note_modified() const { return bit_status(Schema::Fields::NOTE); }
  bool is_number_modified() const { return bit_status(Schema::Fields::NUMBER); }
  bool is_opener_modified() const { return bit_status(Schema::Fields::OPENER); }
  bool is_refection_date_modified() const { return bit_status(Schema::Fields::REFECTION_DATE); }
  bool is_refection_note_modified() const { return bit_status(Schema::Fields::REFECTION_NOTE); }
  bool is_status_modified() const { return bit_status(Schema::Fields::STATUS); }
  bool is_topos_modified() const { return bit_status(Schema::Fields::TOPOS); }

  // Field accessor by position
  QVariant field(int position) const;
  void set_field(int position, const QVariant & value);

  void load_foreign_keys();
  QSharedPointer<BBleauMassif> massif();
  void set_massif(QSharedPointer<BBleauMassif> & value);

signals:
  void coordinateChanged();
  void colourChanged();
  void creation_dateChanged();
  void gestionChanged();
  void gradeChanged();
  void massif_sqlChanged();
  void noteChanged();
  void numberChanged();
  void openerChanged();
  void refection_dateChanged();
  void refection_noteChanged();
  void statusChanged();
  void toposChanged();

private:
  QGeoCoordinate m_coordinate;
  QString m_colour;
  int m_creation_date;
  QString m_gestion;
  QString m_grade;
  int m_massif_sql;
  QString m_note;
  int m_number;
  QString m_opener;
  int m_refection_date;
  QString m_refection_note;
  QString m_status;
  QStringList m_topos;
  QSharedPointer<BBleauMassif> m_massif = nullptr;
};

QDataStream & operator<<(QDataStream & out, const BBleauCircuit & obj);
QDataStream & operator>>(QDataStream & in, BBleauCircuit & obj);
// qRegisterMetaTypeStreamOperators<BBleauCircuit>("BBleauCircuit");

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug debug, const BBleauCircuit & obj);
#endif

/**************************************************************************************************/


class BleauSchema : public QcDatabaseSchema
{
public:
  BleauSchema(QcDatabase & database);
  BleauSchema(const BleauSchema & other) = delete;
  ~BleauSchema();

  BleauSchema & operator=(const BleauSchema & other) = delete;

  QcDatabaseTable & place() { return *m_place; }
  QcDatabaseTable & massif() { return *m_massif; }
  QcDatabaseTable & boulder() { return *m_boulder; }
  QcDatabaseTable & circuit() { return *m_circuit; }

private:
  QcDatabaseTable * m_place;
  QcDatabaseTable * m_massif;
  QcDatabaseTable * m_boulder;
  QcDatabaseTable * m_circuit;
};

/**************************************************************************************************/

#endif /* __BLEAUDB-GENERATED_H__ */

/***************************************************************************************************
 *
 * End
 *
 **************************************************************************************************/
