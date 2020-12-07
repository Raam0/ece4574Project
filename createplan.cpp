#include "createplan.h"
#include "ui_createplan.h"

/* createplan.cpp Everyone Virginia Tech
* Holds the code to randomly generate meals to choose from
*/

CreatePlan::CreatePlan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreatePlan)
{
    ui->setupUi(this);

    foods = FoodItems();

    int randOne = rand()%9;
    int randTwo = rand()%9;
    int randThree = rand()%9;
    while(randTwo == randOne)
        randTwo = rand()%9;
    while((randThree == randOne) || (randThree == randTwo))
        randThree = rand()%9;
    breakfast1 = foods.getBreakfast(randOne);
    image.load(foods.getFoodImage(breakfast1));
    ui->breakfast1button->setIcon(image);
    ui->breakfast1name->setText(breakfast1);
    breakfast2 = foods.getBreakfast(randTwo);
    image.load(foods.getFoodImage(breakfast2));
    ui->breakfast2button->setIcon(image);
    ui->breakfast2name->setText(breakfast2);
    breakfast3 = foods.getBreakfast(randThree);
    image.load(foods.getFoodImage(breakfast3));
    ui->breakfast3button->setIcon(image);
    ui->breakfast3name->setText(breakfast3);

    randOne = rand()%9;
    randTwo = rand()%9;
    randThree = rand()%9;
    while(randTwo == randOne)
        randTwo = rand()%9;
    while((randThree == randOne) || (randThree == randTwo))
        randThree = rand()%9;
    lunch1 = foods.getLunch(randOne);
    image.load(foods.getFoodImage(lunch1));
    ui->lunch1button->setIcon(image);
    ui->lunch1name->setText(lunch1);
    lunch2 = foods.getLunch(randTwo);
    image.load(foods.getFoodImage(lunch2));
    ui->lunch2button->setIcon(image);
    ui->lunch2name->setText(lunch2);
    lunch3 = foods.getLunch(randThree);
    image.load(foods.getFoodImage(lunch3));
    ui->lunch3button->setIcon(image);
    ui->lunch3name->setText(lunch3);

    randOne = rand()%9;
    randTwo = rand()%9;
    randThree = rand()%9;
    while(randTwo == randOne)
        randTwo = rand()%9;
    while((randThree == randOne) || (randThree == randTwo))
        randThree = rand()%9;
    dinner1 = foods.getDinner(randOne);
    image.load(foods.getFoodImage(dinner1));
    ui->dinner1button->setIcon(image);
    ui->dinner1name->setText(dinner1);
    dinner2 = foods.getDinner(randTwo);
    image.load(foods.getFoodImage(dinner2));
    ui->dinner2button->setIcon(image);
    ui->dinner2name->setText(dinner2);
    dinner3 = foods.getDinner(randThree);
    image.load(foods.getFoodImage(dinner3));
    ui->dinner3button->setIcon(image);
    ui->dinner3name->setText(dinner3);

    ui->errormsg->hide();
}

CreatePlan::~CreatePlan()
{
    delete ui;
}


// slots ensuring single button clicked for each meal
void CreatePlan::on_breakfast1button_clicked()
{
    ui->breakfast2button->setChecked(false);
    ui->breakfast3button->setChecked(false);
}
void CreatePlan::on_breakfast2button_clicked()
{
    ui->breakfast1button->setChecked(false);
    ui->breakfast3button->setChecked(false);
}
void CreatePlan::on_breakfast3button_clicked()
{
    ui->breakfast1button->setChecked(false);
    ui->breakfast2button->setChecked(false);
}

void CreatePlan::on_lunch1button_clicked()
{
    ui->lunch2button->setChecked(false);
    ui->lunch3button->setChecked(false);
}
void CreatePlan::on_lunch2button_clicked()
{
    ui->lunch1button->setChecked(false);
    ui->lunch3button->setChecked(false);
}
void CreatePlan::on_lunch3button_clicked()
{
    ui->lunch1button->setChecked(false);
    ui->lunch2button->setChecked(false);
}

void CreatePlan::on_dinner1button_clicked()
{
    ui->dinner2button->setChecked(false);
    ui->dinner3button->setChecked(false);
}
void CreatePlan::on_dinner2button_clicked()
{
    ui->dinner1button->setChecked(false);
    ui->dinner3button->setChecked(false);
}
void CreatePlan::on_dinner3button_clicked()
{
    ui->dinner1button->setChecked(false);
    ui->dinner2button->setChecked(false);
}


