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
    QList<QString> GenerateWorkouts(QList<QString> preferedWorkouts);
    int GetCaloriesBurned();

private:
    void PickWorkouts();
    std::map<QString, int>  workoutData;
    QString goal;
    int EER;
    int duration;
    int caloriesBurned;
    QList<QString> generatedWorkouts;
    QList<QString> availableWorkouts;
};

#endif // WORKOUTS_H
