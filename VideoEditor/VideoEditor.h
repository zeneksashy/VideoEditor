#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VideoEditor.h"

class VideoEditor : public QMainWindow
{
	Q_OBJECT

public:
	VideoEditor(QWidget *parent = Q_NULLPTR);

private:
	Ui::VideoEditorClass ui;
};
