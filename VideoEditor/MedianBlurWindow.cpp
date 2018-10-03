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
	blur.Initialize(ui.kernel->value());
	auto frames = blur.ExecuteEffect();
	MediaManager::player->setEffect(frames);
	this->close();
}