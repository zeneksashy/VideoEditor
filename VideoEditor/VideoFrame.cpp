#include "VideoFrame.h"
#include<qpainter.h>
VideoFrame::VideoFrame(QWidget *parent)
	: QWidget(parent)
{
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setMinimumHeight(60);
	setFixedHeight(60);
	setMinimumWidth(120);
	isSelected = false;
}

VideoFrame::~VideoFrame()
{
	capture.release();
}
void VideoFrame::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	painter.fillRect(rect(), Qt::gray);
	QSize size(rect().size());
	size.setWidth(size.height()*1.7);
	painter.drawImage(QPoint(0, 0), img[0].scaled(size));
	painter.drawImage(QPoint(templenght /2, 0), img[1].scaled(size));
	painter.drawImage(QPoint(templenght -size.width(), 0), img[2].scaled(size));
	if (isSelected)
	{
		QPen pen(QColor::fromRgb(126, 253, 61));
		painter.setPen(pen);
		painter.drawRoundedRect(0, 0, width() - 1, height() - 1, 0, 0);
	}
}
void VideoFrame::Initliaize(QString filename)
{
	capture.open(filename.toStdString());
	if (capture.isOpened())
	{
		framecount= (long)capture.get(CV_CAP_PROP_FRAME_COUNT);
		img[0] = loadFrame(100);
		img[1] = loadFrame(framecount / 2);
		img[2] = loadFrame(framecount - 1);
		framerate = capture.get(CV_CAP_PROP_FPS);
		lenght = framecount/framerate;
		templenght = lenght;
		setFixedWidth(lenght);
	}
}

QImage VideoFrame::loadFrame(long pos)
{
	capture.set(CV_CAP_PROP_POS_MSEC, pos);
	QImage img;
	if (capture.read(frame))
	{
		if (frame.channels() == 3)
		{
			cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
			img = QImage((const unsigned char*)(RGBframe.data),
				RGBframe.cols, RGBframe.rows, QImage::Format_RGB888);
		}
		else
		{
			img = QImage((const unsigned char*)(frame.data),
				frame.cols, frame.rows, QImage::Format_Indexed8);
		}
	}
	return img;
}

void VideoFrame::drawOutline()
{
	isSelected = true;
	repaint();
}

void VideoFrame::mousePressEvent(QMouseEvent *)
{
	emit LineSelected(this);
}

void VideoFrame::ResizeFrame(int p)
{
	try
	{
		templenght = lenght;
		templenght = lenght * p;
		setFixedWidth(templenght);
		repaint();
	}
	catch (const std::exception& e )
	{
		e.what();
	}

}

void VideoFrame::deleteOutline()
{
	isSelected = false;
	repaint();
}
