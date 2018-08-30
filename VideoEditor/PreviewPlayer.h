#pragma once

#include <QWidget>
#include "ui_PreviewPlayer.h"
#include <QImage>
#include "Player.h"
#include<QMessageBox>
#include<qmediaplayer.h>

class PreviewPlayer : public QWidget
{
	Q_OBJECT

public:
	PreviewPlayer(QWidget *parent = Q_NULLPTR);
	~PreviewPlayer();
	void loadVideo(QString path);
private slots:
	void updatePlayerUI(QImage img);
	void onPlayButtonClicked();
	void onStopButtonClicked();
	void onPauseButtonCLicked();
	void setGausianBlur();
	void setVideoPosition(int pos);
	void setMaxToTimeLine(int max);
	void updateTimeLine(int value);
	
private:
	QScopedPointer<Player> player;
	Ui::PreviewPlayer ui;
	void configureButtons();
};
