/********************************************************************************
** Form generated from reading UI file 'MainGUI.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINGUI_H
#define UI_MAINGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainGUIClass)
    {
        if (MainGUIClass->objectName().isEmpty())
            MainGUIClass->setObjectName("MainGUIClass");
        MainGUIClass->resize(600, 400);
        menuBar = new QMenuBar(MainGUIClass);
        menuBar->setObjectName("menuBar");
        MainGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainGUIClass);
        mainToolBar->setObjectName("mainToolBar");
        MainGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MainGUIClass);
        centralWidget->setObjectName("centralWidget");
        MainGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainGUIClass);
        statusBar->setObjectName("statusBar");
        MainGUIClass->setStatusBar(statusBar);

        retranslateUi(MainGUIClass);

        QMetaObject::connectSlotsByName(MainGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainGUIClass)
    {
        MainGUIClass->setWindowTitle(QCoreApplication::translate("MainGUIClass", "MainGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainGUIClass: public Ui_MainGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGUI_H
