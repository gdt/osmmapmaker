#pragma once

#include <QString>
#include <vector>
#include "datasource.h"
#include "stylelayer.h"

#include <filesystem>

using namespace std::filesystem;

class Project
{
public:
	Project(path filename);
	~Project();

	void save();
	void save(path filename);

	std::vector< DataSource*> dataSources()
	{
		return dataSources_;
	}

	void removeDataSource(DataSource* src);
	void addDataSource(DataSource* src);

	std::vector< StyleLayer*> styleLayers()
	{
		return styleLayers_;
	}

	void removeStyleLayer(StyleLayer* l);
	void addStyleLayer(size_t atIndex, StyleLayer *l);

	QColor backgroundColor();
	void setBackgroundColor(QColor c);

	path renderDatabasePath();
	SQLite::Database* renderDatabase();

	path projectPath();

	void createViews();

private:
	void createView(SQLite::Database &db, const QString &viewName, const QString &dataSource, OsmEntityType type, const QString &primaryKey, std::vector<QString> &attributes);

	void createRenderDatabaseIfNotExist();
	void upgradeRenderDatabase();

	QColor backgroundColor_;
	SQLite::Database *db_;
	std::vector< DataSource*> dataSources_;
	std::vector< StyleLayer *> styleLayers_;
	path projectPath_;

};