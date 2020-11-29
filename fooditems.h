#ifndef FOODITEMS_H
#define FOODITEMS_H

#include <QObject>
#include <QList>
#include <map>

#include "profile.h"

const QString omeletim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/omelet.jpg";
const QString scrambledeggsim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/scrambledeggs.jpg";
const QString pancakesim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/pancakes.jpg";
const QString parfaitim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/parfait.jpg";
const QString oatmealim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/oatmeal.jpg";
const QString cerealim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/cereal.jpg";
const QString frenchtoastim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/frenchtoast.jpg";
const QString bagelim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/bagel.jpg";
const QString bsandwichim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/bsandwich.jpg";
const QString macandcheeseim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/macandcheese.jpg";
const QString hamandcheeseim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/hamandcheese.jpg";
const QString grilledcheeseim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/grilledcheese.jpg";
const QString ramenim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/ramen.jpg";
const QString tacoim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/taco.jpg";
const QString sushiim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/sushi.jpg";
const QString pizzaim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/pizza.jpg";
const QString saladim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/salad.jpg";
const QString bltim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/blt.jpg";
const QString beefstewim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/beefstew.jpg";
const QString chickenpotpieim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/potpie.jpg";
const QString chickenparmim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/chickenparm.jpg";
const QString enchiladaim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/enchilada.jpg";
const QString lasagnaim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/lasagna.jpg";
const QString padthaiim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/padthai.jpg";
const QString spaghettiim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/spaghetti.jpg";
const QString porkchopim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/porkchop.jpg";
const QString bakedchickenim = "C:/Users/Natalie Fleming/OneDrive/Documents/LSSD/Project/bakedchicken.jpg";

class FoodItems
{
public:
    FoodItems();
    QString getBreakfast(int index);
    QString getLunch(int index);
    QString getDinner(int index);
    QString getFoodImage(QString food);
    int getFoodCalories(QString food);

private:
    QList<QString> breakfasts;
    QList<QString> lunches;
    QList<QString> dinners;
    std::map<QString, QString> foodimages;
    std::map<QString, int> foodcalories;
};

#endif // FOODITEMS_H
