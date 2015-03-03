#include "Student.h"

using namespace std;

Student::Student() {

    id        = -1;
    lastName  = "VOID";
    firstName = "VOID";

}

Student::Student(int init_id, string init_lastName, string init_firstName) {

    id        = init_id;
    lastName  = init_lastName;
    firstName = init_firstName;

}
