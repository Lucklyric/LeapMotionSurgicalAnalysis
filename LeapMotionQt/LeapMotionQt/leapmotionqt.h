#ifndef LEAPMOTIONQT_H
#define LEAPMOTIONQT_H

#include <QtWidgets/QMainWindow>
#include "SynchronizeRecorder.h"
#include "ui_leapmotionqt.h"
#include <QCamera>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QMediaPlayer>
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QDateTime>
#include <Qdir>
#include <QThread>
#include <QVector>
#include <QImage>

class LeapMotionQt : public QMainWindow
{
	Q_OBJECT

public:
	LeapMotionQt(QWidget *parent = 0);
	~LeapMotionQt();

public:
	Ui::LeapMotionQtClass ui;
	SynchronizeRecorder* mySynchronizeRecorder;
	QThread* myRecorderThread;
	public slots:
	void exportingTheVideoSequence(QVector<QImage>* imageSequence);
};

#endif // LEAPMOTIONQT_H
