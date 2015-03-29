#include "leapmotionqt.h"


LeapMotionQt::LeapMotionQt(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.mLeapWidget->mParent = this;
}

LeapMotionQt::~LeapMotionQt()
{

}

