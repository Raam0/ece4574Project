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

class Workouts
{
public:
    Workouts();
    void GenerateWorkouts(int CurrentCals);
    void saveData();
    int loadData();
    QList<QString> getReccomendations();
    QList<int> getTimeReccomendations();
    void setAvailableWorkouts(QList<QString> q1);
    void setCalories(int c1);
    void setPlan(int p1);
    void setIndex(int i1);

private:
    std::map<QString, int>  workoutData;
    QString goal;
    //generatedWorkouts is 3 Workouts to Reccomend
    QList<QString> generatedWorkouts;

    //Timeworkouts is time to spend on each workout
    QList<int> timeWorkouts;

    //Available workouts is the list of their preferred workouts
    QList<QString> availableWorkouts;

    //calories is their needed cals per day, plan is lose or maintain weight, and index is where to start reccs
    int calories;
    int plan;
    int index;
};

#endif // WORKOUTS_H
