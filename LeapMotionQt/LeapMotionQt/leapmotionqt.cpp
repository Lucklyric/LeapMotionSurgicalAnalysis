#include "leapmotionqt.h"
#include <QMainWindow>
#include <boost\filesystem.hpp>
Q_DECLARE_METATYPE(QCameraInfo)

LeapMotionQt::LeapMotionQt(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.mLeapWidget->mParent = this;
}



LeapMotionQt::~LeapMotionQt()
{

}

