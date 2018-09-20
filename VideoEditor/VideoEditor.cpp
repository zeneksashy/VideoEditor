#include "VideoEditor.h"
#include<qmediaplayer.h>
#include<qmediaplaylist.h>
#include <QMediaMetaData>
#include <QStandardPaths>
#include<qfiledialog.h>
#include <QStyle>
#include "Player.h"
#include<Qtime>
#include <QFileDialog>
#include <QMessageBox>
#include"MediaManager.h"

VideoEditor::VideoEditor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	MediaManager::LoadWidget(ui.preview);
	MediaManager::LoadWidget(ui.timeLine);
	connectWdigets();
	ConfigureWindow();
}

void VideoEditor::open()
{
	
	QString filename = QFileDialog::getOpenFileName(this,
		tr("Open Video"), ".",
		tr("Video Files (*.avi *.mpg *.mp4)"));
	if (!filename.isEmpty())
	{
		MediaManager::LoadMedia(filename);
	}
	
}

void VideoEditor::connectWdigets()
{
//	auto g = 
	connect(ui.actiongausian_blur, &QAction::triggered, new GausianBlurWindow(), &GausianBlurWindow::exec);
}

void VideoEditor::ConfigureWindow()
{
	setWindowFlags(Qt::Window
		| Qt::WindowMinimizeButtonHint
		| Qt::WindowMaximizeButtonHint
		| Qt::WindowCloseButtonHint);
	QMainWindow::showMaximized();
	setAcceptDrops(true);
}
