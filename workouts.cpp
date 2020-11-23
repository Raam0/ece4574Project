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

//Algorithm for generating 3 reccomended workouts
void Workouts::GenerateWorkouts(int CurrentCals)
{
    //clear all previous reccomendations
    generatedWorkouts.clear();
    timeWorkouts.clear();

    //target calories to be burned through exercise
    int target = CurrentCals - calories;

    //If plan = 0, they chose to lose weight, target is 500 below the Goal
    if(plan == 0)
    {
        target -= 500;
    }

    //If they are already at less Calories than the target, reccomend no exercise (0 minutes for each exercise)
    if(target <= 0)
    {
        for(int i = 0; i < 3; i++)
        {
            generatedWorkouts.push_back(availableWorkouts[index]);
            timeWorkouts.push_back(0);
            index++;
            if(index == availableWorkouts.size())
                index = 0;
        }
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            generatedWorkouts.push_back(availableWorkouts[index]);
            timeWorkouts.push_back(target/workoutData[availableWorkouts[index]]);
            index++;
            if(index == availableWorkouts.size())
                index = 0;
        }
    }
}

void Workouts::saveData()
{
    //set up strings to be put in save file
    std::string nL = "\n";
    const char* newLine = nL.c_str();

    std::string s = std::to_string(calories);
    char const *cals = s.c_str();

    std::string s1 = std::to_string(plan);
    char const *currPlan = s1.c_str();

    std::string s2 = std::to_string(index);
    char const *currIndex = s2.c_str();

    QFile file(QDir::current().absolutePath() + "/save.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        file.write(cals);
        file.write(newLine);

        file.write(currPlan);
        file.write(newLine);

        file.write(currIndex);
        file.write(newLine);

        for (int i = 0; i < availableWorkouts.size(); ++i) {
            file.write(availableWorkouts.at(i).toStdString().c_str());
            file.write(newLine);
        }
    }
    else
        qDebug() << "Failed to save data";
}

int Workouts::loadData()
{
    int state = 0;
    QFile file(QDir::current().absolutePath() + "/save.txt");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open";
        availableWorkouts = { "temp"};
        calories = 0;
        plan = 0;
        index = 0;
        saveData();
        return 1;
    }
    else
    {
        while (!file.atEnd()) {
            QString line = file.readLine();
            if(state == 0)
            {
                calories = line.toInt();
                state = 1;
            }
            else if(state == 1)
            {
                plan = line.toInt();
                state = 2;
            }
            else if(state == 2)
            {
                index = line.toInt();
                state = 3;
            }
            else if(state == 3)
            {
                int pos = line.indexOf(QChar('\r'));
                availableWorkouts.push_back(line.left(pos));
            }
        }
    }
    return 0;
}

QList<QString> Workouts::getReccomendations()
{
    return generatedWorkouts;
}

QList<int> Workouts::getTimeReccomendations()
{
    return timeWorkouts;
}

void Workouts::setAvailableWorkouts(QList<QString> q1)
{
    availableWorkouts = q1;
}

void Workouts::setCalories(int c1)
{
    calories = c1;
}

void Workouts::setPlan(int p1)
{
    plan = p1;
}

void Workouts::setIndex(int i1)
{
    index = i1;
}


