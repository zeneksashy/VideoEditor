#pragma once
#include <QWidget>
#include "ui_PreviewPlayer.h"
#include <QImage>
#include "Player.h"
#include<QMessageBox>
#include<qmediaplayer.h>
#include"VideoLoader.h"
class PreviewPlayer :public QWidget, public VideoLoader
{
	Q_OBJECT

public:
	PreviewPlayer(QWidget *parent = Q_NULLPTR);
	~PreviewPlayer();
	void loadFile(QString path) override;
private slots:
	void updatePlayerUI();
	void onPlayButtonClicked();
	void onStopButtonClicked();
	void onPauseButtonCLicked();
	void setVideoPosition(int pos);
	void setMaxToTimeLine(int max);
	void updateTimeLine(int value);
	void stopTimeLine();
private:
	int i;
	Ui::PreviewPlayer ui;
	void configureButtons();
};
