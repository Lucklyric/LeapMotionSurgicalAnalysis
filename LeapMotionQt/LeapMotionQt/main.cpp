#include "leapmotionqt.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	LeapMotionQt w;
	w.show();
	return a.exec();
}
