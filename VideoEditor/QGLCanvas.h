#pragma once
#include <QGLWidget>
#include<qopenglwidget.h>
#include<ctime>
class QGLCanvas : public QOpenGLWidget
{
	Q_OBJECT

public:
	QGLCanvas(QWidget *parent);
	~QGLCanvas();
public slots:
	void setImage(const QImage& image);
protected:

	void paintEvent(QPaintEvent*);
private:
	QImage img;
};
