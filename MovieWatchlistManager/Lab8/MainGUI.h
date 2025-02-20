#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainGUI.h"
#include "Service.h"
#include "GUI.h"
#include "FileRepo.h"
#include "Exception.h"
#include "qstackedlayout.h"
#include "qtoolbar.h"
#include <QVBoxLayout>
#include <QPushButton>
class MainGUI : public QMainWindow
{
    Q_OBJECT

public:
    MainGUI(Service& service, QWidget *parent = nullptr);
    ~MainGUI();

private:
    Service& service;
    Ui::MainGUIClass* ui;
};
