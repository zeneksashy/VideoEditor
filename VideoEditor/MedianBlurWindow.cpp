#include "MedianBlurWindow.h"

MedianBlurWindow::MedianBlurWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

MedianBlurWindow::~MedianBlurWindow()
{
}
void MedianBlurWindow::applyEffect()
{
	MedianBlur blur;
	auto cap = MediaManager::player->getVideCapture();
	blur.Initialize(cap, ui.kernel->value());
	auto frames = blur.ExecuteEffect();
	MediaManager::player->setEffect(frames);
	this->close();
}