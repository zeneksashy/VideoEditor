#include "VideoEditor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VideoEditor w;
	w.show();
	return a.exec();
}
