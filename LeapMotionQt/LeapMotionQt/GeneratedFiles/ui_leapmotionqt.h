/********************************************************************************
** Form generated from reading UI file 'leapmotionqt.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEAPMOTIONQT_H
#define UI_LEAPMOTIONQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "CanonQtCamera.h"
#include "LeapQtGl.h"

QT_BEGIN_NAMESPACE

class Ui_LeapMotionQtClass
{
public:
    QAction *actionImport;
    QAction *actionImport_Video;
    QAction *actionOutputDataFile;
    QWidget *centralWidget;
    LeapQtGl *mLeapWidget;
    QGroupBox *mGeneralInfo;
    QGridLayout *gridLayout;
    QLabel *ldFps;
    QLabel *dFps;
    CanonQtCamera *mCamera;
    QTabWidget *tabWidget;
    QWidget *recording;
    QPushButton *recordingButton;
    QPushButton *stopCamera;
    QRadioButton *radioCheckForVideo;
    QWidget *replaying;
    QPushButton *pushButton_3;
    QLabel *videoFrame;
    QLabel *motionFrame;
    QSlider *videoFrameBar;
    QSlider *motionFrameBar;
    QRadioButton *radioButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEtra;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *LeapMotionQtClass)
    {
        if (LeapMotionQtClass->objectName().isEmpty())
            LeapMotionQtClass->setObjectName(QStringLiteral("LeapMotionQtClass"));
        LeapMotionQtClass->resize(1202, 625);
        LeapMotionQtClass->setStyleSheet(QStringLiteral(""));
        actionImport = new QAction(LeapMotionQtClass);
        actionImport->setObjectName(QStringLiteral("actionImport"));
        actionImport_Video = new QAction(LeapMotionQtClass);
        actionImport_Video->setObjectName(QStringLiteral("actionImport_Video"));
        actionOutputDataFile = new QAction(LeapMotionQtClass);
        actionOutputDataFile->setObjectName(QStringLiteral("actionOutputDataFile"));
        centralWidget = new QWidget(LeapMotionQtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mLeapWidget = new LeapQtGl(centralWidget);
        mLeapWidget->setObjectName(QStringLiteral("mLeapWidget"));
        mLeapWidget->setGeometry(QRect(0, -1, 761, 591));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mLeapWidget->sizePolicy().hasHeightForWidth());
        mLeapWidget->setSizePolicy(sizePolicy);
        mLeapWidget->setStyleSheet(QStringLiteral("background:rgb(0, 0, 0)"));
        mGeneralInfo = new QGroupBox(mLeapWidget);
        mGeneralInfo->setObjectName(QStringLiteral("mGeneralInfo"));
        mGeneralInfo->setGeometry(QRect(10, 20, 121, 51));
        mGeneralInfo->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(mGeneralInfo);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ldFps = new QLabel(mGeneralInfo);
        ldFps->setObjectName(QStringLiteral("ldFps"));

        gridLayout->addWidget(ldFps, 0, 0, 1, 1);

        dFps = new QLabel(mGeneralInfo);
        dFps->setObjectName(QStringLiteral("dFps"));
        dFps->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));

        gridLayout->addWidget(dFps, 0, 1, 1, 1);

        mCamera = new CanonQtCamera(centralWidget);
        mCamera->setObjectName(QStringLiteral("mCamera"));
        mCamera->setGeometry(QRect(760, 0, 441, 381));
        mCamera->setAutoFillBackground(false);
        mCamera->setStyleSheet(QStringLiteral("background-color: rgb(143, 250, 255)"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(760, 380, 441, 211));
        tabWidget->setStyleSheet(QStringLiteral(""));
        recording = new QWidget();
        recording->setObjectName(QStringLiteral("recording"));
        recordingButton = new QPushButton(recording);
        recordingButton->setObjectName(QStringLiteral("recordingButton"));
        recordingButton->setGeometry(QRect(10, 50, 111, 71));
        stopCamera = new QPushButton(recording);
        stopCamera->setObjectName(QStringLiteral("stopCamera"));
        stopCamera->setGeometry(QRect(300, 50, 111, 71));
        radioCheckForVideo = new QRadioButton(recording);
        radioCheckForVideo->setObjectName(QStringLiteral("radioCheckForVideo"));
        radioCheckForVideo->setEnabled(true);
        radioCheckForVideo->setGeometry(QRect(10, 10, 82, 17));
        radioCheckForVideo->setChecked(false);
        radioCheckForVideo->setAutoRepeat(false);
        tabWidget->addTab(recording, QString());
        replaying = new QWidget();
        replaying->setObjectName(QStringLiteral("replaying"));
        pushButton_3 = new QPushButton(replaying);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 130, 75, 51));
        videoFrame = new QLabel(replaying);
        videoFrame->setObjectName(QStringLiteral("videoFrame"));
        videoFrame->setGeometry(QRect(10, 80, 211, 16));
        motionFrame = new QLabel(replaying);
        motionFrame->setObjectName(QStringLiteral("motionFrame"));
        motionFrame->setGeometry(QRect(10, 30, 211, 16));
        videoFrameBar = new QSlider(replaying);
        videoFrameBar->setObjectName(QStringLiteral("videoFrameBar"));
        videoFrameBar->setGeometry(QRect(40, 100, 351, 22));
        videoFrameBar->setOrientation(Qt::Horizontal);
        motionFrameBar = new QSlider(replaying);
        motionFrameBar->setObjectName(QStringLiteral("motionFrameBar"));
        motionFrameBar->setGeometry(QRect(40, 50, 351, 22));
        motionFrameBar->setOrientation(Qt::Horizontal);
        radioButton = new QRadioButton(replaying);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(0, 10, 101, 17));
        pushButton_2 = new QPushButton(replaying);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 130, 51, 51));
        pushButton = new QPushButton(replaying);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 130, 51, 51));
        tabWidget->addTab(replaying, QString());
        LeapMotionQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LeapMotionQtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1202, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEtra = new QMenu(menuBar);
        menuEtra->setObjectName(QStringLiteral("menuEtra"));
        LeapMotionQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LeapMotionQtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LeapMotionQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEtra->menuAction());
        menuFile->addAction(actionImport);
        menuFile->addAction(actionImport_Video);
        menuEtra->addAction(actionOutputDataFile);

        retranslateUi(LeapMotionQtClass);
        QObject::connect(recordingButton, SIGNAL(clicked()), mLeapWidget, SLOT(startRecording()));
        QObject::connect(actionImport, SIGNAL(triggered()), mLeapWidget, SLOT(importFile()));
        QObject::connect(pushButton, SIGNAL(clicked()), mLeapWidget, SLOT(lastFrame()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), mLeapWidget, SLOT(nextFrame()));
        QObject::connect(recordingButton, SIGNAL(clicked()), mCamera, SLOT(toggleRecording()));
        QObject::connect(stopCamera, SIGNAL(clicked()), mCamera, SLOT(killWokerTimer()));
        QObject::connect(motionFrameBar, SIGNAL(sliderMoved(int)), mLeapWidget, SLOT(changeToFrame(int)));
        QObject::connect(mLeapWidget, SIGNAL(loadedFrame(int,int)), motionFrameBar, SLOT(setRange(int,int)));
        QObject::connect(mLeapWidget, SIGNAL(buttonChangedFrame(int)), motionFrameBar, SLOT(setValue(int)));
        QObject::connect(mLeapWidget, SIGNAL(setFrameLabelTex(QString)), motionFrame, SLOT(setText(QString)));
        QObject::connect(actionImport_Video, SIGNAL(triggered()), mCamera, SLOT(importVideo()));
        QObject::connect(mCamera, SIGNAL(loadedFrame(int,int)), videoFrameBar, SLOT(setRange(int,int)));
        QObject::connect(videoFrameBar, SIGNAL(sliderMoved(int)), mCamera, SLOT(changeReaplyingIndex(int)));
        QObject::connect(mCamera, SIGNAL(setFrameLabelTex(QString)), videoFrame, SLOT(setText(QString)));
        QObject::connect(actionOutputDataFile, SIGNAL(triggered()), mLeapWidget, SLOT(reOutPutDataFile()));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), mLeapWidget, SLOT(synchroMode(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), mCamera, SLOT(synchroMode(bool)));
        QObject::connect(mLeapWidget, SIGNAL(changeCameraIndex(int)), videoFrameBar, SLOT(setValue(int)));
        QObject::connect(videoFrameBar, SIGNAL(valueChanged(int)), mCamera, SLOT(changeReaplyingIndex(int)));
        QObject::connect(motionFrameBar, SIGNAL(valueChanged(int)), mLeapWidget, SLOT(changeToFrame(int)));
        QObject::connect(pushButton_3, SIGNAL(clicked()), mLeapWidget, SLOT(autoPlayMode()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LeapMotionQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *LeapMotionQtClass)
    {
        LeapMotionQtClass->setWindowTitle(QApplication::translate("LeapMotionQtClass", "LeapMotionQt", 0));
        actionImport->setText(QApplication::translate("LeapMotionQtClass", "Import Motion", 0));
        actionImport_Video->setText(QApplication::translate("LeapMotionQtClass", "Import Video", 0));
        actionOutputDataFile->setText(QApplication::translate("LeapMotionQtClass", "OutputDataFile", 0));
        mGeneralInfo->setTitle(QString());
        ldFps->setText(QApplication::translate("LeapMotionQtClass", "<html><head/><body><p><span style=\" color:#ffffff;\">deviceFps:</span></p></body></html>", 0));
        dFps->setText(QApplication::translate("LeapMotionQtClass", "0", 0));
        recordingButton->setText(QApplication::translate("LeapMotionQtClass", "Start Recording", 0));
        stopCamera->setText(QApplication::translate("LeapMotionQtClass", "StopCamera", 0));
        radioCheckForVideo->setText(QApplication::translate("LeapMotionQtClass", "ExportVideo", 0));
        tabWidget->setTabText(tabWidget->indexOf(recording), QApplication::translate("LeapMotionQtClass", "Recorder", 0));
        pushButton_3->setText(QApplication::translate("LeapMotionQtClass", "Play", 0));
        videoFrame->setText(QApplication::translate("LeapMotionQtClass", "MtionFrame:", 0));
        motionFrame->setText(QApplication::translate("LeapMotionQtClass", "MtionFrame:", 0));
        radioButton->setText(QApplication::translate("LeapMotionQtClass", "Synchronization", 0));
        pushButton_2->setText(QApplication::translate("LeapMotionQtClass", ">", 0));
        pushButton->setText(QApplication::translate("LeapMotionQtClass", "<", 0));
        tabWidget->setTabText(tabWidget->indexOf(replaying), QApplication::translate("LeapMotionQtClass", "Replayer", 0));
        menuFile->setTitle(QApplication::translate("LeapMotionQtClass", "File", 0));
        menuEtra->setTitle(QApplication::translate("LeapMotionQtClass", "Etra", 0));
    } // retranslateUi

};

namespace Ui {
    class LeapMotionQtClass: public Ui_LeapMotionQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEAPMOTIONQT_H
