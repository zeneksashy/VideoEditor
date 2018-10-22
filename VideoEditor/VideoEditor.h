#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VideoEditor.h"
#include<qmediaplayer.h>
#include<qmediaplaylist.h>
#include "Player.h"
#include <QFileDialog>
#include <QMessageBox>
#include"GausianBlurWindow.h"
#include "ProjectSettingsWIndow.h"
#include <QMediaMetaData>
#include <QStandardPaths>
#include <QStyle>
#include "Player.h"
#include<Qtime>
#include"MediaManager.h"
#include "StartPageWindow.h"

class VideoEditor : public QMainWindow
{
	Q_OBJECT

public:
	VideoEditor(QWidget *parent = Q_NULLPTR);
private slots:
	void open();
	void saveProject();
private:
	
	QScopedPointer<ProjectSettingsWIndow> settings;
	void connectWdigets();
	void ConfigureWindow();
	Ui::VideoEditorClass ui;
};
