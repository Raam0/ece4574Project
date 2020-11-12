#include "lssdapplication.h"
#include "ui_lssdapplication.h"

/*
 * (a ui stack is a group of pages)
 * main stack
 *      0: start page
 *      1: data input page
 *          0: name input page
 *          1: gender input page
 *          2: birthdate input page
 *          3: height & weight input page
 *          4: food preferences input page
 *          5: workout preferences input page
 *          6: goal input
 *      2: main page
 */

LSSDApplication::LSSDApplication(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LSSDApplication)
{
    ui->setupUi(this);
    // initializations
    ui->mainstack->setCurrentIndex(0);
    ui->datainputstack->setCurrentIndex(0);
    ui->datainputbackground->hide();
    ui->errormsg->hide();
    name = "";
    gender = Male;
    birthdate = QDate();
    height.first = 0;
    height.second = 0;
    foodprefs = QList<int>();
    workoutprefs = QList<int>();
    goal = MaintainWeight;
    goalcalories = 2000;
    consumedcalories = 0;

    // add pictures to buttons for food preferences page
    image.load(applesim);
    ui->applesbutton->setIcon(image);
    image.load(bananasim);
    ui->bananasbutton->setIcon(image);
    image.load(beansim);
    ui->beansbutton->setIcon(image);
    image.load(beefim);
    ui->beefbutton->setIcon(image);
    image.load(breadim);
    ui->breadbutton->setIcon(image);
    image.load(broccoliim);
    ui->broccolibutton->setIcon(image);
    image.load(carrotsim);
    ui->carrotsbutton->setIcon(image);
    image.load(chickenim);
    ui->chickenbutton->setIcon(image);
    image.load(pastaim);
    ui->pastabutton->setIcon(image);
    image.load(potatoesim);
    ui->potatoesbutton->setIcon(image);
    image.load(riceim);
    ui->ricebutton->setIcon(image);
    image.load(seafoodim);
    ui->seafoodbutton->setIcon(image);
    // add pictures to buttons for workout preferences page
    image.load(cyclingim);
    ui->cyclingbutton->setIcon(image);
    image.load(dancingim);
    ui->dancingbutton->setIcon(image);
    image.load(hikingim);
    ui->hikingbutton->setIcon(image);
    image.load(runningim);
    ui->runningbutton->setIcon(image);
    image.load(sportsim);
    ui->sportsbutton->setIcon(image);
    image.load(swimmingim);
    ui->swimmingbutton->setIcon(image);
    image.load(walkingim);
    ui->walkingbutton->setIcon(image);
    image.load(weightliftingim);
    ui->weightliftingbutton->setIcon(image);
    image.load(yogaim);
    ui->yogabutton->setIcon(image);
}

LSSDApplication::~LSSDApplication()
{
    delete ui;
}

// performed when "next" button pressed (so that size can be checked to be >3)
void LSSDApplication::createfoodprefslist() {
    foodprefs = QList<int>(); // clears just in case user clicks "next" again (after going back, etc)
    if (ui->applesbutton->isChecked()) {
        foodprefs.push_back(Apples);
    }
    if (ui->bananasbutton->isChecked()) {
        foodprefs.push_back(Bananas);
    }
    if (ui->beansbutton->isChecked()) {
        foodprefs.push_back(Beans);
    }
    if (ui->beefbutton->isChecked()) {
        foodprefs.push_back(Beef);
    }
    if (ui->breadbutton->isChecked()) {
        foodprefs.push_back(Bread);
    }
    if (ui->broccolibutton->isChecked()) {
        foodprefs.push_back(Broccoli);
    }
    if (ui->carrotsbutton->isChecked()) {
        foodprefs.push_back(Carrots);
    }
    if (ui->chickenbutton->isChecked()) {
        foodprefs.push_back(Chicken);
    }
    if (ui->pastabutton->isChecked()) {
        foodprefs.push_back(Pasta);
    }
    if (ui->potatoesbutton->isChecked()) {
        foodprefs.push_back(Potatoes);
    }
    if (ui->ricebutton->isChecked()) {
        foodprefs.push_back(Rice);
    }
    if (ui->seafoodbutton->isChecked()) {
        foodprefs.push_back(Seafood);
    }
}

