#ifndef CREATEPLAN_H
#define CREATEPLAN_H

#include <QWidget>
#include <QObject>
#include <QPixmap>
#include <stdlib.h>

#include "lssdapplication.h"
#include "fooditems.h"

namespace Ui {
class CreatePlan;
}

class CreatePlan : public QWidget
{
    Q_OBJECT

public:
    explicit CreatePlan(QWidget *parent = nullptr);
    ~CreatePlan();

private slots:
    void on_breakfast1button_clicked();
    void on_breakfast2button_clicked();
    void on_breakfast3button_clicked();
    void on_lunch1button_clicked();
    void on_lunch2button_clicked();
    void on_lunch3button_clicked();
    void on_dinner1button_clicked();
    void on_dinner2button_clicked();
    void on_dinner3button_clicked();

    void on_breakfastshuffle_clicked();
    void on_lunchshuffle_clicked();
    void on_dinnershuffle_clicked();
    void on_finishbutton_clicked();

signals:
    void mealplanchanged(QString breakfast, QString lunch, QString dinner);

private:
    Ui::CreatePlan *ui;
    FoodItems foods;
    QPixmap image;
    QString breakfast1, breakfast2, breakfast3;
    QString lunch1, lunch2, lunch3;
    QString dinner1, dinner2, dinner3;
    QString breakfastmeal, lunchmeal, dinnermeal;
};

#endif // CREATEPLAN_H
