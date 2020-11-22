#ifndef FOODITEMS_H
#define FOODITEMS_H

#include <QObject>
#include <map>

#include "profile.h"

class FoodItems
{
public:
    FoodItems();
    int GetFoodCalories(QString food);
    QList<QString> GenerateFoods(QList<QString> preferedFoods, Profile prof);

private:
    void PickFoods();
    std::map<QString, int> foods;
    QList<QString> generatedFoods;
    QList<QString> availableFoods;
    int EER;
    int duration;
    int caloriesConsumed;

};

#endif // FOODITEMS_H
