#ifndef ASSIGNMENTS_H_INCLUDED
#define ASSIGNMENTS_H_INCLUDED

#include <string>

class Assignments {
private:
    int aId, assignType, grade1, grade2, grade3, grade4, grade5;
public:
    Assignments();
    Assignments(int init_id, int init_assignType, int init_grade1, int init_grade2, int init_grade3, int init_grade4, int init_grade5 );

    // getters
    int get_id() { return aId; }
    int get_asnType() { return assignType; }
    int get_grade1() { return grade1; }
    int get_grade2() { return grade2; }
    int get_grade3() { return grade3; }
    int get_grade4() { return grade4; }
    int get_grade5() { return grade5; }
};

#endif // ASSIGNMENTS_H_INCLUDED
