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
	auto start = std::chrono::system_clock::now();
	img = std::move(image);
	this->update();
	auto end = std::chrono::system_clock::now();
	auto nano = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	emit sendTime(nano);
	//std::cout << "czas wykonania " << nano.count() << "\n";
}

void QGLCanvas::paintEvent(QPaintEvent *)
{
	QPainter p(this);
	p.setRenderHint(QPainter::SmoothPixmapTransform);
	p.drawImage(this->rect(), img);
}
