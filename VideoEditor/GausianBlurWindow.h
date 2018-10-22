#pragma once

#include <QDialog>
#include<qbuttongroup.h>
#include "ui_GausianBlurWindow.h"
#include "GausianBlur.h"
#include"MediaManager.h"
class GausianBlurWindow : public QDialog
{
	Q_OBJECT
public:
	GausianBlurWindow(QWidget *parent = Q_NULLPTR);
	~GausianBlurWindow();
private slots:
	void applyEffect();
	void OnSizeXvalueChanged();
	void OnSizeYvalueChanged();
private:
	void connectWidgets();
	Ui::GausianBlurWindow ui;
};
