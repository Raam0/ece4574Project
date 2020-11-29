#include "fooditems.h"

FoodItems::FoodItems()
{
    breakfasts = {
        "Omelet with hash browns", "Scrambled eggs and bacon",
        "Blueberry pancakes", "Yogurt parfait",
        "Oatmeal", "Bowl of cereal", "French toast",
        "Bagel with cream cheese", "Breakfast sandwich"
    };
    lunches = {
        "Mac and Cheese", "Ham and Cheese Sandwich",
        "Grilled Cheese Sandwich", "Ramen", "Taco",
        "Sushi", "Pizza", "Chicken Caesar Salad", "BLT"
    };
    dinners = {
        "Beef Stew", "Chicken Pot Pie", "Chicken Parmesan",
        "Enchilada", "Lasagna", "Pad Thai ", "Spaghetti",
        "Pork Chop", "Baked Chicken"
    };

    foodimages = {
        {"Omelet with hash browns", omeletim},
        {"Scrambled eggs and bacon", scrambledeggsim},
        {"Blueberry pancakes", pancakesim},
        {"Yogurt parfait", parfaitim},
        {"Oatmeal", oatmealim},
        {"Bowl of cereal", cerealim},
        {"French toast", frenchtoastim},
        {"Bagel with cream cheese", bagelim},
        {"Breakfast sandwich", bsandwichim},
        {"Mac and Cheese", macandcheeseim},
        {"Ham and Cheese Sandwich", hamandcheeseim},
        {"Grilled Cheese Sandwich", grilledcheeseim},
        {"Ramen", ramenim},
        {"Taco", tacoim},
        {"Sushi", sushiim},
        {"Pizza", pizzaim},
        {"Chicken Caesar Salad", saladim},
        {"BLT", bltim},
        {"Beef Stew", beefstewim},
        {"Chicken Pot Pie", chickenpotpieim},
        {"Chicken Parmesan", chickenparmim},
        {"Enchilada", enchiladaim},
        {"Lasagna", lasagnaim},
        {"Pad Thai ", padthaiim},
        {"Spaghetti", spaghettiim},
        {"Pork Chop", porkchopim},
        {"Baked Chicken", bakedchickenim}
    };

    foodcalories = {
        {"Omelet with hash browns", 536},
        {"Scrambled eggs and bacon", 588},
        {"2 blueberry pancakes", 352},
        {"Yogurt parfait", 376},
        {"Oatmeal", 300},
        {"Bowl of cereal", 320},
        {"French toast", 498},
        {"Bagel with cream cheese", 389},
        {"Breakfast sandwich", 392},
        {"Mac and Cheese", 699},
        {"Ham and Cheese Sandwich", 352},
        {"Grilled Cheese Sandwich", 392},
        {"Ramen", 380},
        {"Taco", 213},
        {"Sushi", 99},
        {"Pizza", 816},
        {"Chicken Caesar Salad", 392},
        {"BLT", 593},
        {"Beef Stew", 186},
        {"Chicken Pot Pie", 673},
        {"Chicken Parmesan", 250},
        {"Enchilada", 323},
        {"Lasagna", 284},
        {"Pad Thai ", 375},
        {"Spaghetti", 374},
        {"Pork Chop", 295},
        {"Baked Chicken", 282}
    };
}

QString FoodItems::getBreakfast(int index)
{
    return breakfasts.at(index);
}
QString FoodItems::getLunch(int index)
{
    return lunches.at(index);
}
QString FoodItems::getDinner(int index)
{
    return dinners.at(index);
}


QString FoodItems::getFoodImage(QString food)
{
    return foodimages.find(food)->second;
}

int FoodItems::getFoodCalories(QString food)
{
    return foodcalories.find(food)->second;
}
