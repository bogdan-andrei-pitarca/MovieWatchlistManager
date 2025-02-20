#include "MainGUI.h"
#include <QtWidgets/QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("MOVIE DATABASE");
    Service service;
    MainGUI w(service);
    w.show();
    return a.exec();
}
