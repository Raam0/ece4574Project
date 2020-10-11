#include "workouts.h"

Workouts::Workouts()
{
    //The integer value is the calories burned in 1 minute
    workoutData = {
        {"Weight Lifting", 7}, {"Yoga", 5},
        {"Elliptical", 11}, {"Bicycing", 10},
        {"Running", 16}, {"Swimming", 12},
        {"Calisthenics", 6}, {"Aerobics", 7}
    };
}

int Workouts::GetWorkoutCalories(QString workout)
{
    auto mapPos = workoutData.find(workout);

    if(mapPos == workoutData.end())
    {
        return -1; // not a valid workout
    }
    else
    {
        return mapPos->second;
    }
}

int Workouts::CalcCaloriesBurned(int time, QString workout)
{
    int workoutCalories = GetWorkoutCalories(workout);
    return time*workoutCalories;
}
