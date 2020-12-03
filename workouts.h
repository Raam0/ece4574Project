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

const QString cyclingim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/cycling.jpg";
const QString dancingim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/dancing.jpg";
const QString hikingim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/hiking.jpg";
const QString runningim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/running.jpg";
const QString sportsim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/sports.jpg";
const QString swimmingim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/swimming.jpg";
const QString walkingim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/walking.jpg";
const QString weightliftingim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/weightlifting.jpg";
const QString yogaim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/yoga.jpg";

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

