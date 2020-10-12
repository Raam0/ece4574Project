#include "workoutprefsscreen.h"
#include "ui_workoutprefsscreen.h"

WorkoutPrefsScreen::WorkoutPrefsScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkoutPrefsScreen)
{
    ui->setupUi(parent);

    QObject::connect(ui->finishbutton, SIGNAL(clicked(bool)), this, SLOT(recordworkoutprefs()));
    //QObject::connect(ui->finishbutton, SIGNAL(clicked(bool)), this->parent()->parent(), SLOT());
    QObject::connect(ui->backbutton, SIGNAL(clicked(bool)), this->parent()->parent(), SLOT(loadfps()));
}

WorkoutPrefsScreen::~WorkoutPrefsScreen()
{
    delete ui;
}

void WorkoutPrefsScreen::recordworkoutprefs()
{
    // add each checked item to a list
}
