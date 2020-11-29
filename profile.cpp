#include "profile.h"


Profile::Profile():
    gender("Male"), age(0), heightMeters(0.0),
    weightKilograms(0.0), BMI(0), EER(0)
{}


void Profile::setGender(QString selectedGender)
{
    gender = selectedGender;
}

void Profile::setAge(int selectedAge)
{
    age = selectedAge;
}

void Profile::setHeight(QPair<int, int> selectedHeight)
{
    heightMeters = (selectedHeight.first * 12 + selectedHeight.second) * 0.0254;
}

void Profile::setWeight(int selectedWeight)
{
    weightKilograms = selectedWeight * 0.45359237;
}


int Profile::getEER()
{
    BMI = weightKilograms/(heightMeters*heightMeters);

    if(gender == "Male")
    {
        getEERmale();
    }
    else
    {
        getEERfemale();
    }

    return EER;
}

void Profile::getEERmale()
{
    if(BMI < 25)
    {
        if(age < 18)
        {
            EER = 113.5 - 61.9 * age + 1.26 * (26.7 * weightKilograms + 903 * heightMeters);
        }
        else
        {
            EER = 661.8 - 9.53 * age + 1.25 * (15.91 * weightKilograms + 539.6 * heightMeters);
        }
    }
    else
    {
        if(age < 18)
        {
            EER = -114.1 - 50.9 * age + 1.24 * (19.5 * weightKilograms + 1161.4 * heightMeters);
        }
        else
        {

            EER = 1085.6 - 10.08 * age + 1.29 * (13.7 * weightKilograms + 416 * heightMeters);
        }
    }
}

void Profile::getEERfemale()
{
    if(BMI < 25)
    {
        if(age < 18)
        {
            EER = 160.3 - 30.8 * age + 1.31 * (10 * weightKilograms + 934 * heightMeters);
        }
        else
        {
            EER = 354.1 - 6.91 * age + 1.27 * (9.36 * weightKilograms + 726 * heightMeters);
        }
    }
    else
    {
        if(age < 18)
        {
            EER = -114.1 - 50.9 * age + 1.35 * (19.5 * weightKilograms + 1161.4 * heightMeters);
        }
        else
        {

            EER = 1085.6 - 10.08 * age + 1.27 * (13.7 * weightKilograms + 416 * heightMeters);
        }
    }
}

