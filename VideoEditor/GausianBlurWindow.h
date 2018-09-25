#pragma once

#include <QDialog>
#include<qbuttongroup.h>
#include "ui_GausianBlurWindow.h"

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
