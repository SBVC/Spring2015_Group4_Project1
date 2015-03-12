#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm> // for std:fill used to populate vectors
#include "whiteboard.h"

/*
 *    File         : W06L.txt (Week 6 lab) - Group Project 1 4
 *    Description  : Whiteboard allows user to enter students and student assignments into memory. Students can
 *                 : be searched by their user ID, last name, and first name. Edits to the student's assignments
 *                 : can be made through the backdoor menu, which is accessed using code 20966 from the Main Menu.
 *    Rev          : 1.0
 *    Created      : Sunday Mar 14, 2015
 *    Authors      : Chad Netwig, Paul Liverman, Erik Montgomery
 *    
*/


/* PROJECT NOTES:
 * 
 *
 * ADDED SUN, 03/01/15 - CHAD
 * 
 * THERE ARE BLOCK COMMENTS THROUGHOUT THE CODE WITH NOTES ON THE CODE THAT STILL NEEDS TO BE IMPLEMENTED
 * 
 * [X] = DONE 
 * [X] 1) INPUT VALIDATION NEEDS TO BE IMPLEMENTED FOR POINT RANGES FOR EACH TYPE OF ASSIGNMENT. IE. QUIZZES, EXAMS, ETC.
 * [X] 2) NEED TO CONTINUE ADDING ASSIGNMENT TYPES TO ADDSTUDENTS CLASS PER USER INTERFACE PDF
 * [X] 3) FINDSTUDENT CLASS NEEDS TO BE FINISHED TO SEARCH FOR THE VARIOUS CASE STATEMENTS THEREIN
 * [ ] 4) NEED TO IMPLEMENT A FUNCTION TO DETERMINE THE MAX POINTS POSSIBLE FOR EACH ASSIGNMENT TYPE SO THIS CAN LATER
 *        BE USED TO CALCULATE TOTAL GRADE
 * [X] 5) THE BACKDOOR MENU STILL NEEDS TO BE DONE
 * [X] 7) STUDENT EDIT MENU NEEDS TO BE CREATED TO CHANGE VALUES IN STUDENTASSIGNMENTS VECTOR
 * [X] 8) INSTEAD OF USING REDUDANT CODE (LIKE IT IS NOW) IN SHOWSTUDENT METHOD WITHIN FINDSTUDENT CLASS, NEED TO EXPAND
 *        DISPLAYSTUDENTS CLASS TO ACCEPT A SINGLE INDEX INSIDE STUDENTLIST VECTOR. THIS WAY A PARTICULAR STUDENT THAT IS
 *        SEARCHED FOR EITHER THROUGH THE SEARCH STUDENTS MENU OR A STUDENT ID THROUGH THE BACKDOOR MENU CAN BE DISPLAYED.
 *        THEN SHOWSTUDENT CAN BE ELIMINATED. AS IT STANDS NOW, DISPLAYSTUDENTS DUMPS ENTIRE STUDENTLIST VECTOR.
 * i) FINAL THOUGHT: THERE ARE SEVERAL WAYS TO ACCOMPLISH THIS PROJECT. BUT WHAT IS HERE IS A PLATFORM THAT 
 *    SHOULD PROVE TO GET THE JOB DONE. IN OTHER WORDS, LET'S CONTINUE WITH WHAT WE HAVE RATHER THAN TAKING ON
 *    MAJOR RESTRUCTURING OF THE CODE. WE'RE CLOSE, I HOPE YOU GUYS LIKE IT.
 * ii) MORE STUFF (BUGS) THAT I'M TOO TIRED TO THINK OF RIGHT NOW :)
 * ADDED 03/08/15:
 * [ ]  9) Need to setup CONSTs for max points, which will help with #4 above.
 * [ ] 10) Need to implement a custom assignment type. Only one.
 * [ ] 11) Need to implement ability to search by total grade.
 * [ ] 12) Validation for edit menu.
 */

using namespace std;
static int studentcnt = 0;  // Keeps track of student id's
 
