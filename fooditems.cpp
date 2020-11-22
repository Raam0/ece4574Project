#include "fooditems.h"

FoodItems::FoodItems() : EER(0), duration(15), caloriesConsumed(0)
{
    foods = {
        {"Apples", 95}, {"Bananas", 105},
        {"Beans", 42}, {"Beef", 338},
        {"Bread", 79}, {"Broccoli", 50},
        {"Carrots", 30}, {"Chicken", 335},
        {"Pasta", 75}, {"Potatoes", 110},
        {"Rice", 206}, {"Seafood", 280}};
}

int FoodItems::GetFoodCalories(QString food)
{
    auto mapPos = foods.find(food);
    return mapPos->second;
}

QList<QString> FoodItems::GenerateFoods(QList<QString> preferedFoods, Profile prof)
{
    EER = prof.getEER();
    generatedFoods.clear();
    availableFoods = preferedFoods;
    PickFoods();
    return generatedFoods;
}

void FoodItems::PickFoods()
{
    caloriesConsumed = 0;

    for(int i = 0; i < availableFoods.size(); i++)
    {
        if(generatedFoods.size() < 3)
        {
            QString foodItem = availableFoods[i];
            caloriesConsumed += GetFoodCalories(foodItem);
            generatedFoods.push_front(foodItem);
        }
    }
}
