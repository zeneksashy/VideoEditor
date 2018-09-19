#pragma once
#include<qstylepainter.h>
#include <QSlider>
#include <QtGui>
#include<qstyleoption.h>
#include<string>
#include <sstream>
class QstyleOptionSlider;
class TimeLineSlider : public QSlider
{
public:
	TimeLineSlider(QWidget *parent = 0):QSlider(parent) {};
	 void paintEvent(QPaintEvent*) override;
private:
	QString convertTime(int sec);
};
