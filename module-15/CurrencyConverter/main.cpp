#include "ccwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CCWindow w;
    w.show();
    return a.exec();
}
