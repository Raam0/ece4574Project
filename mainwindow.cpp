#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sscontainer = new QWidget(this);
    startscreen = new StartScreen(sscontainer);
    sscontainer->hide();

    discontainer = new QWidget(this);
    datainputscreen = new DataInputScreen(discontainer);
    discontainer->hide();

    fpscontainer = new QWidget(this);
    foodprefsscreen = new FoodPrefsScreen(fpscontainer);
    fpscontainer->hide();

    wpscontainer = new QWidget(this);
    workoutprefsscreen = new WorkoutPrefsScreen(wpscontainer);
    wpscontainer->hide();

    loadss();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadss()
{
    discontainer->hide();
    fpscontainer->hide();
    wpscontainer->hide();

    sscontainer->show();
}

void MainWindow::loaddis()
{
    sscontainer->hide();
    fpscontainer->hide();
    wpscontainer->hide();

    discontainer->show();
}

void MainWindow::loadfps()
{
    sscontainer->hide();
    discontainer->hide();
    wpscontainer->hide();

    fpscontainer->show();
}

void MainWindow::loadwps()
{
    sscontainer->hide();
    discontainer->hide();
    fpscontainer->hide();

    wpscontainer->show();
}
