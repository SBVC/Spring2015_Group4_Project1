#include "Assignments.h"

using namespace std;

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
