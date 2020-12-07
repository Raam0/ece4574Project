#ifndef FOODITEMS_H
#define FOODITEMS_H

#include <QObject>
#include <QList>
#include <map>

#include "profile.h"

const QString omeletim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/omelet.jpg";
const QString scrambledeggsim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/scrambledeggs.jpg";
const QString pancakesim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/pancakes.jpg";
const QString parfaitim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/parfait.jpg";
const QString oatmealim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/oatmeal.jpg";
const QString cerealim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/cereal.jpg";
const QString frenchtoastim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/frenchtoast.jpg";
const QString bagelim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/bagel.jpg";
const QString bsandwichim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/bsandwich.jpg";
const QString macandcheeseim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/macandcheese.jpg";
const QString hamandcheeseim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/hamandcheese.jpg";
const QString grilledcheeseim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/grilledcheese.jpg";
const QString ramenim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/ramen.jpg";
const QString tacoim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/taco.jpg";
const QString sushiim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/sushi.jpg";
const QString pizzaim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/pizza.jpg";
const QString saladim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/salad.jpg";
const QString bltim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/blt.jpg";
const QString beefstewim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/beefstew.jpg";
const QString chickenpotpieim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/potpie.jpg";
const QString chickenparmim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/chickenparm.jpg";
const QString enchiladaim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/enchilada.jpg";
const QString lasagnaim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/lasagna.jpg";
const QString padthaiim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/padthai.jpg";
const QString spaghettiim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/spaghetti.jpg";
const QString porkchopim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/porkchop.jpg";
const QString bakedchickenim = "C:/Users/Raam Udayappan/Desktop/ece4574Project-master/Images/bakedchicken.jpg";

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
