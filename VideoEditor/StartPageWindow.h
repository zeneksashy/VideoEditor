#pragma once

#include <QDialog>
#include "ui_StartPageWindow.h"
#include <qfiledialog.h>


class StartPageWindow : public QDialog
{
	Q_OBJECT

public:
	StartPageWindow(QWidget *parent = Q_NULLPTR);
	~StartPageWindow();
private slots:
	void fileDialogShow();
	void itemSelected(QListWidgetItem*);
	void buttonBoxClicked(QAbstractButton * button);
private:
	void ConifugreUi();
	
	void ConnectUi();
	void SetPath();
	Ui::StartPageWindow ui;
	QString dir;
	QString projPath;
};
