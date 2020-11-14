#ifndef PROFILE_H
#define PROFILE_H

#include <QObject>

class Profile
{
public:
    Profile();
    void setAge(int selectedAge);
    void setHeight(QPair<int, int> selectedHeight);
    void setWeight(int selectedWeight);
    void setGender(QString selectedGender);
    void setGoal(QString selectedGoal);

    QString getGoal();
    int getEER();
    void getEERmale();
    void getEERfemale();

private:
    int age;
    int heightMeters;
    int weightKilograms;
    int BMI;
    int EER;
    QString gender;
    QString goal;
};

#endif // PROFILE_H
