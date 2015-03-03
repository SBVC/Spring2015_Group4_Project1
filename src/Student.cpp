#include "Student.h"
#include <sstream>
#include <iostream>

using namespace std;

int Student::nextID = 0;

const int Student::defaultID = -1;
const string Student::defaultLastName = "VOID";
const string Student::defaultFirstName = "VOID";

Student::Student() {

    id        = defaultID;
    lastName  = defaultLastName;
    firstName = defaultFirstName;

}

Student::Student(string init_lastName, string init_firstName) {

    id        = get_nextID();
    lastName  = init_lastName;
    firstName = init_firstName;

}

string Student::get_namedID() {

    stringstream convert;
    convert << "s" << id;
    return convert.str();

}

// DEPRECATED
Student::Student(int init_id, string init_lastName, string init_firstName) {

    // Log to say it is deprecated.
    clog << "Student s" << init_id << " is using deprecated Student constructor. Please use the version that sets an ID automatically." << endl;
    id        = init_id;
    lastName  = init_lastName;
    firstName = init_firstName;

}
