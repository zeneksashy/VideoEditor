#include "QGLCanvas.h"
#include<iostream>
QGLCanvas::QGLCanvas(QWidget *parent)
	: QOpenGLWidget(parent)
{
}

QGLCanvas::~QGLCanvas()
{
}

void QGLCanvas::setImage(const QImage & image)
{
	img = std::move(image);
	this->update();
}

void QGLCanvas::paintEvent(QPaintEvent *)
{
	QPainter p(this);
	p.drawImage(this->rect(), img);
}
