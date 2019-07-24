#include "imageprocess.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	imageprocess w;
	
	//w.setFixedSize(799,440);
	w.show();
	return a.exec();
}
