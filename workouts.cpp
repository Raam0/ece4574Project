#include "workouts.h"

Workouts::Workouts() : goal(""), EER(0), duration(15), caloriesBurned(0)
{
    //The integer value is the calories burned in 1 minute
    workoutData = {
        {"WeightLifting", 7}, {"Yoga", 5},
        {"Hiking", 11}, {"Cycling", 10},
        {"Running", 16}, {"Swimming", 12},
        {"Sports", 6}, {"Dancing", 7},
        {"Walking", 6}
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

//NOTE//
//Will try to factor in time into calculation, will ask natalie add UI features for time and
//physical activity level
QList<QString> Workouts::GenerateWorkouts(QList<QString> preferedWorkouts)
{
    generatedWorkouts.clear(); // start new list
    availableWorkouts = preferedWorkouts;
    PickWorkouts();
    return generatedWorkouts;       
}

//500 calories fewer
void Workouts::PickWorkouts()
{
    caloriesBurned = 0;

    for(int i = 0; i < availableWorkouts.size(); i++)
    {
        if(generatedWorkouts.size() < 3)
        {
            QString workout = availableWorkouts[i];
            caloriesBurned += CalcCaloriesBurned(duration, workout);
            generatedWorkouts.push_front(workout);
        }
    }
}

int Workouts::GetCaloriesBurned()
{
    return caloriesBurned;
}
