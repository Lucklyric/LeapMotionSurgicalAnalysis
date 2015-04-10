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
    QPushButton *recordingButton;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    CanonQtCamera *mCamera;
    QPushButton *stopCamera;
    QSlider *motionFrameBar;
    QSlider *videoFrameBar;
    QLabel *motionFrame;
    QLabel *videoFrame;
    QRadioButton *radioCheckForVideo;
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

        recordingButton = new QPushButton(centralWidget);
        recordingButton->setObjectName(QStringLiteral("recordingButton"));
        recordingButton->setGeometry(QRect(760, 380, 111, 23));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(870, 380, 31, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(900, 380, 31, 23));
        mCamera = new CanonQtCamera(centralWidget);
        mCamera->setObjectName(QStringLiteral("mCamera"));
        mCamera->setGeometry(QRect(760, 0, 441, 381));
        mCamera->setAutoFillBackground(false);
        mCamera->setStyleSheet(QStringLiteral("background-color: rgb(143, 250, 255)"));
        stopCamera = new QPushButton(centralWidget);
        stopCamera->setObjectName(QStringLiteral("stopCamera"));
        stopCamera->setGeometry(QRect(1120, 380, 81, 23));
        motionFrameBar = new QSlider(centralWidget);
        motionFrameBar->setObjectName(QStringLiteral("motionFrameBar"));
        motionFrameBar->setGeometry(QRect(800, 450, 351, 22));
        motionFrameBar->setOrientation(Qt::Horizontal);
        videoFrameBar = new QSlider(centralWidget);
        videoFrameBar->setObjectName(QStringLiteral("videoFrameBar"));
        videoFrameBar->setGeometry(QRect(800, 500, 351, 22));
        videoFrameBar->setOrientation(Qt::Horizontal);
        motionFrame = new QLabel(centralWidget);
        motionFrame->setObjectName(QStringLiteral("motionFrame"));
        motionFrame->setGeometry(QRect(770, 430, 211, 16));
        videoFrame = new QLabel(centralWidget);
        videoFrame->setObjectName(QStringLiteral("videoFrame"));
        videoFrame->setGeometry(QRect(770, 480, 211, 16));
        radioCheckForVideo = new QRadioButton(centralWidget);
        radioCheckForVideo->setObjectName(QStringLiteral("radioCheckForVideo"));
        radioCheckForVideo->setEnabled(true);
        radioCheckForVideo->setGeometry(QRect(770, 410, 82, 17));
        radioCheckForVideo->setChecked(false);
        radioCheckForVideo->setAutoRepeat(false);
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
        pushButton->setText(QApplication::translate("LeapMotionQtClass", "<", 0));
        pushButton_2->setText(QApplication::translate("LeapMotionQtClass", ">", 0));
        stopCamera->setText(QApplication::translate("LeapMotionQtClass", "StopCamera", 0));
        motionFrame->setText(QApplication::translate("LeapMotionQtClass", "MtionFrame:", 0));
        videoFrame->setText(QApplication::translate("LeapMotionQtClass", "MtionFrame:", 0));
        radioCheckForVideo->setText(QApplication::translate("LeapMotionQtClass", "ExportVideo", 0));
        menuFile->setTitle(QApplication::translate("LeapMotionQtClass", "File", 0));
        menuEtra->setTitle(QApplication::translate("LeapMotionQtClass", "Etra", 0));
    } // retranslateUi

};

namespace Ui {
    class LeapMotionQtClass: public Ui_LeapMotionQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEAPMOTIONQT_H