// performed when "next" button pressed (so that size can be checked to be >3)
void LSSDApplication::createworkoutprefslist() {
    workoutprefs = QList<int>(); // clears just in case user clicks "next" again (after going back, etc)
    if (ui->cyclingbutton->isChecked()) {
        workoutprefs.push_back(Cycling);
    }
    if (ui->dancingbutton->isChecked()) {
        workoutprefs.push_back(Dancing);
    }
    if (ui->hikingbutton->isChecked()) {
        workoutprefs.push_back(Hiking);
    }
    if (ui->runningbutton->isChecked()) {
        workoutprefs.push_back(Running);
    }
    if (ui->sportsbutton->isChecked()) {
        workoutprefs.push_back(Sports);
    }
    if (ui->swimmingbutton->isChecked()) {
        workoutprefs.push_back(Swimming);
    }
    if (ui->walkingbutton->isChecked()) {
        workoutprefs.push_back(Walking);
    }
    if (ui->weightliftingbutton->isChecked()) {
        workoutprefs.push_back(WeightLifting);
    }
    if (ui->yogabutton->isChecked()) {
        workoutprefs.push_back(Yoga);
    }
}

// performed when "finish" button pressed (final page of data input stack)
void LSSDApplication::recordinputs() {
    // name
    name = ui->nameinput->text();
    // gender
    if (ui->malerb->isChecked()) {
        gender = Male;
    }
    else {
        gender = Female;
    }
    // birthdate
    birthdate = ui->birthdateinput->date();
    // height
    height.first = ui->heightftinput->value();
    height.second = ui->heightininput->value();
    // weight
    initialweight = ui->weightinput->value();
    // goal
    if (ui->loseweightrb->isChecked()) {
        goal = LoseWeight;
    }
    else if (ui->maintainweightrb->isChecked()) {
        goal = MaintainWeight;
    }
    else {
        goal = GainWeight;
    }
}

// performed when "finish" button pressed (final page of data input stack)
void LSSDApplication::createmainpage() {
    ui->namelabel->setText("Hi " + name + "!");
    // ---> calculate goal calories from gender, height, goal, etc info <---
    ui->goalcaloriesnum->setValue(goalcalories);
    ui->todaycaloriesnum->setValue(0);
    ui->remainingcaloriesnum->setValue(goalcalories);
    ui->caloriesprogressbar->setValue(0);
    ui->initialweightnum->setValue(initialweight);
    ui->currentweightnum->setValue(initialweight);
    ui->weightchangenum->setValue(0);
}


// SLOTS FOR DATA INPUT

void LSSDApplication::on_startbutton_clicked()
{
    ui->datainputstack->setCurrentIndex(0);
    ui->datainputbackground->show();
    ui->mainstack->setCurrentIndex(1);
}

