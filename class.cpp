#include "class.hpp"

Student::Student(std::string studName, std::string studSurname, unsigned short studPpoints, unsigned short studTpoints, unsigned short studEpoints)
{
    name = studName;
    surname = studSurname;
    practicePoints = studPpoints;
    testsPoints = studTpoints;
    examPoints = studEpoints;
    access = false;
}


Subject::Subject(std::string subjName)
{
    name = subjName;
    pointForAccess = 0;
}