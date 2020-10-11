#include "fooditems.h"

FoodItems::FoodItems()
{
    foods = {
        {"Apple", 72}, {"Banana", 105},
        {"Slice of bread", 66}, {"Carrots raw 1 cup", 52},
        {"Chili 1 cup", 287}, {"Oatmeal 1 cup", 147},
        {"Spaghetti 1 cup", 313}, {"Backed potato", 161},
        {"Pizza one slice", 298}, {"Rice 1 cup", 205},
        {"Hot dog", 137}, {"Pork chop 8 ounce", 505},
        {"Steak 8 ounce", 679}, {"Tuna 8 ounce", 250}};
}

int FoodItems::GetFoodCalories(QString food)
{
    auto mapPos = foods.find(food);

    if(mapPos == foods.end())
    {
        return -1; // not a valid food item
    }
    else
    {
        return mapPos->second;
    }
}
