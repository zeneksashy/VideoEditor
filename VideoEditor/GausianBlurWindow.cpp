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
void GausianBlurWindow::OnSizeXvalueChanged()
{
	int val = ui.SizeX->value();
	if (val % 2 == 0)
	{
		ui.SizeX->setValue(val - 1);
	}
}
void GausianBlurWindow::OnSizeYvalueChanged()
{
	int val = ui.SizeY->value();
	if (val % 2 == 0)
	{
		ui.SizeY->setValue(val - 1);
	}
}
void GausianBlurWindow::applyEffect()
{
	double x = ui.XParam->value();
	double y = ui.YParam->value();
	uint sizeX = ui.SizeX->value();
	uint sizeY = ui.SizeY->value();
	GausianBlurParam params;
	params.Create(x, y, sizeX, sizeY);
	//auto cap = MediaManager::player->getVideCapture();
	MediaManager::gBlur->Initialize(params);
	//auto frames = MediaManager::gBlur->ExecuteEffect();
	MediaManager::player->setEffect(MediaManager::gBlur);
	this->hide();
}

void GausianBlurWindow::connectWidgets()
{
	connect(ui.buttonBox, &QDialogButtonBox::accepted, this, &GausianBlurWindow::applyEffect);
	connect(ui.SizeX, &QSpinBox::editingFinished, this, &GausianBlurWindow::OnSizeXvalueChanged);
	connect(ui.SizeY, &QSpinBox::editingFinished, this, &GausianBlurWindow::OnSizeYvalueChanged);
}
