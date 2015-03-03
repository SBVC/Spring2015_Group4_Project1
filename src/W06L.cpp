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
 * 1) INPUT VALIDATION NEEDS TO BE IMPLEMENTED FOR POINT RANGES FOR EACH TYPE OF ASSIGNMENT. IE. QUIZZES, EXAMS, ETC.
 * 2) NEED TO CONTINUE ADDING ASSIGNMENT TYPES TO ADDSTUDENTS CLASS PER USER INTERFACE PDF
 * 3) FINDSTUDENT CLASS NEEDS TO BE FINISHED TO SEARCH FOR THE VARIOUS CASE STATEMENTS THEREIN
 * 4) NEED TO IMPLEMENT A FUNCTION TO DETERMINE THE MAX POINTS POSSIBLE FOR EACH ASSIGNMENT TYPE SO THIS CAN LATER
 *    BE USED TO CALCULATE TOTAL GRADE
 * 5) THE BACKDOOR MENU STILL NEEDS TO BE DONE
 * 7) STUDENT EDIT MENU NEEDS TO BE CREATED TO CHANGE VALUES IN STUDENTASSIGNMENTS VECTOR
 * 8) INSTEAD OF USING REDUDANT CODE (LIKE IT IS NOW) IN SHOWSTUDENT METHOD WITHIN FINDSTUDENT CLASS, NEED TO EXPAND
 *    DISPLAYSTUDENTS CLASS TO ACCEPT A SINGLE INDEX INSIDE STUDENTLIST VECTOR. THIS WAY A PARTICULAR STUDENT THAT IS
 *    SEARCHED FOR EITHER THROUGH THE SEARCH STUDENTS MENU OR A STUDENT ID THROUGH THE BACKDOOR MENU CAN BE DISPLAYED.
 *    THEN SHOWSTUDENT CAN BE ELIMINATED. AS IT STANDS NOW, DISPLAYSTUDENTS DUMPS ENTIRE STUDENTLIST VECTOR.
 * 9) FINAL THOUGHT: THERE ARE SEVERAL WAYS TO ACCOMPLISH THIS PROJECT. BUT WHAT IS HERE IS A PLATFORM THAT
 *    SHOULD PROVE TO GET THE JOB DONE. IN OTHER WORDS, LET'S CONTINUE WITH WHAT WE HAVE RATHER THAN TAKING ON
 *    MAJOR RESTRUCTURING OF THE CODE. WE'RE CLOSE, I HOPE YOU GUYS LIKE IT.
 * 10) MORE STUFF (BUGS) THAT I'M TOO TIRED TO THINK OF RIGHT NOW :)
 *
 *
 */

using namespace std;
static int studentcnt = 0;  // Keeps track of student id's

// Create two vectors to hold all students and student assignments
vector<Student> StudentList;
vector<Assignments> StudentAssignments;

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
               return "not implemented";
               break;
           default:
               return "undetermined";
       }

   }

class findStudent {

private:
    int position;     // Used to record position of search value

public:
    void showStudent(vector<Student> &sList, int pos) {

    if (pos == -1) {
            cout << "Student not found!" << endl;
        }
        else
        {

        std::cout << "\nID         : " << sList[pos].get_id();
        std::cout << "\nFirst name : " << sList[pos].get_firstName();
        std::cout << "\nLast name  : " << sList[pos].get_lastName();
        // std::cout << "\nGPA        : " << std::setprecision(3) << studentlist[len].get_gpa() << endl;
        } // end else

} //end dumpArr

 int search(vector<Student> &sList, vector<Assignments> &aList, int searchVal)
 {
     bool validselection = false;
     int sID = -1;
     std::string sLast = "";
     std::string sFirst = "";
     double totGrade = 0.0;
     int selected = -1; // index of vector

     switch (searchVal) {

        case 1:            // Search for id
             std::cout << "Enter student ID to search for: ";
             std::cin >> sID;
              for (int i=0; i < sList.size(); i++) {

              if (sList[i].get_id() == sID) { // If the value is found
              position = i;      // Record the index of found id
                 }
             }
            return position;       // Return the found student position, or -1 not found
            break;

         /*
          * NEED TO ADD CODE FOR THE REMAINING CASE STATEMENTS
          *
          *
          */
         case 2:
             std::cout << "DEBUG Case 2" << endl;
             break;
         case 3:
              std::cout << "DEBUG Case 3" << endl;
             break;
         case 4:
              std::cout << "DEBUG Case 4" << endl;
             break;
      default:
          std::cout << "\nStudent not found!" << endl;
          return -1;
    }

 }// End search

}; // end findStudent

