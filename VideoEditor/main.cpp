#include "VideoEditor.h"
#include <QtWidgets/QApplication>
#include<QtQml/qqmlapplicationengine.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VideoEditor w;
	w.show();
	return a.exec();
}
