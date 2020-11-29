#ifndef PROFILE_H
#define PROFILE_H

#include <QObject>

class Profile
{
public:
    Profile();
    void setGender(QString selectedGender);
    void setAge(int selectedAge);
    void setHeight(QPair<int, int> selectedHeight);
    void setWeight(int selectedWeight);

    int getEER();
    void getEERmale();
    void getEERfemale();

private:
    QString gender;
    int age;
    double heightMeters;
    double weightKilograms;
    int BMI;
    int EER;
};

#endif // PROFILE_H
