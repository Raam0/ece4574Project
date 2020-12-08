/* profile.h Tim Paul Virginia Tech
* The methods in the profile class
* will be used to store user info
* and calculate the EER value
 */
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
