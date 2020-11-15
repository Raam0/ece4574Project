#include "workouts.h"

Workouts::Workouts()
{
    //The integer value is the calories burned in 1 minute
    workoutData = {
        {"WeightLifting", 7}, {"Yoga", 5},
        {"Hiking", 11}, {"Bicycing", 10},
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
QList<QString> Workouts::GenerateWorkouts(QList<QString> preferedWorkouts, Profile profile)
{
    goal = profile.getGoal();
    generatedWorkouts.clear(); // start new list
    availableWorkouts = preferedWorkouts;

    if(goal == "LoseWeight")
    {
        LoseWeight();
    }
    if(goal == "MaintainWeight")
    {
        MaintainWeight();
    }
    else
    {
        GainWeight();
    }
    return generatedWorkouts;
        
}
//500 calories fewer
void Workouts::LoseWeight()
{

}
//maintain EER
void Workouts::MaintainWeight()
{

}
//500 calores more
void Workouts::GainWeight()
{

}
