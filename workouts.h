#ifndef WORKOUTS_H
#define WORKOUTS_H

#include <QObject>
#include <map>

#include "profile.h"

class Workouts
{
public:
    Workouts();

    int CalcCaloriesBurned(int time, QString workout);//time in minutes
    int GetWorkoutCalories(QString workout);
    QList<QString> GenerateWorkouts(QList<QString> preferedWorkouts, Profile profile);
    void LoseWeight();
    void MaintainWeight();
    void GainWeight();

private:
    std::map<QString, int>  workoutData;
};

#endif // WORKOUTS_H
