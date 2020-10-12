#ifndef WORKOUTPREFSSCREEN_H
#define WORKOUTPREFSSCREEN_H

#include <QWidget>

namespace Ui {
class WorkoutPrefsScreen;
}

class WorkoutPrefsScreen : public QWidget
{
    Q_OBJECT

public:
    explicit WorkoutPrefsScreen(QWidget *parent = 0);
    ~WorkoutPrefsScreen();

private slots:
    void recordworkoutprefs();

private:
    Ui::WorkoutPrefsScreen *ui;
};

#endif // WORKOUTPREFSSCREEN_H
