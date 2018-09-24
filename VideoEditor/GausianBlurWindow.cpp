#include "GausianBlurWindow.h"
#include "GausianBlur.h"

#include"MediaManager.h"
GausianBlurWindow::GausianBlurWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connectWidgets();
	setAttribute(Qt::WA_DeleteOnClose);
}

GausianBlurWindow::~GausianBlurWindow()
{
}
void GausianBlurWindow::applyEffect()
{
	double x = ui.XParam->value();
	double y = ui.YParam->value();
	uint sizeX = ui.SizeX->value();
	uint sizeY = ui.SizeY->value();
	GausianBlurParam params;
	params.Create(x, y, sizeX, sizeY);
	auto cap = MediaManager::player->getVideCapture();
	MediaManager::gBlur->Initialize(cap, params);
	auto frames = MediaManager::gBlur->ExecuteEffect();
	MediaManager::player->setEffect(frames);
	this->hide();
}

void GausianBlurWindow::connectWidgets()
{
	connect(ui.buttonBox, &QDialogButtonBox::accepted, this, &GausianBlurWindow::applyEffect);
}
