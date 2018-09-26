#pragma once

#include <QDialog>
#include "ui_ProjectSettingsWIndow.h"

class ProjectSettingsWIndow : public QDialog
{
	Q_OBJECT

public:
	ProjectSettingsWIndow(QWidget *parent = Q_NULLPTR);
	~ProjectSettingsWIndow();

private:
	void ConfigureUi();
	void addResolutions();
	void addFrameRates();
	Ui::ProjectSettingsWIndow ui;
};