// for each page, checks for valid inputs
// moves to next page with inputs, shows error label if none given
// if on last page of data input stack, move to third page of main stack
void LSSDApplication::on_nextbutton_clicked()
{
    ui->errormsg->hide();

    // nameinputpage
    if (ui->datainputstack->currentIndex() == 0) {
        if (ui->nameinput->text() != "") {
            ui->datainputstack->setCurrentIndex(1);
        }
        else {
            ui->errormsg->setText("Please enter your name.");
            ui->errormsg->show();
        }

    }
    // genderinputpage
    else if (ui->datainputstack->currentIndex() == 1) {
        if (ui->malerb->isChecked() ||
                ui->femalerb->isChecked()) {
            ui->datainputstack->setCurrentIndex(2);
        }
        else {
            ui->errormsg->setText("Please select your gender.");
            ui->errormsg->show();
        }
    }
    // birthdayinputpage
    else if (ui->datainputstack->currentIndex() == 2) {
        if (ui->birthdateinput->date() != QDate(2020, 1, 1)) {
            ui->datainputstack->setCurrentIndex(3);
        }
        else {
            ui->errormsg->setText("Please enter your birthdate.");
            ui->errormsg->show();
        }
    }
    // measurementsinputpage
    else if (ui->datainputstack->currentIndex() == 3) {
        if (ui->heightftinput->value() != 0 &&
                ui->weightinput->value() != 0) {
            ui->datainputstack->setCurrentIndex(4);
        }
        else {
            if (ui->heightftinput->value() == 0 &&
                    ui->weightinput->value() == 0) {
                ui->errormsg->setText("Please enter your height and weight.");
            }
            else if (ui->heightftinput->value() == 0) {
                ui->errormsg->setText("Please enter your height.");
            }
            else {
                ui->errormsg->setText("Please enter your weight.");
            }
            ui->errormsg->show();
        }

    }
    // foodprefspage
    else if (ui->datainputstack->currentIndex() == 4) {
        createfoodprefslist();
        if (foodprefs.size() >= 3) {
            ui->datainputstack->setCurrentIndex(5);
        }
        else {
            ui->errormsg->setText("Please choose three options.");
            ui->errormsg->show();
        }
    }
    // workoutprefspage
    else if (ui->datainputstack->currentIndex() == 5) {
        createworkoutprefslist();
        if (workoutprefs.size() >= 3) {
            ui->datainputstack->setCurrentIndex(6);
            ui->nextbutton->setText("Finish"); // sets "continue" to "finish"
        }
        else {
            ui->errormsg->setText("Please choose three options.");
            ui->errormsg->show();
        }
    }
    // goalinputpage
    else if (ui->datainputstack->currentIndex() == 6) {
        if (ui->loseweightrb->isChecked() ||
                ui->maintainweightrb->isChecked() ||
                ui->gainweightrb->isChecked()) {
            ui->datainputbackground->hide();
            recordinputs();
            createmainpage();
            ui->mainstack->setCurrentIndex(2);
        }
        else {
            ui->errormsg->setText("Please choose a goal.");
            ui->errormsg->show();
        }
    }
}

// moves back one page unless currently on the first page of the data input stack
// in which case, moves to first page of main stack
void LSSDApplication::on_backbutton_clicked()
{
    ui->errormsg->hide();

    if (ui->datainputstack->currentIndex() == 0) {
        ui->datainputbackground->hide();
        ui->mainstack->setCurrentIndex(0);
    }
    else {
        ui->datainputstack->setCurrentIndex(
                    ui->datainputstack->currentIndex()-1);
        if (ui->datainputstack->currentIndex() == 5) {
            ui->nextbutton->setText("Continue"); // resets from "finish" to "continue"
        }
    }
};


// SLOTS FOR MAIN PAGE

// adds input to "calories consumed so far today"
// calculates "remaining calories today"
// calculates percentage of calories consumed for the progress bar
void LSSDApplication::on_caloriesinputbutton_clicked()
{
    consumedcalories = consumedcalories + ui->caloriesinput->value();
    ui->todaycaloriesnum->setValue(consumedcalories);
    ui->remainingcaloriesnum->setValue(goalcalories - consumedcalories);
    ui->caloriesprogressbar->setValue(double(consumedcalories) / goalcalories * 100);
}

// updates "weight change" value
void LSSDApplication::on_currentweightnum_valueChanged(int arg1)
{
    ui->weightchangenum->setValue(arg1 - initialweight);
}

void LSSDApplication::on_generatefoodsbutton_clicked()
{
    // ---> generate food recommendations <---
}

void LSSDApplication::on_generateworkoutsbutton_clicked()
{
    // ---> generate workout recommendations <---
}
