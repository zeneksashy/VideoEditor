#include "PreviewPlayer.h"
#include<qstyle.h>
#include"MediaManager.h"
#include<ctime>
PreviewPlayer::PreviewPlayer(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	player.reset(new Player);
	auto media = MediaManager::player->getMediaPlayer();
	connect(media, &QMediaPlayer::durationChanged, this, &PreviewPlayer::setMaxToTimeLine);
	connect(media, &QMediaPlayer::positionChanged, this, &PreviewPlayer::updateTimeLine);
	//connect(MediaManager::player, SIGNAL(processedImage(QImage)), this, SLOT(updatePlayerUI(QImage)));
	connect(MediaManager::player, &Player::processedImage, ui.canvas, &QGLCanvas::setImage);
	connect(ui.volumeSlider, &QSlider::valueChanged, media, &QMediaPlayer::setVolume);
	connect(ui.timeLine, &QSlider::valueChanged, this, &PreviewPlayer::setVideoPosition);
	connect(ui.canvas, &QGLCanvas::sendTime, MediaManager::player, &Player::recieveTime);
	configureButtons();
	
	//ui.previewLabel->setAlignment(Qt::AlignCenter);
}

PreviewPlayer::~PreviewPlayer()
{
}


void PreviewPlayer::setMaxToTimeLine(int max)
{
	ui.timeLine->setRange(0, max);
}
void PreviewPlayer::onPlayButtonClicked()
{
	if (MediaManager::player->isStopped())
	{
		MediaManager::player->Play();
	}
}
void PreviewPlayer::updateTimeLine(int value)
{
	if (!ui.timeLine->isSliderDown())
	{
		ui.timeLine->blockSignals(true);
		ui.timeLine->setValue(value);
		ui.timeLine->blockSignals(false);
	}
		
}
void PreviewPlayer::onStopButtonClicked()
{
	if (!MediaManager::player->isStopped())
	{
		
		MediaManager::player->Stop();
	}
}

void PreviewPlayer::onPauseButtonCLicked()
{
	if(!MediaManager::player->isStopped())
	{
		MediaManager::player->Pause();
	}
}
void PreviewPlayer::setGausianBlur()
{
//	MediaManager::player->effect();
}
void PreviewPlayer::setVideoPosition(int pos)
{
	MediaManager::player->setVideoPosition(pos);

}
void PreviewPlayer::loadFile(QString path)
{
	if (!MediaManager::player->loadFile(path))
	{
		QMessageBox msgBox;
		msgBox.setText("The selected video could not be opened!");
		msgBox.exec();
	}
}
void PreviewPlayer::updatePlayerUI(QImage img)
{
	ui.canvas->setImage(img);
	//ui.previewLabel->setPixmap(QPixmap::fromImage(img).scaled(ui.previewLabel->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
}
void PreviewPlayer::configureButtons()
{
	ui.playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	ui.stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
	ui.pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
}