#ifndef STUDENTTESTS_H_INCLUDED
#define STUDENTTESTS_H_INCLUDED

#include "UnitTest++.h"
#include "Student.h"

SUITE(StudentTests)
{
    TEST(constructorsTest)
    {
        Student student = Student();
        CHECK_EQUAL("VOID", student.get_firstName());
        CHECK_EQUAL("VOID", student.get_lastName());
        CHECK_EQUAL(-1, student.get_id());
    }
    /*
class Student{
    private:
        int id;
        std::string lastName;
        std::string firstName;
    public:
        Student();
        Student(int init_id, std::string init_lastName, std::string init_firstName);
        // setters
        //void set_id(int init_id){ id = init_id; }
        //void set_lastName(std::string init_lastName){ lastName = init_lastName; }
        //void set_firstName(std::string init_firstName){ firstName = init_firstName; }

        // getters
        int get_id(){ return id; }
        std::string get_lastName(){ return lastName; }
        std::string get_firstName(){ return firstName; }

};
    */
}

#endif // STUDENTTESTS_H_INCLUDED
