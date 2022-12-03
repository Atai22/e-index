#include <iostream>
#include <string> 
#include <fstream> 
#include "class.hpp"


void creat_new_student(ofstream& file) 
{
    int choose_action;
    printf("Write student's name:\n");
    char buf[101];
    scanf("%100s", buf);
    std::string studName=buf;
    std::cout << studName << endl;
    printf("Write student's surname:\n");
    char buf2[101];
    scanf("%100s", buf2);
    std::string studSurname=buf2;
    Student newStudent(studName, studSurname);
    file << newStudent.name << "\t" << newStudent.surname << "\t" << newStudent.practicePoints << "\t" << newStudent.testsPoints << "\t" << newStudent.examPoints << std::endl;
        
}  

void add_new_information(){
     int numbers;
     printf("if u want to uploat points for semenar press 1-,\n if u want to uploat points for test press 2-\n if u want to see the result press 3-\n else you go to menu-");
     if (numbers==1)
     {
         printf("U choose add points for semenar");
     }
     else if (numbers == 2)
     {
         printf("u choose add points for tast\n"); 
     }
     else if (numbers == 3)
     {
         printf("u choose see the result\n"); 
     }
     else 
     {
         printf("invalid input and u go to menu\n"); 
     }   
 }


void information(ofstream& file){
    int information_chosen;
    printf ("Choose creat new student (1) or add new infomation(2)\n or go to back-");
    scanf("%d",&information_chosen);
    if (information_chosen == 1) {
        printf("u choose creat new student\n"); 
        creat_new_student(file);
    }
    else if (information_chosen == 2)
    {
        printf("u choose add new information\n"); 
        //add_new_information();
    }
    else if (information_chosen == 3)
    {
        printf("u went back to menu\n"); 
    
    } 
    else 
    {
        printf("invalid input and u go to menu\n"); 
    }
   
}

int main (){
    int subject_chosen;
    while (1)
    {    
        printf("Choose subject: math-1, biology-2:\n");
        scanf("%d",&subject_chosen);

        if(subject_chosen == 1) {
            printf("u choose math\n");
            ofstream mathsfile; 
            mathsfile.open("Maths.txt", ios::out | ios::app | ios::in);
            information(mathsfile);
        }
        else if (subject_chosen == 2)
        {
            printf("u choose biology\n"); 
           ofstream biologyfile; 
            biologyfile.open("Biology.txt", ios::out | ios::app | ios::in);
            information(biologyfile);
        }
        else
        {
            printf("invalid input and u stay in menu\n"); 
        }
    }
        return 0;
}