// Create two vectors to hold all students and student assignments 
std::vector<Student> StudentList;
std::vector<Assignments> StudentAssignments;

// int mainMenu();          // prototype for mainMenu()

   enum asnTypes {
       
       QUIZ = 1,
       EXAM,
       LAB,
       DISCUSSION,
       FINALEXAM,
       CUSTOM
   };
   std::string getAsnType (int asn){
   
       switch(asn) {
           case 1:
               return "Quiz";
               break;
           case 2:
               return "Exam";
               break;
           case 3:
               return "Lab";
               break;
           case 4:
               return "Discussion";
               break;
           case 5:
               return "Final Exam";
               break;
           case 6:
               return "Extra Credit";
               break;
           default:
               return "not implemented";
       }
       
   }

class findStudent {   

private:
    int position;     // Used to record position of search value 

   
public:
    
     /*
    void showStudent(vector<Student> &sList, vector<Assignments> &aList, int pos) {
  
    if (pos == -1) {
            cout << "Student not found!" << endl; 
        }
        else
        {
        
        displayStudents showStudents; // instantiate class
        // showStudents.dumpStudents(sList, aList, pos);
        
        std::cout << "\nID         : " << sList[pos].get_id();
        std::cout << "\nFirst name : " << sList[pos].get_firstName();
        std::cout << "\nLast name  : " << sList[pos].get_lastName();
        // std::cout << "\nGPA        : " << std::setprecision(3) << studentlist[len].get_gpa() << endl;
       
        
        } // end else
           
} //end dumpArr  
   */ // disabled member and expanded displaystudents to handle
    
 int search(vector<Student> &sList, vector<Assignments> &aList, int searchVal)
 {
     bool validselection = false;   
     int sID = -1;
     std::string sLast = "";
     std::string sFirst = "";
     double sTotgrade = 0.0;
     int selected = -1; // index of vector
     
     switch (searchVal) {
 
        case 1:            // Search for id
             std::cout << "Enter student ID to search for: ";
             std::cin >> sID;
              for (int i=0; i < sList.size(); i++) {

              if (sList[i].get_id() == sID) { // If the value is found
              position = i;      // Record the index of found id
              return position;
              break;
              } else { position = -1; }
             }
            return position;       // Return the found student position, or -1 not found
            break;
         
         /*
          * NEED TO ADD CODE FOR THE REMAINING CASE STATEMENTS
          *  DONE - 03/08/15 CLN
          * 
          */
         case 2:
             // std::cout << "DEBUG Case 2" << endl;
             std::cout << "Enter student's last name to search for: ";
             std::cin >> sLast;
              for (int i=0; i < sList.size(); i++) {

              if (sList[i].get_lastName() == sLast) { // If the value is found
              position = i;      // Record the index of found id
              return position;
              break;
              } else { position = -1; }
             }
            return position;       // Return the found student position, or -1 not found
            break;
            
         case 3:
             // std::cout << "DEBUG Case 3" << endl;
             std::cout << "Enter student's first name to search for: ";
             std::cin >> sFirst;
              for (int i=0; i < sList.size(); i++) {

              if (sList[i].get_firstName() == sFirst) { // If the value is found
              position = i;      // Record the index of found id
              return position;
              break;
              } else { position = -1; }
             }
            return position;       // Return the found student position, or -1 not found
            break;
            
         case 4:
             std::cout << "DEBUG Case 4" << endl;
             std::cout << "Enter student's total grade search for: ";
             std::cin >> sTotgrade;
              for (int i=0; i < sList.size(); i++) {

              if (aList[i].get_id() == sTotgrade) { // If the value is found
              position = i;      // Record the index of found id
              return position;
              break;
              } else { position = -1; }
             }
            return position;       // Return the found student position, or -1 not found
             break;
      default:
          // std::cout << "\nStudent not found!" << endl;
          return -1;
       }
     }  // End search()
 
}; // end findStudent class
   
