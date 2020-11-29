#include "fooditems.h"

FoodItems::FoodItems()
{
    breakfasts = {
        "Omelet with hash browns", "Scrambled eggs and bacon",
        "2 blueberry pancakes", "Yogurt parfait",
        "Oatmeal with banana", "Cereal with milk", "French toast",
        "Bagel with cream cheese", "Breakfast sandwich"
    };
    lunches = {
        "Mac and cheese", "Ham and cheese sandwich",
        "Grilled cheese sandwich", "Ramen", "3 tacos",
        "6-piece sushi roll", "2 pieces of pizza",
        "Chicken caesar salad", "BLT"
    };
    dinners = {
        "Beef stew", "Chicken pot pie", "Chicken parmesan",
        "1 enchilada", "Lasagna", "Pad thai", "Spaghetti",
        "Pork chop", "Baked chicken"
    };

    foodimages = {
        {"Omelet with hash browns", omeletim},
        {"Scrambled eggs and bacon", scrambledeggsim},
        {"2 blueberry pancakes", pancakesim},
        {"Yogurt parfait", parfaitim},
        {"Oatmeal with banana", oatmealim},
        {"Cereal with milk", cerealim},
        {"French toast", frenchtoastim},
        {"Bagel with cream cheese", bagelim},
        {"Breakfast sandwich", bsandwichim},
        {"Mac and cheese", macandcheeseim},
        {"Ham and cheese sandwich", hamandcheeseim},
        {"Grilled cheese sandwich", grilledcheeseim},
        {"Ramen", ramenim},
        {"3 tacos", tacoim},
        {"6-piece sushi roll", sushiim},
        {"2 pieces of pizza", pizzaim},
        {"Chicken caesar salad", saladim},
        {"BLT", bltim},
        {"Beef stew", beefstewim},
        {"Chicken pot pie", chickenpotpieim},
        {"Chicken parmesan", chickenparmim},
        {"1 enchilada", enchiladaim},
        {"Lasagna", lasagnaim},
        {"Pad thai", padthaiim},
        {"Spaghetti", spaghettiim},
        {"Pork chop", porkchopim},
        {"Baked chicken", bakedchickenim}
    };

    foodcalories = {
        {"Omelet with hash browns", 636},
        {"Scrambled eggs and bacon", 688},
        {"2 blueberry pancakes", 804},
        {"Yogurt parfait", 476},
        {"Oatmeal with banana", 417},
        {"Cereal with milk", 420},
        {"French toast", 598},
        {"Bagel with cream cheese", 489},
        {"Breakfast sandwich", 492},
        {"Mac and cheese", 799},
        {"Ham and cheese sandwich", 452},
        {"Grilled cheese sandwich", 492},
        {"Ramen", 480},
        {"3 tacos", 568},
        {"6-piece sushi roll", 350},
        {"2 pieces of pizza", 670},
        {"Chicken caesar salad", 570},
        {"BLT", 693},
        {"Beef stew", 714},
        {"Chicken pot pie", 773},
        {"Chicken parmesan", 667},
        {"1 enchilada", 423},
        {"Lasagna", 384},
        {"Pad thai", 475},
        {"Spaghetti", 474},
        {"Pork chop", 395},
        {"Baked chicken", 382}
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
