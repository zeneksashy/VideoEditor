#pragma once

#include <QDialog>
#include "ui_MedianBlurWindow.h"
#include "MedianBlur.h"
#include"MediaManager.h"
class MedianBlurWindow : public QDialog
{
	Q_OBJECT
public:
	MedianBlurWindow(QWidget *parent = Q_NULLPTR);
	~MedianBlurWindow();
private slots:
	void applyEffect();
private:
	Ui::MedianBlurWindow ui;
};
