#pragma once

#include <QWidget>
#include "ui_TimeLine.h"
#include <QDragEnterEvent>
#include"AudioRecognition.h"
#include"VideoLoader.h"
#include<AudioFrame.h>
#include <QAudioDecoder>
#include"VideoFrame.h"
#include<qpainter.h>
#include<map>
#include <QtGui>
#include <QtWidgets>
class TimeLine : public QWidget, public VideoLoader
{
	Q_OBJECT

public:
	void loadFile(QString) override;
	TimeLine(QWidget *parent = Q_NULLPTR);
	void dragEnterEvent(QDragEnterEvent* event);
	void dropEvent(QDropEvent* e);
	void paintEvent(QPaintEvent *)override;
	bool eventFilter(QObject* watched, QEvent* event);

private slots:
	void updateTime(qint64 pos);
	void itemSelected(QListWidgetItem*);
	void LineSelected(MediaFrame*);
private:

	//to delete ?
	int i;
	void ResizeFrames(QPoint);
	void wheelEvent(QWheelEvent *e)override;
	void UpdateTimeLabel(qint64 pos);
	void UpdateTimeLine(qint64 pos);
	QScopedPointer<QAudioDecoder> decoder;
	QScopedPointer<AudioAnalyser> analyser;
	bool CheckAudio();
	bool CheckVideo();
	AudioRecognition recognizer;
	VideoFrame* CreateVideoFrame(QString);
	std::vector<QAudioBuffer> buffers;
	AudioFrame* CreateAudioFrame(QString);
	static const  QStringList supportedFormats;
	static const  std::list<std::string> supportedFormats1;
	Ui::TimeLine ui;
	QScopedPointer<QHBoxLayout> layout;
	std::map<QListWidgetItem*, AudioFrame*> audioSources;
	std::map<QListWidgetItem*, VideoFrame*> videoSources;
};


class Overlay : public QWidget {
public:
	explicit Overlay(QWidget *parent = nullptr) : QWidget(parent) {
		setAttribute(Qt::WA_NoSystemBackground);
		setAttribute(Qt::WA_TransparentForMouseEvents);
	}
protected:
	void paintEvent(QPaintEvent *) override {
		QPainter p(this);
		p.setPen(Qt::red);
		QLine line(5, 0, 5, rect().height());
		p.drawLine(line);

	}
};

class OverlayFactoryFilter : public QObject {
	QPointer<Overlay> m_overlay;
public:
	explicit OverlayFactoryFilter(QObject *parent = nullptr) : QObject(parent) {}
protected:
	bool eventFilter(QObject *obj, QEvent *ev) override {
		if (!obj->isWidgetType()) return false;
		auto w = static_cast<QWidget*>(obj);
		if (ev->type() == QEvent::MouseButtonPress) {
			if (!m_overlay) m_overlay = new Overlay;
			m_overlay->setParent(w);
			m_overlay->resize(w->size());
			m_overlay->show();
		}
		else if (ev->type() == QEvent::Resize) {
			if (m_overlay && m_overlay->parentWidget() == w)
				m_overlay->resize(w->size());
		}
		return false;
	}
};
