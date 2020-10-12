#include "foodprefsscreen.h"
#include "ui_foodprefsscreen.h"

FoodPrefsScreen::FoodPrefsScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FoodPrefsScreen)
{
    ui->setupUi(parent);

    QObject::connect(ui->continuebutton, SIGNAL(clicked(bool)), this, SLOT(recordfoodprefs()));
    QObject::connect(ui->continuebutton, SIGNAL(clicked(bool)), this->parent()->parent(), SLOT(loadwps()));
    QObject::connect(ui->backbutton, SIGNAL(clicked(bool)), this->parent()->parent(), SLOT(loaddis()));
}

FoodPrefsScreen::~FoodPrefsScreen()
{
    delete ui;
}

void FoodPrefsScreen::recordfoodprefs()
{
    // add each checked item to a list
}