class displayStudents {

private:
    int asnCntr;
public:
    void dumpStudents(vector<Student> &sList, vector<Assignments> &aList, int pos) {
        std::string asnType;       
        // pos -2 displays all students
        // pos -1 no student found
        // pos = x display x student
        if (sList.empty() != true) {
         
        if (pos == -2) {
        for (int i=0; i < sList.size(); i++) {
            std:: cout << "-----------------------------------------------------------------" << endl;
            std::cout << "\nID         : " << sList[i].get_id();
            std::cout << "\nFirst name : " << sList[i].get_firstName();
            std::cout << "\nLast name  : " << sList[i].get_lastName() << endl;
            
            std::cout << "\nAssignments for " << sList[i].get_firstName() << " " << sList[i].get_lastName() << endl;
             asnCntr = 0;
             
            for (int j=0; j < aList.size(); j++ ) {
             
                if (sList[i].get_id() == aList[j].get_id()) {
                    
                    asnType = getAsnType(aList[j].get_asnType()); // Determine assignment type
                    // asnTotal = Implement assignment total possible points based on asnType
                    
                    if (aList[j].get_grade1() != -1 ) {
                        asnCntr++;
                        std::cout << "Assignment # " << asnCntr << " - " << asnType << " - Grade : " << aList[j].get_grade1() << endl;
                    }
                    if (aList[j].get_grade2() != -1 ) {
                        asnCntr++;
                        std::cout << "Assignment # " << asnCntr << " - " << asnType << " - Grade : " << aList[j].get_grade2() << endl;
                    }
                    if (aList[j].get_grade3() != -1 ) {
                        asnCntr++;
                        std::cout << "Assignment # " << asnCntr << " - " << asnType << " - Grade : " << aList[j].get_grade3() << endl;
                    }
                    if (aList[j].get_grade4() != -1 ) {
                        asnCntr++;
                        std::cout << "Assignment # " << asnCntr << " - " << asnType << " - Grade : " << aList[j].get_grade4() << endl;
                    }
                    if (aList[j].get_grade5() != -1 ) {
                        asnCntr++;
                        std::cout << "Assignment # " << asnCntr << " - " << asnType << " - Grade : " << aList[j].get_grade5() << endl;
                    }
                             }
                
                  }
            std:: cout << "-----------------------------------------------------------------" << endl;
              }
            } else if (pos == -1) { std::cout << "\nStudent not found!" << endl; 
            
              } else 
              
              {  //std::cout << "DEBUG: Displaying found student!!!" << endl; 
                 std:: cout << "-----------------------------------------------------------------" << endl;
                 std::cout << "\nID         : " << sList[pos].get_id();
                 std::cout << "\nFirst name : " << sList[pos].get_firstName();
                 std::cout << "\nLast name  : " << sList[pos].get_lastName() << endl;
            
                 std::cout << "\nAssignments for " << sList[pos].get_firstName() << " " << sList[pos].get_lastName() << endl;
                 asnCntr = 0;
              
               for (int j=0; j < aList.size(); j++ ) {
             
                if (sList[pos].get_id() == aList[j].get_id()) {
                    
                    asnType = getAsnType(aList[j].get_asnType()); // Determine assignment type
                    // asnTotal = Implement assignment total possible points based on asnType
                    
                    if (aList[j].get_grade1() != -1 ) {
                        asnCntr++;
                        std::cout << "Assignment # " << asnCntr << " - " << asnType << " - Grade : " << aList[j].get_grade1() << endl;
                    }
                    if (aList[j].get_grade2() != -1 ) {
                        asnCntr++;
                        std::cout << "Assignment # " << asnCntr << " - " << asnType << " - Grade : " << aList[j].get_grade2() << endl;
                    }
                    if (aList[j].get_grade3() != -1 ) {
                        asnCntr++;
                        std::cout << "Assignment # " << asnCntr << " - " << asnType << " - Grade : " << aList[j].get_grade3() << endl;
                    }
                    if (aList[j].get_grade4() != -1 ) {
                        asnCntr++;
                        std::cout << "Assignment # " << asnCntr << " - " << asnType << " - Grade : " << aList[j].get_grade4() << endl;
                    }
                    if (aList[j].get_grade5() != -1 ) {
                        asnCntr++;
                        std::cout << "Assignment # " << asnCntr << " - " << asnType << " - Grade : " << aList[j].get_grade5() << endl;
                    }
                             }
                
                  }
              std:: cout << "-----------------------------------------------------------------" << endl;
            }
            
        } else { 
            std:: cout << "-----------------------------------------------------------------" << endl;
            std::cout << "No students found! Please add students from Main Menu." << endl;
            std:: cout << "-----------------------------------------------------------------" << endl;
           }
        system("PAUSE");
    }
}; // end displayStudents

