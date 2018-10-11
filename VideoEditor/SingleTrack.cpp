#include "SingleTrack.h"
#include<iostream>
uint SingleTrack::videoCounter = 0;
uint SingleTrack::audioCounter = 0;
SingleTrack::SingleTrack(QWidget *parent) :isClicked(false),QWidget(parent),audioTracks(0),videoTracks(0)
{
	ui.setupUi(this);
	ConnectUi();
	setAcceptDrops(true);
}

SingleTrack::~SingleTrack()
{
}
void SingleTrack::itemMoved()
{
	ui.tracksLayout->removeWidget(currentTrack);
	currentTrack->show();
}
void SingleTrack::CreateMediaTrack(MediaTrack * track)
{
	 auto audio = dynamic_cast<AudioTrack*>(track);
	 auto video = dynamic_cast<VideoTrack*>(track);
	 if (audio)
	 {
		 ++audioCounter;
		 ui.TrackButton->setText(tr("A") + QString::number(audioCounter));
	 }
	 if (video)
	 {
		 ++videoCounter;
		 ui.TrackButton->setText(tr("V")+ QString::number(videoCounter));
	 }
	 currentTrack = track;
	ui.tracksLayout->addWidget(track);
}

void SingleTrack::dropEvent(QDropEvent * e)
{
	auto str = e->mimeData()->text();
	std::cout <<"drop string"<< str.toStdString()<<"\n";
	auto i = str.toLongLong();
	std::cout << "Drop int" << i<<"\n";
	AudioTrack*  track = (AudioTrack*)i;
	//track = (AudioTrack*)i;
	std::cout << track;
	currentTrack = track;
	ui.tracksLayout->addWidget(track);
//	dataStream >> tr;
//	tr << dataStream;
	//currentTrack = tr;

	//textBrowser->setPlainText(e->mimeData()->text());
	//mimeTypeCombo->clear();
	//mimeTypeCombo->addItems(e->mimeData()->formats());

	//e->acceptProposedAction();
}

void SingleTrack::dragEnterEvent(QDragEnterEvent * event)
{
//	if (event->mimeData()->hasFormat("application/x-dnditemdata"))
		event->acceptProposedAction();
}

void SingleTrack::OnButtonClick()
{
	isClicked = !isClicked;
	ChangeButtonColor();
	TurnOnOffTrack();

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
	if (isClicked)
		return;
	else
	{
		return;
	}
	// implement it !!!!!!!!!
}