class displayStudents {

private:
    int asnCntr;
public:
    void dumpStudents(vector<Student> &sList, vector<Assignments> &aList) {
        std::string asnType;

        for (int i=0; i < sList.size(); i++) {
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

            }
    }
}; // end displayStudents


void addStudents(vector<Student> &sList, vector<Assignments> &aList) {

   char doAgain;              // Y or N
   std::string lName = "";
   std::string fName = "";
   int quizQty = -1;
   int examQty = -1;
   const int ARRSIZE = 5;
   int quizArr[ARRSIZE];
   int examArr[ARRSIZE];
    // vector<int> quizVect(5);
    // std::fill(quizVect.begin(), quizVect.end(), -1);

   do {

       studentcnt++; // increments student ID (static var)
       // resets arrays back to default value of -1 for while loop
       std::fill(quizArr, quizArr + ARRSIZE, -1);
       std::fill(examArr, quizArr + ARRSIZE, -1);

       std::cout << "Student ID: " << studentcnt;
       std::cout << "\nEnter student's Last Name: ";
       std::cin >> lName;
       std::cout << "Enter student's First Name: ";
       std::cin >> fName;
       sList.push_back(Student(studentcnt, lName, fName));  // populates StudentList vector
       std::cout << "How many quizzes did " << fName << " " << lName << " take? Enter [0-5]: ";
       std::cin >> quizQty;

       if (quizQty > 0 && quizQty <= 5){

            /*
             *
             * NEED TO PUT SOME INPUT VALIDATION TO TEST VALID ENTRY FOR POINT RANGE
             * FOR EACH TYPE OF ASSIGNMENT.
             *
             *
             *
             */
            for (int i=0; i < quizQty; i++ ) {
                //int quizScore = -1;
                std::cout << "Points for Quiz # " << i+1 << ". Enter [0-10]: ";
                std:: cin >> quizArr[i];
                //std::cin >> quizScore;

                }
            // Populate quizzes for the student
        aList.push_back(Assignments(studentcnt, QUIZ, quizArr[0], quizArr[1], quizArr[2], quizArr[3], quizArr[4]));
       } // end if

       std::cout << "How many exams did " << fName << " " << lName << " take? Enter [0-5]: ";
       std::cin >> examQty;
        if (quizQty > 0 && quizQty <= 5){


            for (int i=0; i < examQty; i++ ) {
                std::cout << "Points for Exam # " << i+1 << ". Enter [0-50]: ";
                std:: cin >> examArr[i];
            }
            // Populate exams for the student
        aList.push_back(Assignments(studentcnt, EXAM, examArr[0], examArr[1], examArr[2], examArr[3], examArr[4]));
       } // end if

       /*
        *
        * NEED TO ADD CODE FOR ADDITIONAL ASSIGNMENT TYPES PER USER INTERFACE PDF
        *
        *
        *
        *
        */

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
    switch (mainSelect) {

        case 1:
            std::cout << "\nDebug: Entered 1" << endl;
            showStudents.dumpStudents(StudentList, StudentAssignments);
            break;
        case 2:
            std::cout << "\nDebug: Entered 2" << endl;
            do {
                findStudent searchStudent; // instantiate class
                int foundStudent = -1;      // index in vector of found student
                std::cout << "\nSearch Menu" << endl;
                std::cout << "[1] Search by the student ID" << endl;
                std::cout << "[2] Search by the student's last name" << endl;
                std::cout << "[3] Search by the student's first name" << endl;
                std::cout << "[4] Search by the student's total grade" << endl;
                std::cout << "[5] Return to Main Menu" << endl;
                std::cout << "Please make selection from above. Enter [1-5]: ";
                cin >> searchChoice;
                foundStudent = searchStudent.search(StudentList, StudentAssignments, searchChoice);
                searchStudent.showStudent(StudentList, foundStudent); // displays student info found  by search
                cout << "\nDEBUG index of student found is: " << foundStudent << endl;
            } while (!cin.fail() && searchChoice !=5);

            break;
        case 3:
            std::cout << "\nDebug: Entered 3" << endl;
            addStudents(StudentList, StudentAssignments);
            break;
        case 4:
            std::cout << "\nExiting Whiteboard" << endl;
            return 2;
            break;
        case 20966:
            std::cout << "\n***** ENTERING BACKDOOR!!! *****" << endl;
            /*
             *
             *
             *
             *
             * BACKDOOR MENU NEEDS TO BE CREATED
             *
             *
             */
            break;
        default:
           std::cout << "Invalid selection, please enter an integer between 1 - 4" << endl;
    }
} while (mainSelect != 4 && !cin.fail());
}

/*
int main() {
    int callMenu = 0;

    while (callMenu == 0 ) {
        callMenu = mainMenu();
    }

     system("PAUSE");
     return EXIT_SUCCESS;

}
*/