class gradeEdit {

private:
    int index, gtype;
    
public:
   gradeEdit();
   gradeEdit(int init_index, int init_gtype);
   void set_index(int init_index) { index = init_index; }
   void set_gtype(int init_gtype) { gtype = init_gtype; }
   int get_index() { return index; }
   int get_gtype() { return gtype; }
};

// prototype
 gradeEdit::gradeEdit() {
     index = -1;
     gtype = -1;
 }   
 
 // prototype
 gradeEdit::gradeEdit(int init_index, int init_gtype){
     index = init_index;
     gtype = init_gtype;
 }
 
class editStudents {

private: 
    int asnCntr; // Used to enumerate assignments 
    std::string asnType;
    char doAgain;  // Y or N
  
public:
     std::vector<gradeEdit> asnIndex; // holds index of assignment and grade type
     //editStudents();        // Instantiate class
     void edit(vector<Student> &sList, vector<Assignments> &aList, int studentPos)  {

         do {
         std:: cout << "-------------------- [ STUDENT EDIT MENU ]----------------------" << endl;
                 std::cout << "\nID         : " << sList[studentPos].get_id();
                 std::cout << "\nFirst name : " << sList[studentPos].get_firstName();
                 std::cout << "\nLast name  : " << sList[studentPos].get_lastName() << endl;
            
                 std::cout << "\nAssignments for " << sList[studentPos].get_firstName() << " " << sList[studentPos].get_lastName() << endl;
                 asnCntr = 0;
               
               for (int j=0; j < aList.size(); j++ ) {
                    
                   if (sList[studentPos].get_id() == aList[j].get_id()) {
                       
                    asnType = getAsnType(aList[j].get_asnType()); // Determine assignment type
                 
                    // asnTotal = Implement assignment total possible points based on asnType
                    
                    if (aList[j].get_grade1() != -1 ) {
                        asnCntr++;
                        asnIndex.push_back(gradeEdit(j, 1));          
                        // cout << "DEBUG Displaying val in asnIndex " << asnIndex[asnCntr-1] << endl;
                        std::cout << "[" << asnCntr << "]" << " Assignment" << " - " << asnType << " - Grade : " << aList[j].get_grade1() << endl;
                    }
                    if (aList[j].get_grade2() != -1 ) {
                        asnCntr++;
                        asnIndex.push_back(gradeEdit(j, 2));  
                        std::cout << "[" << asnCntr << "]" << " Assignment" << " - " << asnType << " - Grade : " << aList[j].get_grade2() << endl;
                    }
                    if (aList[j].get_grade3() != -1 ) {
                        asnCntr++;
                        asnIndex.push_back(gradeEdit(j, 3));  
                        std::cout << "[" << asnCntr << "]" << " Assignment" << " - " << asnType << " - Grade : " << aList[j].get_grade3() << endl;
                    }
                    if (aList[j].get_grade4() != -1 ) {
                        asnCntr++;
                        asnIndex.push_back(gradeEdit(j, 4));  
                        std::cout << "[" << asnCntr << "]" << " Assignment" << " - " << asnType << " - Grade : " << aList[j].get_grade4() << endl;
                    }
                    if (aList[j].get_grade5() != -1 ) {
                        asnCntr++;
                        asnIndex.push_back(gradeEdit(j, 5));  
                        std::cout << "[" << asnCntr << "]" << " Assignment" << " - " << asnType << " - Grade : " << aList[j].get_grade5() << endl;
                    }
                       }
                             }
                 if (asnCntr > 0) {
                  // cout << "DEBUG: There are assignments to edit" << endl;
                
                   int selection = 0;
                   char editMore;    // Y/N
                   
                   do {
                   std::cout << "\nPlease enter assignment number from above to edit grade : ";
                   cin >> selection;
                   if (selection > 0 && selection <= asnCntr) {
                                           
                        } else { std::cout << "\nAssignment # " << selection << " does not exist!"; }
                   } while (selection == 0 || selection > asnCntr);            
                 
                   int newgrade = -1;
                   std::cout << "\nEnter new grade for assignment #" << selection << " : ";
                   std::cin >> newgrade;
                      
                       // change value in grade 1 field
                      // cout << "DEBUG: showing gtype : " << asnIndex[selection-1].get_gtype() << endl;
                      // cout << "DEBUG: showing index : " << asnIndex[selection-1].get_index() << endl;
                      if (asnIndex[selection-1].get_gtype() == 1) {               
                      std::cout << "\nOld grade for assignment # " << selection << " was : " << aList[asnIndex[selection-1].get_index()].get_grade1();   
                      aList[asnIndex[selection-1].get_index()].set_grade1(newgrade);
                      std::cout << "\nNew grade for assignment # " << selection << " is : " <<  aList[asnIndex[selection-1].get_index()].get_grade1();
                      }
                   
                     // change value in grade 2 field
                    if (asnIndex[selection-1].get_gtype() == 2) {               
                      std::cout << "\nOld grade for assignment # " << selection << " was : " << aList[asnIndex[selection-1].get_index()].get_grade2();   
                      aList[asnIndex[selection-1].get_index()].set_grade2(newgrade);
                      std::cout << "\nNew grade for assignment # " << selection << " is : " <<  aList[asnIndex[selection-1].get_index()].get_grade2();
                      }
                    // change value in grade 3 field
                    if (asnIndex[selection-1].get_gtype() == 3) {               
                      std::cout << "\nOld grade for assignment # " << selection << " was : " << aList[asnIndex[selection-1].get_index()].get_grade3();   
                      aList[asnIndex[selection-1].get_index()].set_grade3(newgrade);
                      std::cout << "\nNew grade for assignment # " << selection << " is : " <<  aList[asnIndex[selection-1].get_index()].get_grade3();
                      }
                    // change value in grade 4 field
                    if (asnIndex[selection-1].get_gtype() == 4) {               
                      std::cout << "\nOld grade for assignment # " << selection << " was : " << aList[asnIndex[selection-1].get_index()].get_grade4();   
                      aList[asnIndex[selection-1].get_index()].set_grade4(newgrade);
                      std::cout << "\nNew grade for assignment # " << selection << " is : " <<  aList[asnIndex[selection-1].get_index()].get_grade4();
                      }
                    // change value in grade 5 field
                    if (asnIndex[selection-1].get_gtype() == 5) {               
                      std::cout << "\nOld grade for assignment # " << selection << " was : " << aList[asnIndex[selection-1].get_index()].get_grade4();   
                      aList[asnIndex[selection-1].get_index()].set_grade4(newgrade);
                      std::cout << "\nNew grade for assignment # " << selection << " is : " <<  aList[asnIndex[selection-1].get_index()].get_grade4();
                      }
                   
                 } else {
                    
                 cout << "\nThere are no assignments to edit for " << sList[studentPos].get_firstName() << " " << sList[studentPos].get_lastName() << endl;
                 }
               
               
          cout << "\nChange grade points for another assignment (Y/N)? ";
          cin >> doAgain;
       }  while (doAgain == 'Y' || doAgain == 'y');
     
       std:: cout << "\n-----------------------------------------------------------------" << endl;
     } // end edit
     
}; //end editStudents class

