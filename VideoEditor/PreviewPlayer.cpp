#include "PreviewPlayer.h"
#include<qstyle.h>
#include"MediaManager.h"
#include<ctime>
PreviewPlayer::PreviewPlayer(QWidget *parent)
	: QWidget(parent)
{
	i = 0;
	ui.setupUi(this);
	auto media = MediaManager::player->getMediaPlayer();
	connect(MediaManager::player, &Player::processedImage, ui.canvas, &QGLCanvas::setImage);
	connect(MediaManager::player, &Player::positionChanged, this, &PreviewPlayer::updatePlayerUI);
	connect(MediaManager::player, &Player::videoStopped, this, &PreviewPlayer::stopTimeLine);
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
void PreviewPlayer::stopTimeLine()
{
	i = 0;
	updateTimeLine(i);
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
	ui.timeLine->setRange(0, MediaManager::player->getVideCapture()->get(cv::CAP_PROP_FRAME_COUNT));
}
void PreviewPlayer::updatePlayerUI()
{
	updateTimeLine(i);
	++i; 
}
void PreviewPlayer::configureButtons()
{
	ui.playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	ui.stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
	ui.pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
}