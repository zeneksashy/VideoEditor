
#include "SingleTrack.h"

SingleTrack::SingleTrack(QWidget *parent) :isClicked(false),QWidget(parent)
{
	ui.setupUi(this);
}

SingleTrack::~SingleTrack()
{
}

void SingleTrack::OnButtonClick()
{
	isClicked = !isClicked;
	ChangeButtonColor();

}
void SingleTrack::ConnectUi()
{
	connect(ui.TrackButton, &QPushButton::clicked, this, &SingleTrack::OnButtonClick);
}

void SingleTrack::ChangeButtonColor()
{
	QPalette pal = ui.TrackButton->palette();
	pal.setColor(QPalette::Button, QColor(Qt::gray));
	ui.TrackButton->setAutoFillBackground(true);
	ui.TrackButton->setPalette(pal);
	ui.TrackButton->update();
}

void SingleTrack::TurnOnOffTrack()
{

}
