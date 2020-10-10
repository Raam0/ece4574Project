#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    QVarLengthArray<int, 74> male;
    QVarLengthArray<int, 74> female;
    for(int i = 0; i < 74; i++)
    {
        if(i == 0)
            male[i] = 1000;
        else if(i == 1)
            male[i] = 1400;
        else if(i < 4)
            male[i] = 1600;
        else if(i < 6)
            male[i] = 1800;
        else if(i < 8)
            male[i] = 2000;
        else if(i < 10)
            male[i] = 2200;
        else if(i == 10)
            male[i] = 2400;
        else if(i == 11)
            male[i] = 2600;
        else if(i == 12)
            male[i] = 2800;
        else if(i == 13)
            male[i] = 3000;
        else if(i < 17)
            male[i] = 3200;
        else if(i < 33)
            male[i] = 3000;
        else if(i < 52)
            male[i] = 2800;
        else if(i < 73)
            male[i] = 2600;
        else
            male[i] = 2400;
    }

    for(int i = 0; i < 74; i++)
    {
        if(i == 0)
            female[i] = 1000;
        else if(i < 3)
            female[i] = 1400;
        else if(i < 5)
            female[i] = 1600;
        else if(i < 8)
            female[i] = 1800;
        else if(i < 10)
            female[i] = 2000;
        else if(i < 12)
            female[i] = 2200;
        else if(i < 28)
            female[i] = 2400;
        else if(i < 57)
            female[i] = 2200;
        else
            female[i] = 2000;
    }
}
