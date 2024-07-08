#include <QApplication>
#include "mainwindow.h"

int main(int arc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}