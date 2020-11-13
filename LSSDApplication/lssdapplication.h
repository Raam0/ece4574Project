#ifndef LSSDAPPLICATION_H
#define LSSDAPPLICATION_H

#include <QMainWindow>
#include <QPixmap>
#include <QDate>

/* ---> UPDATE IMAGE LOCATIONS <--- */
// food images locations
const QString applesim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/apple.jpg";
const QString bananasim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/bananas.jpg";
const QString beansim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/beans.jpg";
const QString beefim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/beef.jpg";
const QString breadim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/bread.jpg";
const QString broccoliim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/broccoli.jpg";
const QString carrotsim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/carrots.jpg";
const QString chickenim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/chicken.jpg";
const QString pastaim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/pasta.jpg";
const QString potatoesim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/potatoes.jpg";
const QString riceim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/rice.jpg";
const QString seafoodim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/seafood.jpg";
// workout images locations
const QString cyclingim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/cycling.jpg";
const QString dancingim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/dancing.jpg";
const QString hikingim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/hiking.jpg";
const QString runningim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/running.jpg";
const QString sportsim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/sports.jpg";
const QString swimmingim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/swimming.jpg";
const QString walkingim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/walking.jpg";
const QString weightliftingim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/weightlifting.jpg";
const QString yogaim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/yoga.jpg";

enum {Male, Female};
enum {Apples, Bananas, Beans, Beef, Bread, Broccoli,
     Carrots, Chicken, Pasta, Potatoes, Rice, Seafood};
enum {Cycling, Dancing, Hiking, Running, Sports,
     Swimming, Walking, WeightLifting, Yoga};
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
    int gender;
    QDate birthdate;
    QPair<int, int> height;
    int initialweight;
    QPixmap image;
    QList<int> foodprefs;
    QList<int> workoutprefs;
    int goal;
    int goalcalories;
    int consumedcalories;
    void createfoodprefslist();
    void createworkoutprefslist();
    void recordinputs();
    void createmainpage();
};

#endif // LSSDAPPLICATION_H
