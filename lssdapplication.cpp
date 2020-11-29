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

    profile = Profile();
    name = "";
    workoutprefs = QList<QString>();

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

    foods = FoodItems();
    breakfastscene = new QGraphicsScene;
    lunchscene = new QGraphicsScene;
    dinnerscene = new QGraphicsScene;
    workouts = Workouts();
    workout1scene = new QGraphicsScene;
    workout2scene = new QGraphicsScene;
    workout3scene = new QGraphicsScene;
}

LSSDApplication::~LSSDApplication()
{
    delete ui;
}

// performed when "next" button pressed (so that size can be checked to be >3)
void LSSDApplication::createworkoutprefslist() {
    workoutprefs = QList<QString>(); // clears just in case user clicks "next" again (after going back, etc)
    if (ui->cyclingbutton->isChecked()) {
        workoutprefs.push_back("Bicycling");
    }
    if (ui->dancingbutton->isChecked()) {
        workoutprefs.push_back("Dancing");
    }
    if (ui->hikingbutton->isChecked()) {
        workoutprefs.push_back("Hiking");
    }
    if (ui->runningbutton->isChecked()) {
        workoutprefs.push_back("Running");
    }
    if (ui->sportsbutton->isChecked()) {
        workoutprefs.push_back("Sports");
    }
    if (ui->swimmingbutton->isChecked()) {
        workoutprefs.push_back("Swimming");
    }
    if (ui->walkingbutton->isChecked()) {
        workoutprefs.push_back("Walking");
    }
    if (ui->weightliftingbutton->isChecked()) {
        workoutprefs.push_back("Weight Lifting");
    }
    if (ui->yogabutton->isChecked()) {
        workoutprefs.push_back("Yoga");
    }
}

// performed when "finish" button pressed (final page of data input stack)
void LSSDApplication::recordinputs() {
    // name
    name = ui->nameinput->text();
    // gender
    if (ui->malerb->isChecked()) {
        profile.setGender("Male");
    }
    else {
        profile.setGender("Female");
    }
    // birthdate & age
    QDate birthdate = ui->birthdateinput->date();
    profile.setAge(2020-birthdate.year());
    // height
    QPair<int, int> height;
    height.first = ui->heightftinput->value();
    height.second = ui->heightininput->value();
    profile.setHeight(height);
    // weight
    initialweight = ui->weightinput->value();
    profile.setWeight(initialweight);
    // workout preferences
    workouts.setAvailableWorkouts(workoutprefs);
    // goal
    if (ui->loseweightrb->isChecked()) {
        workouts.setGoal(LoseWeight);
    }
    else {
        workouts.setGoal(MaintainWeight);
    }
    workouts.setCalories(profile.getEER());
}

// performed when "finish" button pressed (final page of data input stack)
void LSSDApplication::createmainpage() {
    ui->namelabel->setText("Hi " + name + "!");
    // calculate goal net calories
    ui->initialweightvalue->setValue(initialweight);
    ui->currentweightvalue->setValue(initialweight);
    ui->weightchangevalue->setValue(0);
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
            ui->datainputstack->setCurrentIndex(5);
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
                ui->maintainweightrb->isChecked()) {
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
    else if (ui->datainputstack->currentIndex() == 5) {
        ui->datainputstack->setCurrentIndex(3);
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
void LSSDApplication::on_createplanbutton_clicked()
{
    CreatePlan * createplanwindow = new CreatePlan;
    QObject::connect(createplanwindow, SIGNAL(mealplanchanged(QString, QString, QString)), this, SLOT(updateplan(QString, QString, QString)));
    createplanwindow->show();
}

void LSSDApplication::updateplan(QString breakfast, QString lunch, QString dinner)
{
    // foods
    breakfastscene->addPixmap(foods.getFoodImage(breakfast));
    ui->breakfastgraphic->setScene(breakfastscene);
    ui->breakfastname->setText(breakfast);
    lunchscene->addPixmap(foods.getFoodImage(lunch));
    ui->lunchgraphic->setScene(lunchscene);
    ui->lunchname->setText(lunch);
    dinnerscene->addPixmap(foods.getFoodImage(dinner));
    ui->dinnergraphic->setScene(dinnerscene);
    ui->dinnername->setText(dinner);

    // workouts
    int inputcalories = foods.getFoodCalories(breakfast) +
                        foods.getFoodCalories(lunch) +
                        foods.getFoodCalories(dinner);
    workouts.generateWorkouts(inputcalories);
    QList<QString> workoutslist = workouts.getRecommendations();
    QList<int> workoutsdurationslist = workouts.getTimeRecommendations();
    workout1scene->addPixmap(workouts.getWorkoutImage(workoutslist.at(0)));
    ui->workout1graphic->setScene(workout1scene);
    ui->workout1name->setText(workoutslist.at(0));
    ui->workout1duration->setText(QString::number(workoutsdurationslist.at(0))+" minutes");
    workout2scene->addPixmap(workouts.getWorkoutImage(workoutslist.at(1)));
    ui->workout2graphic->setScene(workout2scene);
    ui->workout2name->setText(workoutslist.at(1));
    ui->workout2duration->setText(QString::number(workoutsdurationslist.at(1))+" minutes");
    workout3scene->addPixmap(workouts.getWorkoutImage(workoutslist.at(2)));
    ui->workout3graphic->setScene(workout3scene);
    ui->workout3name->setText(workoutslist.at(2));
    ui->workout3duration->setText(QString::number(workoutsdurationslist.at(2))+" minutes");
}

void LSSDApplication::on_currentweightvalue_valueChanged(int arg1)
{
    ui->weightchangevalue->setValue(arg1-initialweight);
}


