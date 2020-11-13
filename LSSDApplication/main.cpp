#include "lssdapplication.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LSSDApplication w;
    w.show();
    return a.exec();
}
