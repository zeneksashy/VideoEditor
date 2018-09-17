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
}
void VideoFrame::paintEvent(QPaintEvent*)
{
	
	QPainter painter(this);
	painter.fillRect(rect(), Qt::gray);
	QSize size(rect().size());
	if (isSelected)
	{
		pen.setColor(QColor::fromRgb(126, 253, 61));
		painter.setPen(pen);
		painter.drawRoundedRect(0, 0, width() - 1, height() - 1, 0, 0);
	}
	size.setWidth(size.height()*1.7);
	painter.drawImage(QPoint(0, 0), img[0].scaled(size));
	painter.drawImage(QPoint(framecount/2, 0), img[1].scaled(size));
	painter.drawImage(QPoint(framecount-size.width(), 0), img[2].scaled(size));
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
		setFixedWidth(framecount);
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
	drawOutline();

}

void VideoFrame::deleteOutline()
{
	isSelected = false;
	repaint();
}
