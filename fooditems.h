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

private:
    std::map<QString, int> foods;
};

#endif // FOODITEMS_H
