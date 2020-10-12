#include "startscreen.h"
#include "ui_startscreen.h"

StartScreen::StartScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartScreen)
{
    ui->setupUi(parent);

    QObject::connect(ui->beginbutton, SIGNAL(clicked(bool)), this->parent()->parent(), SLOT(loaddis()));
}

StartScreen::~StartScreen()
{
    delete ui;
}
