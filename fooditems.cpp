#include "fooditems.h"

FoodItems::FoodItems()
{
    foods = {
        {"Omelet with hash browns", 536}, {"Scrambled eggs and bacon", 588},
        {"Blueberry pancakes", 352}, {"Yogurt with fruit and granola", 376},
        {"Oatmeal", 300}, {"Bowl of cereal", 320},
        {"French toast", 498}, {"Bagel with cream cheese", 389},
        {"Breakfast sandwich", 392}, {"Mac and Cheese", 699},
        {"Ham and Cheese Sandwich", 352}, {"Grilled Cheese Sandwich", 392},
        {"Ramen", 380}, {"Taco", 213},
        {"Sushi", 99}, {"Pizza", 816},
        {"Chicken Caesar Salad", 392}, {"BLT", 593},
        {"Beef Stew", 186}, {"Chicken Pot Pie", 673},
        {"Chicken Parmesan", 250}, {"Enchiladas", 323},
        {"Lasagne", 284}, {"Pad Thai ", 375},
        {"Spaghetti", 374}, {"Pork Chop", 295}, {"Baked Chicken", 282}};
}

int FoodItems::GetFoodCalories(QString food)
{
    auto mapPos = foods.find(food);
    return mapPos->second;
}


