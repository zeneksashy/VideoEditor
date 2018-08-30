#pragma once

#include <QWidget>
#include "ui_TimeLine.h"
#include <QDragEnterEvent>
class TimeLine : public QWidget
{
	Q_OBJECT

public:
	TimeLine(QWidget *parent = Q_NULLPTR);
	~TimeLine();
	void dragEnterEvent(QDragEnterEvent* event);
	void dropEvent(QDropEvent*);

private:
	void CreateFrame();
	bool CheckMimeTypes(QMimeData& data);
	static const  QStringList supportedFormats;
	static const  std::list<std::string> supportedFormats1;
	Ui::TimeLine ui;
	QScopedPointer<QHBoxLayout> layout;
};
