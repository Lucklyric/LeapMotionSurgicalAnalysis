#pragma once
#include <QObject>
#include <QImage>
#include "Leap.h"
#include "DataRecorder.h"
#include "QVideoEncoder.h"
class SynchronizeRecorder : public QObject
{
	Q_OBJECT
public:
	SynchronizeRecorder();
	~SynchronizeRecorder();

public:
	DataRecorder* mMotiontFileRecorder;
	QVideoEncoder* myEncoder;
	bool isRecording;

	public slots:
	void parseOneMotionFrame(Leap::Frame mFrame);
	void parseOneVideoFrame(QImage mImage);
	void stopRecording();
	void startVideoRecording(QImage mImage);
};

