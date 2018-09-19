#pragma once
#include<qstylepainter.h>
#include <QSlider>
#include<QStyleOptionSlider>

class TimeLineSlider : public QSlider
{
	Q_OBJECT

public:
	TimeLineSlider(QWidget *parent);
	 void paintEvent(QPaintEvent*) override;
	~TimeLineSlider();
};
