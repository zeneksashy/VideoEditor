#include "StartPageWindow.h"
#include <stdlib.h> 
#include<qdir.h>
#include<qlistwidget.h>
#include "ProjectSettingsWIndow.h"
#include<qmessagebox.h>
#include "MediaManager.h"
StartPageWindow::StartPageWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
	ui.openToolButton->setIcon(style()->standardIcon(QStyle::SP_FileDialogStart));
	dir = tr(getenv("USERPROFILE"));
	dir += "\\Documents";
	SetPath();
	ConnectUi();
	//ConifugreUi();
}

StartPageWindow::~StartPageWindow()
{
}
void StartPageWindow::fileDialogShow()
{
	 dir = QFileDialog::getExistingDirectory(this,
		tr("Open Directory"), dir,
		QFileDialog::ShowDirsOnly
		| QFileDialog::DontResolveSymlinks);
	 SetPath();
}
void StartPageWindow::ConifugreUi()
{
	ui.pathsList->clear();
	QDir directory;
	directory.setPath(dir);
	directory.setNameFilters(QStringList() << "*.ediproj");
	auto files = directory.entryList();
	for each (auto var in files)
	{
		auto item = new QListWidgetItem(var, ui.pathsList);
	}
}
void StartPageWindow::itemSelected(QListWidgetItem * item)
{
	projPath = ui.projectPath->text()+tr("\\")+ item->text();
}
void StartPageWindow::buttonBoxClicked(QAbstractButton* button)
{
	if (button == ui.buttonBox->button(QDialogButtonBox::Ok))
	{
		if (projPath.isEmpty())
		{
			QMessageBox msgBox;
			msgBox.setText("No project selected");
			msgBox.exec();
		}
		else
		{
			MediaManager::Deserialize(projPath.toStdString());
			this->hide();
		}
	}
	else
	{
		exit(0);
	}
}
void StartPageWindow::ConnectUi()
{
	connect(ui.openToolButton, &QToolButton::clicked, this, &StartPageWindow::fileDialogShow);
	connect(ui.buttonBox, &QDialogButtonBox::clicked, this, &StartPageWindow::buttonBoxClicked);
	connect(ui.pathsList, &QListWidget::itemClicked, this, &StartPageWindow::itemSelected);
	connect(ui.newProjectButton, &QPushButton::clicked, [this]() {this->hide(); auto x = new ProjectSettingsWIndow(); x->exec(); });
}

void StartPageWindow::SetPath()
{
	if (!dir.isEmpty())
	{
		ui.projectPath->setText(dir);
		ConifugreUi();
	}
		
}
