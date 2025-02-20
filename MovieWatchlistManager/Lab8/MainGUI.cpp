#include "MainGUI.h"
#include <iostream>
MainGUI::MainGUI(Service& service, QWidget *parent)
    : service{ service }, QMainWindow{ parent }, ui{ new Ui::MainGUIClass }
{
    ui->setupUi(this);
    this->service = Service();
    try {
        this->service.setRepositoryType(new FileRepo{ "movies.txt" });
    }
    catch (FileException& e) {
        std::cout << e.what() << endl;
    }
    QToolBar* toolbar = new QToolBar(this);
    this->addToolBar(toolbar);
    QAction* admin = new QAction("ADMIN MODE", this);
    QAction* user = new QAction("USER MODE", this);
    toolbar->addAction(admin);
    toolbar->addAction(user);
    this->setWindowTitle("LOCAL MOVIE DATABASE");
    QWidget* adminWidget = new AdminGUI(this->service);
    QWidget* userWidget = new UserGUI(this->service);
    QLabel* welcome = new QLabel("\t\t\t\tHELLO! PLEASE SELECT CREDENTIALS");
    QStackedLayout* layout = new QStackedLayout();
    layout->addWidget(welcome);
    layout->addWidget(adminWidget);
    layout->addWidget(userWidget);
    this->centralWidget()->setLayout(layout);
    this->resize(400, 400);
    this->connect(admin, &QAction::triggered, this, [=]() {
        this->resize(900, 400);
        layout->setCurrentIndex(1);
        });
    this->connect(user, &QAction::triggered, this, [=]() {
        this->resize(900, 400);
        layout->setCurrentIndex(2);
        });

}

MainGUI::~MainGUI()
{
    delete ui;
}
