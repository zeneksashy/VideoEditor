#include "ProjectSettingsWIndow.h"
#include "MediaManager.h"
ProjectSettingsWIndow::ProjectSettingsWIndow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ConfigureUi();
	ConnectUi();
}

ProjectSettingsWIndow::~ProjectSettingsWIndow()
{
}

void ProjectSettingsWIndow::saveSettings()
{
	ProjectSettings settings;
	settings.frameHeight = ui.widthEdit->text().toInt();
	settings.frameWidth = ui.widthEdit->text().toInt();
	settings.frameRate = ui.frameRateCombo->currentText().toInt();
	settings.path = (ui.pathEdit->text().append(ui.nameEdit->text())).toStdString();
	MediaManager::project->setProjectSettings(settings);
	this->hide();
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
}

void ProjectSettingsWIndow::resolutionComboBoxChanged(const QString & str)
{
	if (str == "Manual")
	{
		ui.widthEdit->setReadOnly(false);
		ui.heightEdit->setReadOnly(false);
	}
	else
	{
		QStringList list = str.split(QRegExp("\\s+"), QString::SkipEmptyParts);
		ui.widthEdit->setText(list[0]);
		ui.heightEdit->setText(list[2]);
	}
}

void ProjectSettingsWIndow::buttonBoxClicked(QAbstractButton * button)
{
	if ((QPushButton *)button == ui.buttonBox->button(QDialogButtonBox::Ok) || (QPushButton *)button == ui.buttonBox->button(QDialogButtonBox::Apply))
	{
		saveSettings();
	}
	else
	{
		this->close();
	}
}

void ProjectSettingsWIndow::ConfigureUi()
{
	ui.widthEdit->setReadOnly(true);
	ui.heightEdit->setReadOnly(true);
	addFrameRates();
	addResolutions();
	ui.widthEdit->setText("1920");
	ui.heightEdit->setText("1080");
}

void ProjectSettingsWIndow::ConnectUi()
{
	connect(ui.buttonBox, &QDialogButtonBox::accepted, this, &ProjectSettingsWIndow::saveSettings);
	connect(ui.buttonBox, &QDialogButtonBox::clicked, this, &ProjectSettingsWIndow::buttonBoxClicked);
	connect(ui.videoFormatCombo, QOverload<const QString &>::of(&QComboBox::currentIndexChanged), this, &ProjectSettingsWIndow::resolutionComboBoxChanged);
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
