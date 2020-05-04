#pragma once

#include <QString>
#include <QDomElement>
#include <QDateTime>

#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/VariadicBind.h>

class DataSource
{
public:
	DataSource();
	DataSource(QDomElement projectNode);

	virtual ~DataSource();

	virtual QString userName();
	virtual void setUserName(QString name);

	virtual QString dataName();
	virtual void setDataName(QString name);

	virtual QDateTime importTime();
	virtual void setImportTime(QDateTime time);

	virtual void importData(SQLite::Database &db) = 0;

	static QString primarySourceName();

protected:
	QString userName_;
	QString dataName_;
	QDateTime lastImport_;
	int lastImportTimeS_;
};


