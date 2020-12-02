#ifndef LSSDAPPLICATION_H
#define LSSDAPPLICATION_H

#include <QMainWindow>
#include <QObject>
#include <QGraphicsScene>
#include <QPixmap>
#include <QDate>

#include "profile.h"
#include "fooditems.h"
#include "workouts.h"
#include "createplan.h"

const QString errorim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/errorim.jpg";

QT_BEGIN_NAMESPACE
namespace Ui { class LSSDApplication; }
namespace Ui { class CreatePlan; }
QT_END_NAMESPACE

class LSSDApplication : public QMainWindow
{
    Q_OBJECT

public:
    LSSDApplication(QWidget *parent = nullptr);
    ~LSSDApplication();

public slots:
    void updateplan(QString breakfast, QString lunch, QString dinner);

private slots:
    // slots for data input
    void on_startbutton_clicked();
    void on_nextbutton_clicked();
    void on_backbutton_clicked();
    // slots for main page
    void on_createplanbutton_clicked();
    void on_currentweightvalue_valueChanged(int arg1);

    void on_resetButton_clicked();

private:
    Ui::LSSDApplication *ui;
    QPixmap image;
    Profile profile;
    QString name;
    int initialweight;
    QList<QString> workoutprefs;
    void createworkoutprefslist();
    void recordinputs();
    void createmainpage();
    FoodItems foods;
    QGraphicsScene *breakfastscene, *lunchscene, *dinnerscene;
    Workouts workouts;
    QGraphicsScene *workout1scene, *workout2scene, *workout3scene;
};

#endif // LSSDAPPLICATION_H
