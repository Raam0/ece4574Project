/* workouts.cpp Raam Udayappan Virginia Tech
* This holds the code for the workouts object. It contains the code load
* and save profiles as well as calculate what workouts to reccomend
* and for how long
*/
#include "workouts.h"

Workouts::Workouts()
{
    workoutimages = {
        {"Weight Lifting", weightliftingim},
        {"Yoga", yogaim},
        {"Hiking", hikingim},
        {"Bicycling", cyclingim},
        {"Running", runningim},
        {"Swimming", swimmingim},
        {"Sports", sportsim},
        {"Dancing", dancingim},
        {"Walking", walkingim}
    };

    //The integer value is the calories burned in 1 minute
    workoutcalories = {
        {"Weight Lifting", 7},
        {"Yoga", 5},
        {"Hiking", 11},
        {"Bicycling", 10},
        {"Running", 16},
        {"Swimming", 12},
        {"Sports", 6},
        {"Dancing", 7},
        {"Walking", 6}
    };

    availableWorkouts = {"Weight Lifting", "Yoga", "Hiking",
                         "Bicycling", "Running", "Swimming",
                         "Sports", "Dancing", "Walking"};
    index = 0;
    calories = 2000;
    goal = MaintainWeight;
    name = "Raam";
    weight = 150;
}

QString Workouts::getWorkoutImage(QString workout)
{
    return workoutimages.find(workout)->second;
}

void Workouts::setAvailableWorkouts(QList<QString> q1)
{
    availableWorkouts = q1;
}

void Workouts::setGoal(int g1)
{
    goal = g1;
}

void Workouts::setCalories(int c1)
{
    calories = c1;
}

//Algorithm for generating 3 recommended workouts
void Workouts::generateWorkouts(int currentCals)
{
    //clear all previous recommendations
    generatedWorkouts.clear();
    timeWorkouts.clear();

    //target calories to be burned through exercise
    int target = currentCals - calories;

    //If they are already at less calories than the target, reccomend no exercise (0 minutes for each exercise)
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
            timeWorkouts.push_back(target/workoutcalories[availableWorkouts[index]]);
            index++;
            if(index == availableWorkouts.size())
                index = 0;
        }
    }
}

QList<QString> Workouts::getRecommendations()
{
    return generatedWorkouts;
}

QList<int> Workouts::getTimeRecommendations()
{
    return timeWorkouts;
}

void Workouts::saveData()
{
    //set up strings to be put in save file
    std::string nL = "\n";
    const char* newLine = nL.c_str();

    std::string s = std::to_string(calories);
    char const *cals = s.c_str();

    std::string s1 = std::to_string(goal);
    char const *currPlan = s1.c_str();

    std::string s2 = std::to_string(index);
    char const *currIndex = s2.c_str();

    std::string s3 = name.toUtf8().constData();
    char const *currName = s3.c_str();

    std::string s4 = std::to_string(weight);
    char const *currWeight = s4.c_str();

    QFile file(QDir::current().absolutePath() + "/save.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        file.write(cals);
        file.write(newLine);

        file.write(currPlan);
        file.write(newLine);

        file.write(currIndex);
        file.write(newLine);

        file.write(currName);
        file.write(newLine);

        file.write(currWeight);
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
        qDebug() << "First time";
        availableWorkouts = { "temp"};
        calories = 0;
        goal = 0;
        index = 0;
        name = "Raam";
        weight = 150;
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
                goal = line.toInt();
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
                name = line.left(pos);
                state = 4;
            }
            else if(state == 4)
            {
                weight = line.toInt();
                state = 5;
            }
            else if(state == 5)
            {
                int pos = line.indexOf(QChar('\r'));
                availableWorkouts.push_back(line.left(pos));
            }
        }
    }
    return 0;
}

void Workouts::setName(QString s1)
{
    name = s1;
}

void Workouts::setWeight(int w1)
{
    weight = w1;
}

QString Workouts::getName()
{
    return name;
}

int Workouts::getWeight()
{
    return weight;
}

int Workouts::getCals()
{
    return calories;
}

int Workouts::getTarget()
{
    if(goal == LoseWeight)
        return calories - (calories*0.1);
    else
        return calories;
}

int Workouts::getPlan()
{
    return goal;
}
