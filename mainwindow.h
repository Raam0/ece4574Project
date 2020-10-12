#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include <startscreen.h>
#include <datainputscreen.h>
#include <foodprefsscreen.h>
#include <workoutprefsscreen.h>

class StartScreen;
class DataInputScreen;
class FoodPrefsScreen;
class WorkoutPrefsScreen;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void loadss();
    void loaddis();
    void loadfps();
    void loadwps();

private:
    Ui::MainWindow *ui;
    QWidget * sscontainer;
    StartScreen * startscreen;
    QWidget * discontainer;
    DataInputScreen * datainputscreen;
    QWidget * fpscontainer;
    FoodPrefsScreen * foodprefsscreen;
    QWidget * wpscontainer;
    WorkoutPrefsScreen * workoutprefsscreen;
};

#endif // MAINWINDOW_H
