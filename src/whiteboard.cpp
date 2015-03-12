/*
 *    File         : whiteboard.cpp 
 *    Description  : Establishes prototypes for  whiteboard.h
 *    Rev          : 1.0
 *    Created      : Sunday Mar 14, 2015
 *    Authors      : Chad Netwig, Paul Liverman, Erik Montgomery
 *    
*/
#include "whiteboard.h"

using namespace std;

Student::Student(){
    id        = -1;
    lastName  = "VOID";
    firstName = "VOID";

}
Student::Student(int init_id, string init_lastName, string init_firstName){
    id        = init_id;
    lastName  = init_lastName;
    firstName = init_firstName;
    }

Assignments::Assignments() {
        
     aId        = -1;
     assignType = -1;
     grade1     = -1;
     grade2     = -1;
     grade3     = -1;
     grade4     = -1;
     grade5     = -1;
        
    }
Assignments::Assignments(int init_id, int init_assignType, int init_grade1, int init_grade2, int init_grade3, int init_grade4, int init_grade5 ){
   
    aId         = init_id;
    assignType  = init_assignType;
    grade1      = init_grade1;
    grade2      = init_grade2;
    grade3      = init_grade3;
    grade4      = init_grade4;
    grade5      = init_grade5;  
    
}


