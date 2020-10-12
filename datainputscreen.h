#ifndef DATAINPUTSCREEN_H
#define DATAINPUTSCREEN_H

#include <QWidget>

namespace Ui {
class DataInputScreen;
}

class DataInputScreen : public QWidget
{
    Q_OBJECT

public:
    explicit DataInputScreen(QWidget *parent = 0);
    ~DataInputScreen();

private slots:
    void recordinputdata();

private:
    Ui::DataInputScreen *ui;
};

#endif // DATAINPUTSCREEN_H
