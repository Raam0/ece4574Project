#ifndef WORKOUTS_H
#define WORKOUTS_H

#include <QObject>
#include <map>

class Workouts
{
public:
    Workouts();

    int CalcCaloriesBurned(int time, QString workout);//time in minutes
    int GetWorkoutCalories(QString workout);

private:
    std::map<QString, int>  workoutData;
};

#endif // WORKOUTS_H
