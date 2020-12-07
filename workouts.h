/* workouts.cpp Raam Udayappan Virginia Tech
* This holds the code for the workouts object. It contains the code load
* and save profiles as well as calculate what workouts to reccomend
* and for how long
*/

#ifndef WORKOUTS_H
#define WORKOUTS_H

#include <QObject>
#include <map>
#include <iostream>
#include <ctime>
#include <QFile>
#include <QDir>
#include <string>
#include <QDebug>
#include "profile.h"

const QString cyclingim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/cycling.jpg";
const QString dancingim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/dancing.jpg";
const QString hikingim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/hiking.jpg";
const QString runningim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/running.jpg";
const QString sportsim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/sports.jpg";
const QString swimmingim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/swimming.jpg";
const QString walkingim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/walking.jpg";
const QString weightliftingim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/weightlifting.jpg";
const QString yogaim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/yoga.jpg";

enum {LoseWeight, MaintainWeight};

class Workouts
{
public:
    Workouts();
    QString getWorkoutImage(QString workout);
    void setAvailableWorkouts(QList<QString> q1);
    void setGoal(int g1);
    void setCalories(int c1);
    void generateWorkouts(int CurrentCals);
    QList<QString> getRecommendations();
    QList<int> getTimeRecommendations();

    void setName(QString s1);
    void setWeight(int w1);

    QString getName();
    int getWeight();

    void saveData();
    int loadData();

    int getCals();
    int getTarget();
    int getPlan();

private:
    std::map<QString, QString> workoutimages;
    std::map<QString, int>  workoutcalories;
    //Available workouts is the list of their preferred workouts
    QList<QString> availableWorkouts;
    //generatedWorkouts is 3 Workouts to Reccomend
    QList<QString> generatedWorkouts;
    //Timeworkouts is time to spend on each workout
    QList<int> timeWorkouts;
    //calories is their needed cals per day, plan is lose or maintain weight, and index is where to start reccs
    QString name;
    int weight;
    int index;
    int goal;
    int calories;
};

#endif // WORKOUTS_H

