#include "PreviewPlayer.h"
#include<qstyle.h>
PreviewPlayer::PreviewPlayer(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	player.reset(new Player);
	auto media = player->getMediaPlayer();
	connect(media, &QMediaPlayer::durationChanged, this, &PreviewPlayer::setMaxToTimeLine);
	connect(media, &QMediaPlayer::positionChanged, this, &PreviewPlayer::updateTimeLine);
	connect(player.data(), SIGNAL(processedImage(QImage)), this, SLOT(updatePlayerUI(QImage)));
	connect(ui.volumeSlider, &QSlider::valueChanged, media, &QMediaPlayer::setVolume);
	connect(ui.timeLine, &QSlider::valueChanged, this, &PreviewPlayer::setVideoPosition);
	configureButtons();
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
	if (player->isStopped())
	{
		player->Play();
		
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
	if (!player->isStopped())
	{
		
		player->Stop();
	}
}

void PreviewPlayer::onPauseButtonCLicked()
{
	if(!player->isStopped())
	{
		player->Pause();
	}
}
void PreviewPlayer::setGausianBlur()
{
	player->effect();
}
void PreviewPlayer::setVideoPosition(int pos)
{
	player->setVideoPosition(pos);

}
void PreviewPlayer::loadVideo(QString path)
{
	if (!player->loadVideo(path))
	{
		QMessageBox msgBox;
		msgBox.setText("The selected video could not be opened!");
		msgBox.exec();
	}
}
void PreviewPlayer::updatePlayerUI(QImage img)
{
	if (!img.isNull())
	{
		ui.previewLabel->setAlignment(Qt::AlignCenter);
		ui.previewLabel->setPixmap(QPixmap::fromImage(img).scaled(ui.previewLabel->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}
void PreviewPlayer::configureButtons()
{
	ui.playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	ui.stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
	ui.pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
}