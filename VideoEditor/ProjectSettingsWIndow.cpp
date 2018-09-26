#include "ProjectSettingsWIndow.h"

ProjectSettingsWIndow::ProjectSettingsWIndow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ConfigureUi();
}

ProjectSettingsWIndow::~ProjectSettingsWIndow()
{
}

void ProjectSettingsWIndow::addFrameRates()
{
	ui.frameRateCombo->addItem(tr("29.970"));
	ui.frameRateCombo->addItem(tr("25.000"));
	ui.frameRateCombo->addItem(tr("30.000"));
	ui.frameRateCombo->addItem(tr("23.976"));
	ui.frameRateCombo->addItem(tr("50.000"));
	ui.frameRateCombo->addItem(tr("60.000"));
	ui.frameRateCombo->addItem(tr("29.940"));
	ui.frameRateCombo->addItem(tr("24.000"));
	ui.frameRateCombo->addItem(tr("Manual"));
}

void ProjectSettingsWIndow::ConfigureUi()
{
	ui.widthEdit->setReadOnly(true);
	ui.heightEdit->setReadOnly(true);
	addFrameRates();
	addResolutions();
}

void ProjectSettingsWIndow::addResolutions()
{
	ui.videoFormatCombo->addItem(tr("1920 x 1080 - HD"));
	ui.videoFormatCombo->addItem(tr("1280 x 720 - HD"));
	ui.videoFormatCombo->addItem(tr("3840 × 2160 - 4K"));
	ui.videoFormatCombo->addItem(tr("7680 × 4320 - 8K"));
	ui.videoFormatCombo->addItem(tr("15360 x 8640 - 16K"));
	ui.videoFormatCombo->addItem(tr("640 x 480 - SD"));
	ui.videoFormatCombo->addItem(tr("Manual"));
}
