#pragma once

#include <QWidget>
#include "ui_SingleLine.h"

class SingleLine : public QWidget
{
	Q_OBJECT

public:
	SingleLine(QWidget *parent = Q_NULLPTR);
	~SingleLine();

private:
	Ui::SingleLine ui;
};
