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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "CanonQtCamera.h"
#include "LeapQtGl.h"

QT_BEGIN_NAMESPACE

class Ui_LeapMotionQtClass
{
public:
    QAction *actionImport;
    QWidget *centralWidget;
    LeapQtGl *mLeapWidget;
    QGroupBox *mGeneralInfo;
    QGridLayout *gridLayout;
    QLabel *ldFps;
    QLabel *dFps;
    QPushButton *recordingButton;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    CanonQtCamera *widget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LeapMotionQtClass)
    {
        if (LeapMotionQtClass->objectName().isEmpty())
            LeapMotionQtClass->setObjectName(QStringLiteral("LeapMotionQtClass"));
        LeapMotionQtClass->resize(1202, 665);
        LeapMotionQtClass->setStyleSheet(QStringLiteral(""));
        actionImport = new QAction(LeapMotionQtClass);
        actionImport->setObjectName(QStringLiteral("actionImport"));
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
        recordingButton->setGeometry(QRect(0, 590, 111, 23));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 590, 31, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 590, 31, 23));
        widget = new CanonQtCamera(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(760, 0, 441, 581));
        LeapMotionQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LeapMotionQtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1202, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        LeapMotionQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LeapMotionQtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LeapMotionQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LeapMotionQtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LeapMotionQtClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionImport);

        retranslateUi(LeapMotionQtClass);
        QObject::connect(recordingButton, SIGNAL(clicked()), mLeapWidget, SLOT(startRecording()));
        QObject::connect(actionImport, SIGNAL(triggered()), mLeapWidget, SLOT(importFile()));
        QObject::connect(pushButton, SIGNAL(clicked()), mLeapWidget, SLOT(lastFrame()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), mLeapWidget, SLOT(nextFrame()));

        QMetaObject::connectSlotsByName(LeapMotionQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *LeapMotionQtClass)
    {
        LeapMotionQtClass->setWindowTitle(QApplication::translate("LeapMotionQtClass", "LeapMotionQt", 0));
        actionImport->setText(QApplication::translate("LeapMotionQtClass", "Import", 0));
        mGeneralInfo->setTitle(QString());
        ldFps->setText(QApplication::translate("LeapMotionQtClass", "<html><head/><body><p><span style=\" color:#ffffff;\">deviceFps:</span></p></body></html>", 0));
        dFps->setText(QApplication::translate("LeapMotionQtClass", "0", 0));
        recordingButton->setText(QApplication::translate("LeapMotionQtClass", "Start Recording", 0));
        pushButton->setText(QApplication::translate("LeapMotionQtClass", "<", 0));
        pushButton_2->setText(QApplication::translate("LeapMotionQtClass", ">", 0));
        menuFile->setTitle(QApplication::translate("LeapMotionQtClass", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class LeapMotionQtClass: public Ui_LeapMotionQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEAPMOTIONQT_H
