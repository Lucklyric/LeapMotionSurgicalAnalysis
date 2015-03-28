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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "LeapQtGl.h"

QT_BEGIN_NAMESPACE

class Ui_LeapMotionQtClass
{
public:
    QAction *actionImport;
    QWidget *centralWidget;
    LeapQtGl *mLeapWidget;
    QPushButton *recordingButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LeapMotionQtClass)
    {
        if (LeapMotionQtClass->objectName().isEmpty())
            LeapMotionQtClass->setObjectName(QStringLiteral("LeapMotionQtClass"));
        LeapMotionQtClass->resize(1171, 815);
        actionImport = new QAction(LeapMotionQtClass);
        actionImport->setObjectName(QStringLiteral("actionImport"));
        centralWidget = new QWidget(LeapMotionQtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mLeapWidget = new LeapQtGl(centralWidget);
        mLeapWidget->setObjectName(QStringLiteral("mLeapWidget"));
        mLeapWidget->setGeometry(QRect(0, -1, 1161, 721));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mLeapWidget->sizePolicy().hasHeightForWidth());
        mLeapWidget->setSizePolicy(sizePolicy);
        recordingButton = new QPushButton(centralWidget);
        recordingButton->setObjectName(QStringLiteral("recordingButton"));
        recordingButton->setGeometry(QRect(0, 730, 111, 23));
        LeapMotionQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LeapMotionQtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1171, 21));
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

        QMetaObject::connectSlotsByName(LeapMotionQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *LeapMotionQtClass)
    {
        LeapMotionQtClass->setWindowTitle(QApplication::translate("LeapMotionQtClass", "LeapMotionQt", 0));
        actionImport->setText(QApplication::translate("LeapMotionQtClass", "Import", 0));
        recordingButton->setText(QApplication::translate("LeapMotionQtClass", "Start Recording", 0));
        menuFile->setTitle(QApplication::translate("LeapMotionQtClass", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class LeapMotionQtClass: public Ui_LeapMotionQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEAPMOTIONQT_H
