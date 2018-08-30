#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VideoEditor.h"
#include<qmediaplayer.h>
#include<qmediaplaylist.h>
#include<opencv2/opencv.hpp>
#include "Player.h"
#include <QFileDialog>
#include <QMessageBox>

class VideoEditor : public QMainWindow
{
	Q_OBJECT

public:
	VideoEditor(QWidget *parent = Q_NULLPTR);
private slots:
	void open();

private:
	void ConfigureWindow();
	Ui::VideoEditorClass ui;
};