void addStudents(vector<Student> &sList, vector<Assignments> &aList) {
   
   char doAgain;              // Y or N
   char final;                // Y or N
   std::string lName = "";
   std::string fName = "";
   int quizQty = -1;
   int examQty = -1;
   int labQty = -1;
   int disQty = -1;
   int finalPnts = -1;
   const int ARRSIZE = 5;
   int quizArr[ARRSIZE];
   int examArr[ARRSIZE];
   int labArr[ARRSIZE];
   int disArr[ARRSIZE];
   int custArr[ARRSIZE];
    // vector<int> quizVect(5);
    // std::fill(quizVect.begin(), quizVect.end(), -1);   
      
   do {
       
       studentcnt++; // increments student ID (static var)
       // resets arrays back to default value of -1 for while loop
       std::fill(quizArr, quizArr + ARRSIZE, -1); 
       std::fill(examArr, examArr + ARRSIZE, -1);
       std::fill(labArr, labArr + ARRSIZE, -1); 
       std::fill(disArr, disArr + ARRSIZE, -1); 
       
       std::cout << "Student ID: " << studentcnt;
       std::cout << "\nEnter student's Last Name: ";
       std::cin >> lName;
       std::cout << "Enter student's First Name: ";
       std::cin >> fName;
       sList.push_back(Student(studentcnt, lName, fName));  // populates StudentList vector    
       
       //quizzes
       do {
       std::cout << "How many quizzes did " << fName << " " << lName << " take? Enter [0-5]: ";
       std::cin >> quizQty;
       if (quizQty < 0 || quizQty > 5) { std::cout << "\nInvalid input. Please enter a number between 0 and 5" << endl; }
       } while (!cin.fail() && quizQty < 0 || quizQty > 5);
       
       if (quizQty > 0 && quizQty <= 5 && !cin.fail()){
           
            /*
             * 
             * NEED TO PUT SOME INPUT VALIDATION TO TEST VALID ENTRY FOR POINT RANGE
             * FOR EACH TYPE OF ASSIGNMENT.   
             * 
             * DONE CLN 03/08/15
             *          
             */
            for (int i=0; i < quizQty; i++ ) {
                //int quizScore = -1;
                do {
                std::cout << "Points for Quiz # " << i+1 << ". Enter [0-10]: ";
                std:: cin >> quizArr[i];
                //std::cin >> quizScore;
                if (quizArr[i] < 0 || quizArr[i] > 10 ) { std::cout << "\nInvalid input. Please enter a number between 0 and 10" << endl; }
                } while (!cin.fail() && quizArr[i] < 0 || quizArr[i] > 10); 
                }  
            // Populate quizzes for the student
        aList.push_back(Assignments(studentcnt, QUIZ, quizArr[0], quizArr[1], quizArr[2], quizArr[3], quizArr[4]));
           // aList.push_back(Assignments.set_id(studentcnt), Assignments.set_asnType(QUIZ), Assignments.set_grade1(quizArr[0]), Assignments.set_grade2(quizArr[1]), Assignments.set_grade3(quizArr[2]), Assignments.set_grade4(quizArr[3]), Assignments.set_grade5(quizArr[4]));
            
       } // end if
       
        // exams
       do {
       std::cout << "How many exams did " << fName << " " << lName << " take? Enter [0-5]: ";
       std::cin >> examQty;
       if (examQty < 0 || examQty > 5) { std::cout << "\nInvalid input. Please enter a number between 0 and 5" << endl; }
       } while (!cin.fail() && examQty < 0 || examQty > 5);
        
       if (examQty > 0 && examQty <= 5 && !cin.fail()){
                
            for (int i=0; i < examQty; i++ ) {
                do {
                std::cout << "Points for Exam # " << i+1 << ". Enter [0-50]: ";
                std:: cin >> examArr[i]; 
                if (examArr[i] < 0 || examArr[i] > 50 ) { std::cout << "\nInvalid input. Please enter a number between 0 and 50" << endl; }
                } while (!cin.fail() && examArr[i] < 0 || examArr[i] > 50); 
            } 
            // Populate exams for the student
        aList.push_back(Assignments(studentcnt, EXAM, examArr[0], examArr[1], examArr[2], examArr[3], examArr[4]));
       } // end if
       //quizzes end
               
       /* 
        * 
        * NEED TO ADD CODE FOR ADDITIONAL ASSIGNMENT TYPES PER USER INTERFACE PDF
        * 
        * DONE 03/08/15 CLN 
        *
        */
       
        // labs
       do {
       std::cout << "How many labs did " << fName << " " << lName << " take? Enter [0-5]: ";
       std::cin >> labQty;
       if (labQty < 0 || labQty > 5) { std::cout << "\nInvalid input. Please enter a number between 0 and 5" << endl; }
       } while (!cin.fail() && labQty < 0 || labQty > 5);
        
       if (labQty > 0 && labQty <= 5 && !cin.fail()){
                
            for (int i=0; i < labQty; i++ ) {
                do {
                std::cout << "Points for Lab # " << i+1 << ". Enter [0-20]: ";
                std:: cin >> labArr[i]; 
                if (labArr[i] < 0 || labArr[i] > 20 ) { std::cout << "\nInvalid input. Please enter a number between 0 and 20" << endl; }
                } while (!cin.fail() && labArr[i] < 0 || labArr[i] > 20); 
            } 
            // Populate labs for the student
        aList.push_back(Assignments(studentcnt, LAB, labArr[0], labArr[1], labArr[2], labArr[3], labArr[4]));
       } // end if
       // labs end
       
       // discussions
       do {
       std::cout << "How many discussions did " << fName << " " << lName << " take? Enter [0-5]: ";
       std::cin >> disQty;
       if (disQty < 0 || disQty > 5) { std::cout << "\nInvalid input. Please enter a number between 0 and 5" << endl; }
       } while (!cin.fail() && disQty < 0 || disQty > 5);
        
       if (disQty > 0 && disQty <= 5 && !cin.fail()){
                
            for (int i=0; i < disQty; i++ ) {
                do {
                std::cout << "Points for discussion # " << i+1 << ". Enter [0-10]: ";
                std:: cin >> disArr[i]; 
                if (disArr[i] < 0 || disArr[i] > 10 ) { std::cout << "\nInvalid input. Please enter a number between 0 and 10" << endl; }
                } while (!cin.fail() && disArr[i] < 0 || disArr[i] > 10); 
            } 
            // Populate discussions for the student
        aList.push_back(Assignments(studentcnt, DISCUSSION, disArr[0], disArr[1], disArr[2], disArr[3], disArr[4]));
       } // end if
       // discussions end
       
       // final exam
       std::cout << "Did " << fName << " " << lName << " take the final exam (Y/N)? ";
       std::cin >> final;
       if (!cin.fail() && final == 'Y' || final == 'y') {
                      
          do {
                std::cout << "Points for the final exam. Enter [0-200]: ";
                std:: cin >> finalPnts;
                if (finalPnts < 0 || finalPnts > 200 ) { std::cout << "\nInvalid input. Please enter a number between 0 and 200" << endl; }
            } while (!cin.fail() && finalPnts < 0 || finalPnts > 200); 
            // Populate exams for the student
        aList.push_back(Assignments(studentcnt, FINALEXAM, finalPnts, -1, -1, -1, -1));
       }
    
       // final exam end
       
    cout << "\nAdd another student (Y/N)? ";
    cin >> doAgain;
    }  while (doAgain == 'Y' || doAgain == 'y');
} // end addStudents


