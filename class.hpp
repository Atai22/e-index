#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;


//class for students
class Student
{
	public:
	Student(std::string, std::string);
	std::string name;
	std::string surname;
	unsigned short practicePoints;
	unsigned short testsPoints;
	unsigned short examPoints;
	bool access; 

} ;

//class for subject
class Subject
{
	public:
	std::string name;
	std::vector<Student>studentlist;
	int pointForAccess;

	bool checkAccess();
};