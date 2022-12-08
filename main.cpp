#include <iostream>
#include <string> 
#include <fstream> 
#include <sstream>
#include <stdlib.h>
#include "class.hpp"
using namespace std;


#define MATHS 1
#define BIOLOGY 2


//delete student2 (byl inspirován nápadem z internetového fóra.)
void delete_line(const char *file_name, int n)
{
    // open file in read mode or in mode
    ifstream is(file_name);
  
    // open file in write mode or out mode
    ofstream tmp;
    tmp.open("temp.txt", ofstream::out);
  
    // loop getting single characters
    char c;
    int line_no = 1;
    while (is.get(c))
    {
        // if a newline character
        if (c == '\n')
        line_no++;
  
        // file content not to be deleted
        if (line_no != n)
            tmp << c;
    }
  
    // closing output file
    tmp.close();
  
    // closing input file
    is.close();
  
    // remove the original file
    remove(file_name);
  
    // rename the file
    rename("temp.txt", file_name);
}


//delete student1
void del(int choose)
{
    printf("Enter name of student you want to delete:\n");

    char nameBuf[101];
    scanf("%100s", nameBuf);
    std::string studName = nameBuf;

    printf("Enter surname of student you want to delete:\n");

    char surnameBuf[101];
    scanf("%100s", surnameBuf);
    std::string studSurname = surnameBuf;

    fstream file;

    if(choose == MATHS) file.open("Maths.txt", ios::in);
    else if (choose == BIOLOGY) file.open("Biology.txt", ios::in);

    std::string buf;

    int lineNumber = 0;
    bool found = false;

    while(getline(file, buf)) 
    {
        if(buf.find(studName + " " + studSurname) != string::npos) 
        {
            found = true;
            break;
        }
        lineNumber++;
    }

    if(!found)
    {
        std::cout << "Sorry, wasn't able to find \"" + studName + " " + studSurname + "\" in your table";
        return;
    }

    if(choose == 1) delete_line("Maths.txt", lineNumber + 1);    
    else delete_line("Biology.txt", lineNumber + 1);

}


//create students
void create_new_student(int choose) 
{
    fstream file;
    int E1;
    int E2;
    int D1;
    int D2 ;
    int C1 ;
    int C2 ;
    int B1 ;
    int B2 ;
    int A1 ;
    int A2 ;      
    if(choose == MATHS) 
    {
        file.open("Maths.txt", ios::app);
        E1 = 50; E2 = 60; D1=60; D2 = 70; C1=70; C2 = 75; B1=75; B2 = 90; A1=90; A2 = 100; 
    }
    else if (choose == BIOLOGY){
        file.open("Biology.txt", ios::app);
        E1 = 10; E2 = 20; D1=20; D2 = 30; C1=30; C2 = 40; B1=40; B2 = 50; A1=50; A2 = 100; 
    } 

    printf("Enter student's name:\n");

    char nameBuf[101];
    scanf("%100s", nameBuf);
    std::string studName = nameBuf;

    printf("Enter student's surname:\n");

    char surnameBuf[101];
    scanf("%100s", surnameBuf);
    std::string studSurname = surnameBuf;

    printf("Enter student's practice points:\n");
    unsigned short practicePoints;
    scanf("%hd", &practicePoints);

    printf("Enter student's test points:\n");
    unsigned short testsPoints;
    scanf("%hd", &testsPoints);
    
    printf("Enter student's exam points:\n");
    unsigned short examPoints;
    scanf("%hd", &examPoints);

    char mark = 'F'; 

    int pointSum = practicePoints + testsPoints + examPoints;

    
    if (pointSum >= E1 && pointSum < E2) mark = 'E';
    else if (pointSum >= D1 && pointSum < D2) mark = 'D';
    else if (pointSum >= C1 && pointSum < C2) mark = 'C';
    else if (pointSum >= B1 && pointSum < B2) mark = 'B';
    else if (pointSum >= A1 && pointSum <= A2) mark = 'A';
    else if (pointSum > 100)
    {
        cout << "Student " + studName + " " + studSurname + " has more than 100 points! Check it one more time, please!\n";
        return;
    }
  
    file << studName << " " << studSurname << " " << practicePoints << " " << testsPoints << " " << examPoints << " " << mark << std::endl;


    file.close();        
}  


//result
void viewSubject(int choose)
{
    fstream file; 
    
    if(choose == MATHS) file.open("Maths.txt", ios::in);
    if(choose == BIOLOGY) file.open("Biology.txt", ios::in);

    std::string buf;

    while(getline(file, buf)) std::cout << buf << std::endl;

    file.close();
}      


//choose function
void information(int choose)
{
    printf ("[1]Create new student\n[2]View whole subject index\n[3]Delete student\n");\
    
    int information_chosen;
    scanf("%d",&information_chosen);

    if (information_chosen == 1) create_new_student(choose);
    else if (information_chosen == 2) viewSubject(choose);
    else if (information_chosen == 3) del(choose);
   
}


//main
int main (){
    int subject_chosen;
    while (1)
    {    
        printf("Choose subject:\n[1]Math\n[2]Biology\n[0]End work\n");
        scanf("%d",&subject_chosen);

        if(subject_chosen == 1) {
            printf("Math:\n");
            information(MATHS);

            std::cout << "\n\n\n";
        }
        else if (subject_chosen == 2)
        {
            printf("Biology:\n"); 
            information(BIOLOGY);

            std::cout << "\n\n\n";
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