#pragma once
#include<qwidget.h>
#include<iostream>
#include <QWidget>
#include<qaudiodecoder.h>
#include<qaudioformat.h>
#include<qpixmap.h>
#include<AudioAnalyser.h>
#include<AudioRecognition.h>
#include <ctime>
#include<qlistwidget.h>
#include"MediaTrack.h"
#include <qmouseeventtransition.h>
#include <QMouseEvent>
#include<qdrag.h>
#include<qmimedata.h>
#include<qbytearray.h>
class MediaTrack: public QWidget
{
	Q_OBJECT
public:
	MediaTrack(QWidget* parent) :QWidget(parent) {}
	virtual ~MediaTrack();
	virtual void drawOutline() = 0;
	virtual void deleteOutline() = 0;
	virtual void ResizeFrame(int) = 0;
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
}; 

