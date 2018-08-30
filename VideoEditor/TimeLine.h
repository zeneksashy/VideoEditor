#pragma once

#include <QWidget>
#include "ui_TimeLine.h"
#include <QDragEnterEvent>
#include"VideoLoader.h"
class TimeLine : public QWidget, public VideoLoader
{
	Q_OBJECT

public:
	void loadVideo(QString) override;
	TimeLine(QWidget *parent = Q_NULLPTR);
	~TimeLine();
	void dragEnterEvent(QDragEnterEvent* event);
	void dropEvent(QDropEvent* e);

private:
	void CreateFrame(qint64 size);
	bool CheckMimeTypes(QMimeData& data);
	static const  QStringList supportedFormats;
	static const  std::list<std::string> supportedFormats1;
	Ui::TimeLine ui;
	QScopedPointer<QHBoxLayout> layout;
};
