#ifndef LSSDAPPLICATION_H
#define LSSDAPPLICATION_H

#include <QMainWindow>
#include <QPixmap>
#include <QDate>

#include "workouts.h"
#include "profile.h"
#include "fooditems.h"

/* ---> UPDATE IMAGE LOCATIONS <--- */
// food images locations
const QString applesim = ":/imag/Images/apple.jpg";
const QString bananasim = ":/imag/Images/bananas.jpg";
const QString beansim = ":/imag/Images/beans.jpg";
const QString beefim = ":/imag/Images/beef.jpg";
const QString breadim = ":/imag/Images/bread.jpg";
const QString broccoliim = ":/imag/Images/broccoli.jpg";
const QString carrotsim = ":/imag/Images/carrots.jpg";
const QString chickenim = ":/imag/Images/chicken.jpg";
const QString pastaim = ":/imag/Images/pasta.jpg";
const QString potatoesim = ":/imag/Images/potatoes.jpg";
const QString riceim = ":/imag/Images/rice.jpg";
const QString seafoodim = ":/imag/Images/seafood.jpg";
// workout images locations
const QString cyclingim = ":/imag/Images/cycling.jpg";
const QString dancingim = ":/imag/Images/dancing.jpg";
const QString hikingim = ":/imag/Images/hiking.jpg";
const QString runningim = ":/imag/Images/running.jpg";
const QString sportsim = ":/imag/Images/sports.jpg";
const QString swimmingim = ":/imag/Images/swimming.jpg";
const QString walkingim = ":/imag/Images/walking.jpg";
const QString weightliftingim = ":/imag/Images/weightlifting.jpg";
const QString yogaim = ":/imag/Images/yoga.jpg";

enum {Male, Female};
enum {LoseWeight, MaintainWeight, GainWeight};

QT_BEGIN_NAMESPACE
namespace Ui { class LSSDApplication; }
QT_END_NAMESPACE

class LSSDApplication : public QMainWindow
{
    Q_OBJECT

public:
    LSSDApplication(QWidget *parent = nullptr);
    ~LSSDApplication();

private slots:
    // slots for data input
    void on_startbutton_clicked();
    void on_nextbutton_clicked();
    void on_backbutton_clicked();
    // slots for main page
    void on_caloriesinputbutton_clicked();
    void on_currentweightnum_valueChanged(int arg1);
    void on_generatefoodsbutton_clicked();
    void on_generateworkoutsbutton_clicked();

private:
    Ui::LSSDApplication *ui;
    QString name;
    QString gender;
    QDate birthdate;
    int age;
    QPair<int, int> height;
    int initialweight;
    QPixmap image;
    QList<QString> foodprefs;
    QList<QString> workoutprefs;
    QString goal;
    int goalcalories;
    int consumedcalories;
    void createfoodprefslist();
    void createworkoutprefslist();
    void recordinputs();
    void createmainpage();
    Workouts workoutsObj;
    FoodItems foodItemsObj;
    Profile profileObj;
};

#endif // LSSDAPPLICATION_H
