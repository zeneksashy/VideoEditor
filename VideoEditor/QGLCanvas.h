#pragma once
#include <QGLWidget>
#include<qopenglwidget.h>
#include<chrono>
class QGLCanvas : public QOpenGLWidget
{
	Q_OBJECT

public:


	QGLCanvas(QWidget *parent);
	~QGLCanvas();
public slots:
	void setImage(const QImage& image);
signals:
	void sendTime(std::chrono::nanoseconds);
protected:
	void paintEvent(QPaintEvent*);
private:
	QImage img;
};
