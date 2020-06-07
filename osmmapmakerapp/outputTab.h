#pragma once

#include <QWidget>
#include <QListWidgetItem>

#include "render.h"

namespace Ui {
	class OutputTab;
}

class OutputTab : public QWidget
{
	Q_OBJECT

public:
	OutputTab(QWidget *parent = 0);
	~OutputTab();

	void setProject(Project *project);


private slots:
	void on_generate_clicked();
	void on_outputNew_clicked();
	void on_outputCopy_clicked();
	void on_outputDelete_clicked();
	void on_outputList_currentRowChanged(int currentRow);
	void on_outputList_itemChanged(QListWidgetItem *item);

	// tile signals
	void on_maxZoom_editingFinished();
	void on_minZoom_editingFinished();
	void on_tileCreate1xRes_clicked();
	void on_tileCreate2xRes_clicked();
	void on_tilePath_editingFinished();
	void on_tileOutputPathUseProjectDir_clicked();
	void on_tileSize_currentIndexChanged(int i);

private:
	void saveTile();
	void saveDefaultPathIntoTilePath();

	std::pair<double, double> fromPixelToLL(int tileSize, std::pair<double, double> px, int zoom);
	std::pair<double, double> fromLLtoPixel(int tileSize, std::pair<double, double> ll, int zoom);

	void RenderTile(Render &render, const path &imagePath, int tileSize,int resolutionScale, int x, int y, int z);

	bool surpressSelectionChange_;

	Project *project_;

	Ui::OutputTab *ui;
};

