#pragma once

#include <QWidget>
#include "ui_SingleTrack.h"

class SingleTrack : public QWidget
{
	Q_OBJECT

public:
	SingleTrack(QWidget *parent = Q_NULLPTR);
	~SingleTrack();
private slots:
	void OnButtonClick();
private:
	void ConnectUi();
	void ChangeButtonColor();
	void TurnOnOffTrack();
	bool isClicked;
	Ui::SingleTrack ui;
};
