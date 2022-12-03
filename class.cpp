#include "class.hpp"

Student::Student(std::string studName, std::string studSurname)
{
    name = studName;
    surname= studSurname;
    practicePoints = 0;
    testsPoints = 0;
    examPoints = 0;
    access = false;
}