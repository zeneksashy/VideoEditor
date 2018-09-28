#pragma once

#include <QDialog>
#include "ui_ProjectSettingsWIndow.h"
#include "Project.h"
#include <qabstractbutton.h>
class ProjectSettingsWIndow : public QDialog
{
	Q_OBJECT

public:
	ProjectSettingsWIndow(QWidget *parent = Q_NULLPTR);
	~ProjectSettingsWIndow();
private slots:
	void saveSettings();
	void resolutionComboBoxChanged(const QString&);
	void buttonBoxClicked(QAbstractButton *);
private:
	void ConfigureUi();
	void ConnectUi();
	void addResolutions();
	void addFrameRates();
	Ui::ProjectSettingsWIndow ui;
};