int mainMenu() {
    
    int mainSelect = -1;
    displayStudents showStudents; // instantiate class
   
    do {    
    // Main Menu
    std::cout << "\nWelcome to Whiteboard!\n\n";
    std::cout << "[1] List all students" << endl;
    std::cout << "[2] Search for a student" << endl;
    std::cout << "[3] Add a new student" << endl;
    std::cout << "[4] Exit Whiteboard\n" << endl;
    std::cout << "Please make selection from above. Enter [1-4]: ";
    
    std::cin >> mainSelect;
    
    int searchChoice = 0;
    int editChoice = 0;
    switch (mainSelect) {
       
        case 1: 
            // std::cout << "\nDebug: Entered 1" << endl;         
            showStudents.dumpStudents(StudentList, StudentAssignments, -2); // -2 = show all students
            break;
        case 2:
            // std::cout << "\nDebug: Entered 2" << endl;     
            if (StudentList.empty() != true) {
            do {
                findStudent searchStudent; // instantiate class
                int foundStudent = -1;      // index in vector of found student
                std::cout << "\nSearch Menu" << endl;
                std::cout << "[1] Search by the student ID" << endl;
                std::cout << "[2] Search by the student's last name" << endl;
                std::cout << "[3] Search by the student's first name" << endl;
                std::cout << "[4] Search by the student's total grade" << endl;
                std::cout << "[5] Return to Main Menu" << endl;
                
                do {
                std::cout << "\nPlease make selection from above. Enter [1-5]: ";
                cin >> searchChoice;
                if (searchChoice < 1 || searchChoice > 5) { std::cout << "\nInvalid input. Please enter a number between 1 and 5." << endl; }
                } while (!cin.fail() && searchChoice < 1 || searchChoice > 5);
                if (searchChoice == 5) { break; }
                foundStudent = searchStudent.search(StudentList, StudentAssignments, searchChoice);
                // searchStudent.showStudent(StudentList, StudentAssignments, foundStudent); // displays student info found  by search
                showStudents.dumpStudents(StudentList, StudentAssignments, foundStudent);
                // cout << "\nDEBUG index of student found is: " << foundStudent << endl;
           
            } while (!cin.fail() && searchChoice !=5);
            } else { std::cout << "There are no students. Please add students from Main Menu." << endl; }
            break;
        case 3:
            // std::cout << "\nDebug: Entered 3" << endl;
            addStudents(StudentList, StudentAssignments);
            break;
        case 4:
            std::cout << "\nExiting Whiteboard" << endl;
            return 2;
            break;
        case 20966:
            std::cout << "\n***** ENTERING BACKDOOR!!! *****" << endl;
            if (StudentList.empty() != true) {
                std::cout << "\nEdit Student Grades Menu" << endl;
                std::cout << "[1] Search by the student ID" << endl;
                std::cout << "[2] Return to the Main Menu" << endl;
                
                do {
                std::cout << "\nPlease make selection from above. Enter [1 or 2]: ";
                cin >> editChoice;
                if (editChoice < 1 || editChoice > 2) { std::cout << "\nInvalid input. Please enter a number between 1 and 2." << endl; }
                } while (!cin.fail() && editChoice < 1 || editChoice > 2);
              if (editChoice == 2) { break; }   
                findStudent searchStudent; // instantiate class
                editStudents modGrade;     // instantiate class
                int foundStudent = -1;      // index in vector of found student
                foundStudent = searchStudent.search(StudentList, StudentAssignments, editChoice); // find the student
                // showStudents.dumpStudents(StudentList, StudentAssignments, foundStudent); // display results
                modGrade.edit(StudentList, StudentAssignments, foundStudent);
            } else { std::cout << "There are no students. Please add students from Main Menu." << endl; }
            
            /*
             * 
             * BACKDOOR MENU NEEDS TO BE CREATED
             *  DONE 03/08/15 CLN
             * 
             */
            break;
        default:
           std::cout << "Invalid selection, please enter an integer between 1 - 4" << endl; 
    }
} while (mainSelect != 4 && !cin.fail());       
}


int main() {
    int callMenu = 0;
    
    while (callMenu == 0 ) {
        callMenu = mainMenu();
    }
     
     system("PAUSE");
     std::cout << "Written by Chad Netwig, Paul Liverman, and Erik Montgomery" << endl;
     return EXIT_SUCCESS;

}

