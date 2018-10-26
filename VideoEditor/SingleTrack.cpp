#include "SingleTrack.h"
uint SingleTrack::videoCounter = 0;
uint SingleTrack::audioCounter = 0;

SingleTrack::SingleTrack(QWidget *parent) :isClicked(false),QWidget(parent),audioTracks(0),videoTracks(0),AudioVideo(true),isFirst(true),isAvaible(false)
{
	ui.setupUi(this);
	ConnectUi();
	setAcceptDrops(true);
	opacity = 100;
}

SingleTrack::~SingleTrack()
{
}

void SingleTrack::itemRemoved(MediaTrack* track)
{
	//ui.tracksLayout->removeWidget(track);
}

void SingleTrack::CreateMediaTrack(MediaTrack * track)
{
	 auto audio = dynamic_cast<AudioTrack*>(track);
	 auto video = dynamic_cast<VideoTrack*>(track);
	 if (audio)
	 {
		 ++audioCounter;
		 ui.TrackButton->setText(tr("A") + QString::number(audioCounter));
		 AudioVideo = false;
		 connect(audio->player.get(), &Player::EndOfVideo, this, &SingleTrack::NextTrack);
	 }
	 if (video)
	 {
		 ++videoCounter;
		 ui.TrackButton->setText(tr("V")+ QString::number(videoCounter));
		 connect(video->player.get(), &Player::EndOfVideo, this, &SingleTrack::NextTrack);
		 connect(video->player.get(), &Player::processedImage, this, &SingleTrack::OnImageProcessed);
	 }
	ui.tracksLayout->addWidget(track);
	AssignCurrentToFirst();
	isFirst = false;
}
void SingleTrack::OnImageProcessed(const QImage& img)
{
	emit ImageProcessed(img);
}

void SingleTrack::dropEvent(QDropEvent * e)
{
	auto str = e->mimeData()->text();
	auto i = str.toLongLong();
	MediaTrack*  track = (MediaTrack*)i;
	InsertToMediaTrack(track);
}

void SingleTrack::dragEnterEvent(QDragEnterEvent * event)
{
	event->acceptProposedAction();
}

void SingleTrack::dragLeaveEvent(QDragLeaveEvent * event)
{

}

void SingleTrack::PlayTrack()
{
	currentTrack->PlayMedia();
}

void SingleTrack::PauseTrack()
{
	currentTrack->PauseMedia();
}

void SingleTrack::StopTrack()
{
	currentTrack->StopMedia();
	AssignCurrentToFirst();
}

void SingleTrack::OnButtonClick()
{
	isClicked = !isClicked;
	ChangeButtonColor();
	TurnOnOffTrack();
}

void SingleTrack::NextTrack()
{
	++currentTrackId;
	if (ui.tracksLayout->count()> currentTrackId)
	{
		currentTrack = dynamic_cast<MediaTrack*>(ui.tracksLayout->itemAt(currentTrackId)->widget());
		if (currentTrack)
		{
			isAvaible = true;
			PlayTrack();
		}
		else
		{
			isAvaible = false;
			//currentTrack = nullptr;
			auto interval = dynamic_cast<QSpacerItem*>(ui.tracksLayout->itemAt(currentTrackId))->sizeHint();
			//std::this_thread::sleep_for();
			NextTrack();
		}
		
	}
	else
	{
		isAvaible = false;
	}
	emit MediaAvailability(isAvaible, this);
}

void SingleTrack::InsertToMediaTrack(MediaTrack *track)
{
	auto audio = dynamic_cast<AudioTrack*>(track);
	auto video = dynamic_cast<VideoTrack*>(track);
	if (audio && !AudioVideo)
	{
		ui.tracksLayout->addWidget(track);
	}
	if (video && AudioVideo)
	{
		ui.tracksLayout->addWidget(track);
	}
	track->show();
}

void SingleTrack::ConnectUi()
{
	connect(ui.TrackButton, &QPushButton::clicked, this, &SingleTrack::OnButtonClick);
}

void SingleTrack::ChangeButtonColor()
{
	if (isClicked)
		ui.TrackButton->setStyleSheet("QPushButton{\nbackground-color: rgb(78, 78, 78);\nborder: 1px solid ;\ncolor:white;\nborder-color:qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(0, 32, 75, 255), stop:1 rgba(221, 185, 167, 210));\n border-radius: 5px;\nfont-family: Arial;\n}");
	else
		ui.TrackButton->setStyleSheet("QPushButton{\nbackground-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(90, 181, 237, 255));\nborder: 1px solid ;\ncolor:white;\nborder-color:qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(0, 32, 75, 255), stop:1 rgba(221, 185, 167, 210));\n border-radius: 5px;\nfont-family: Arial;\n}");	
}

void SingleTrack::TurnOnOffTrack()
{
	StopTrack();
	if (isClicked)
		isAvaible = false;
	else
	{
		isAvaible = true;
	}
	emit MediaAvailability(isAvaible, this);
	// implement it !!!!!!!!!
}

void SingleTrack::AssignCurrentToFirst()
{
	if (isFirst)
	{
		
		currentTrack = dynamic_cast<MediaTrack*>(ui.tracksLayout->itemAt(0)->widget());
		if (currentTrack)
		{
			isAvaible=true;
		}
		else
		{
			isAvaible = false;
		}
		emit MediaAvailability(isAvaible, this);
		currentTrackId = 0;
	}
}
