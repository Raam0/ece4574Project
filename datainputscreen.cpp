#include "datainputscreen.h"
#include "ui_datainputscreen.h"

DataInputScreen::DataInputScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataInputScreen)
{
    ui->setupUi(parent);

    QObject::connect(ui->continuebutton, SIGNAL(clicked(bool)), this, SLOT(recordinputdata()));
    QObject::connect(ui->continuebutton, SIGNAL(clicked(bool)), this->parent()->parent(), SLOT(loadfps()));
    QObject::connect(ui->backbutton, SIGNAL(clicked(bool)), this->parent()->parent(), SLOT(loadss()));
}

DataInputScreen::~DataInputScreen()
{
    delete ui;
}

void DataInputScreen::recordinputdata()
{
    QString name = ui->nameinput->text();
    // gender
    // birthday
        // calculate age
    // height
    // weight
}
