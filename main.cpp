#include <iostream>
#include <string> 
#include <fstream> 
#include <stdlib.h>
#include "class.hpp"
using namespace std;


/*void del(fstream& file)
{
 std::string studDel;  
 printf ("enter name and surname whichone u want to delete ");
 scanf ("%100s",studDel);
 std::string studDel; 
 if (studDel==studName)
 {
    while (getline(file, studDel))
        {   
        std::cout<<studDel<<std::endl;
        }
 }      
}*/


//creat students
void creat_new_student(fstream& file) 
{
    int choose_action;
    printf("enter student's name:\n");
    char buf[101];
    scanf("%100s", buf);
    std::string studName=buf;
    //std::cout << studName << endl;

    printf("enter student's surname:\n");
    char buf2[101];
    scanf("%100s", buf2);
    std::string studSurname=buf2;
    //std::cout << studSurname << endl;

    printf("enter student's practis points:\n");
    unsigned short  buf3;
    scanf("%d", buf3);
    unsigned short studPpoints = buf3;
    cout << studPpoints << endl;

    printf("enter student's test points:\n");
    unsigned short buf4;
    scanf("%d", buf4);
    unsigned short studTpoints = buf4;
    cout << studTpoints << endl;

    printf("enter student's test points:\n");
    unsigned short buf5;
    scanf("%d", buf5);
    unsigned short studEpoints = buf5;
    cout << studEpoints << endl;

    Student newStudent(studName, studSurname, studPpoints, studTpoints, studEpoints);
    file << newStudent.name << "\t" << newStudent.surname << "\t" << newStudent.practicePoints << "\t" << newStudent.testsPoints << "\t" << newStudent.examPoints << std::endl;
        
}  

//result
void result(fstream& file)
    {
     std::string bufs; 
     while (getline(file, bufs))
        {   
        std::cout<<bufs<<std::endl;
        }
     }      


//choose function
void information(fstream& file)
{
    int information_chosen;
    printf ("Choose to creat a new student (1) or see result(2)\n or delete student (3)\n");
    scanf("%d",&information_chosen);
    if (information_chosen == 1) {
        printf("u choose creat a new student\n"); 
        creat_new_student(file);
    }
    else if (information_chosen == 2)
    {
        printf("see result\n"); 
        result(file);
    }
    else if (information_chosen == 3)
    {
        //del(file);
    }
   
}


//main
int main (){
    int subject_chosen;
    while (1)
    {    
        printf("Choose subject: math-1, biology-2:\nexit is 0-\n");
        scanf("%d",&subject_chosen);

        if(subject_chosen == 1) {
            printf("u choose math\n");
            fstream mathsfile; 
            mathsfile.open("Maths.txt", ios::out | ios::app | ios::in);
            information(mathsfile);
        }
        else if (subject_chosen == 2)
        {
            printf("u choose biology\n"); 
            fstream biologyfile; 
            biologyfile.open("Biology.txt", ios::out | ios::app | ios::in);
            information(biologyfile);
        }
        else if (subject_chosen == 0)
        {
            printf("Thanks and bye\n");
            break;
        }
        else
        {
            printf("invalid input and u stay in menu\n"); 
        }
    }   
        return 0;
}

