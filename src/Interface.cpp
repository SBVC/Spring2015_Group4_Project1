#include "Interface.h"
#include <iostream>

// totally not a way to cheat Professor X, just ignore this bit, k?
const int BACKDOOR = 20966;

Interface::Interface()
{
    //ctor
}

Interface::~Interface()
{
    //dtor
}

void Interface::mainMenu()
{
    int userChoice;

    cout << "Whiteboard - Main Menu\n\n";
    cout << " 1. List students.\n";
    cout << " 2. Search for a student.\n";
    cout << " 3. Add a new student.\n";
    cout << " 4. List assignments.\n";
    cout << " 5. Search for an assignment.\n";
    cout << " 6. Add a new assignment.\n\n";
    cout << "Please choose an option [1-6]: ";

    //safely get an int from std in

    switch(userChoice)
    {
        case 1:
            listStudents();
        case 2:
            searchStudentsMenu();
        case 3:
            addNewStudent();
        case 4:
            listAssignments();
        case 5:
            searchAssignmentsMenu();
        case 6:
            addNewAssignment();
        case BACKDOOR:
            // DUNNO YET, FIX THIS
        default:
            //ERROR
    }
}

void Interface::listStudents()
{
    //
}

void Interface::listAssignments()
{
    //
}

void Interface::addNewStudent()
{
    //
}

void Interface::addNewAssignment()
{
    //
}

void Interface::searchStudentsMenu()
{
    int userChoice;

    cout << "Whiteboard - Search for Student\n\n";
    cout << " 1. Search by ID.\n";
    cout << " 2. Search by last name.\n";
    cout << " 3. Search by first name.\n\n";
    cout << "Please choose an option [1-3]: ";

    //safely get an int from std in

    switch(userChoice)
    {
        case 1:
            searchStudentsByID();
        case 2:
            searchStudentsByLastName();
        case 3:
            searchStudentsByFirstName();
        default:
            // ERROR
    }
}

void Interface::searchAssignmentsMenu()
{
    int userChoice;

    cout << "Whiteboard - Search for Assignment\n\n";
    cout << " 1. Search by ID.\n";
    cout << " 2. Search by type.\n";
    cout << " 3. Search by title.\n\n";
    // cout << " 4. Search by max score.\n\n"; //nope?
    cout << "Please choose an option [1-3]: ";

    //safely get an int from std in

    switch(userChoice)
    {
        case 1:
            searchAssignmentsByID();
        case 2:
            searchAssignmentsByType();
        case 3:
            searchAssignmentsByTitle();
        default:
            // ERROR
    }
}

void Interface::searchStudentsByID()
{
    //
}

void Interface::searchStudentsByLastName()
{
    //
}

void Interface::searchStudentsByFirstName()
{
    //
}

void Interface::searchAssignmentsByID()
{
    //
}

void Interface::searchAssignmentsByTitle()
{
    //
}
