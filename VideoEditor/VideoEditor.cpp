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
VideoEditor::VideoEditor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Window
		| Qt::WindowMinimizeButtonHint
		| Qt::WindowMaximizeButtonHint
		| Qt::WindowCloseButtonHint);
	QMainWindow::showMaximized();
	setAcceptDrops(true);
}

void VideoEditor::open()
{
	QString filename = QFileDialog::getOpenFileName(this,
		tr("Open Video"), ".",
		tr("Video Files (*.avi *.mpg *.mp4)"));
	if (!filename.isEmpty())
	{
		ui.preview->loadVideo(filename);
	}
	
}