// shuffle slots
void CreatePlan::on_breakfastshuffle_clicked()
{
    int randOne = rand()%9;
    int randTwo = rand()%9;
    int randThree = rand()%9;
    while(randTwo == randOne)
        randTwo = rand()%9;
    while((randThree == randOne) || (randThree == randTwo))
        randThree = rand()%9;

    breakfast1 = foods.getBreakfast(randOne);
    image.load(foods.getFoodImage(breakfast1));
    ui->breakfast1button->setIcon(image);
    ui->breakfast1name->setText(breakfast1);
    breakfast2 = foods.getBreakfast(randTwo);
    image.load(foods.getFoodImage(breakfast2));
    ui->breakfast2button->setIcon(image);
    ui->breakfast2name->setText(breakfast2);
    breakfast3 = foods.getBreakfast(randThree);
    image.load(foods.getFoodImage(breakfast3));
    ui->breakfast3button->setIcon(image);
    ui->breakfast3name->setText(breakfast3);
}

void CreatePlan::on_lunchshuffle_clicked()
{
    int randOne = rand()%9;
    int randTwo = rand()%9;
    int randThree = rand()%9;
    while(randTwo == randOne)
        randTwo = rand()%9;
    while((randThree == randOne) || (randThree == randTwo))
        randThree = rand()%9;

    lunch1 = foods.getLunch(randOne);
    image.load(foods.getFoodImage(lunch1));
    ui->lunch1button->setIcon(image);
    ui->lunch1name->setText(lunch1);
    lunch2 = foods.getLunch(randTwo);
    image.load(foods.getFoodImage(lunch2));
    ui->lunch2button->setIcon(image);
    ui->lunch2name->setText(lunch2);
    lunch3 = foods.getLunch(randThree);
    image.load(foods.getFoodImage(lunch3));
    ui->lunch3button->setIcon(image);
    ui->lunch3name->setText(lunch3);
}

void CreatePlan::on_dinnershuffle_clicked()
{
    int randOne = rand()%9;
    int randTwo = rand()%9;
    int randThree = rand()%9;
    while(randTwo == randOne)
        randTwo = rand()%9;
    while((randThree == randOne) || (randThree == randTwo))
        randThree = rand()%9;
    dinner1 = foods.getDinner(randOne);
    image.load(foods.getFoodImage(dinner1));
    ui->dinner1button->setIcon(image);
    ui->dinner1name->setText(dinner1);
    dinner2 = foods.getDinner(randTwo);
    image.load(foods.getFoodImage(dinner2));
    ui->dinner2button->setIcon(image);
    ui->dinner2name->setText(dinner2);
    dinner3 = foods.getDinner(randThree);
    image.load(foods.getFoodImage(dinner3));
    ui->dinner3button->setIcon(image);
    ui->dinner3name->setText(dinner3);
}


// finish slot
void CreatePlan::on_finishbutton_clicked()
{
    breakfastmeal = "";
    lunchmeal = "";
    dinnermeal = "";

    if (ui->breakfast1button->isChecked()) {
        breakfastmeal = breakfast1;
    }
    else if (ui->breakfast2button->isChecked()) {
        breakfastmeal = breakfast2;
    }
    else if (ui->breakfast3button->isChecked()) {
        breakfastmeal = breakfast3;
    }

    if (ui->lunch1button->isChecked()) {
        lunchmeal = lunch1;
    }
    else if (ui->lunch2button->isChecked()) {
        lunchmeal = lunch2;
    }
    else if (ui->lunch3button->isChecked()) {
        lunchmeal = lunch3;
    }

    if (ui->dinner1button->isChecked()) {
        dinnermeal = dinner1;
    }
    else if (ui->dinner2button->isChecked()) {
        dinnermeal = dinner2;
    }
    else if (ui->dinner3button->isChecked()) {
        dinnermeal = dinner3;
    }

    if (breakfastmeal == "" || lunchmeal == "" || dinnermeal == "") {
        ui->errormsg->show();
    }
    else {
        emit mealplanchanged(breakfastmeal, lunchmeal, dinnermeal);
        delete this;
    }
}

