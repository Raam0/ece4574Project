#ifndef FOODPREFSSCREEN_H
#define FOODPREFSSCREEN_H

#include <QWidget>

namespace Ui {
class FoodPrefsScreen;
}

class FoodPrefsScreen : public QWidget
{
    Q_OBJECT

public:
    explicit FoodPrefsScreen(QWidget *parent = 0);
    ~FoodPrefsScreen();

private slots:
    void recordfoodprefs();

private:
    Ui::FoodPrefsScreen *ui;
};

#endif // FOODPREFSSCREEN_H
