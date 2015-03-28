#ifndef LEAPMOTIONQT_H
#define LEAPMOTIONQT_H

#include <QtWidgets/QMainWindow>
#include "ui_leapmotionqt.h"


class LeapMotionQt : public QMainWindow
{
	Q_OBJECT

public:
	LeapMotionQt(QWidget *parent = 0);
	~LeapMotionQt();

private:
	Ui::LeapMotionQtClass ui;
	
};

#endif // LEAPMOTIONQT_H
