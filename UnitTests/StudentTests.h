#ifndef STUDENTTESTS_H_INCLUDED
#define STUDENTTESTS_H_INCLUDED

#include "UnitTest++.h"
#include "Student.h"
#include "Student.cpp"
#include <string>

using namespace std;

SUITE(StudentTests)
{
    TEST(constructorsTest) // TEST DEPENDS ON ORDER OF TESTS RUN, leave it here
    {
        string lastName = "Last Name";
        string firstName = "First Name";
        int stupidID = -1337;

        Student student = Student(); // "invalid" constructor
        CHECK_EQUAL(Student::defaultFirstName, student.get_firstName());
        CHECK_EQUAL(Student::defaultLastName, student.get_lastName());
        CHECK_EQUAL(Student::defaultID, student.get_id());

        Student student2 = Student(lastName, firstName);
        CHECK_EQUAL(firstName, student2.get_firstName());
        CHECK_EQUAL(lastName, student2.get_lastName());
        CHECK_EQUAL(0, student2.get_id()); // this depends on this being the first constructed Student that is 'valid'

        // DEPRECATED
        Student student3 = Student(stupidID, lastName, firstName);
        CHECK_EQUAL(firstName, student3.get_firstName());
        CHECK_EQUAL(lastName, student3.get_lastName());
        CHECK_EQUAL(stupidID, student3.get_id());
    }

    TEST(idAssignmentsTest) // TEST DEPENDS ON ORDER OF TESTS, do not move
    {
        string bogus = "Bogus Name Stuff";

        Student student1 = Student(bogus, bogus);
        Student student2 = Student(bogus, bogus);
        Student student3 = Student(bogus, bogus);

        CHECK_EQUAL(1, student1.get_id());
        CHECK_EQUAL(2, student2.get_id());
        CHECK_EQUAL(3, student3.get_id());

        CHECK_EQUAL("s1", student1.get_namedID());
        CHECK_EQUAL("s2", student2.get_namedID());
        CHECK_EQUAL("s3", student3.get_namedID());
    }

    TEST(getIDTest) // TEST DEPENDS ON ORDER OF TESTS, do not move
    {
        string bogus = "Bogus Name Stuff";

        Student student4 = Student(bogus, bogus);
        CHECK_EQUAL(4, student4.get_id());
    }

    TEST(getNamedIDTest) // TEST DEPENDS ON ORDER OF TESTS, do not move
    {
        string bogus = "Bogus Name Stuff";

        Student student5 = Student(bogus, bogus);
        CHECK_EQUAL("s5", student5.get_namedID());
    }

    TEST(getLastNameTest)
    {
        Student student = Student();
        CHECK_EQUAL(Student::defaultLastName, student.get_lastName());
    }

    TEST(getFirstNameTest)
    {
        Student student = Student();
        CHECK_EQUAL(Student::defaultFirstName, student.get_firstName());
    }

    TEST(setLastNameTest)
    {
        string lastName = "Last Name";

        Student student = Student();
        student.set_lastName(lastName);
        CHECK_EQUAL(lastName, student.get_lastName());
    }

    TEST(setFirstNameTest)
    {
        string firstName = "First Name";

        Student student = Student();
        student.set_firstName(firstName);
        CHECK_EQUAL(firstName, student.get_firstName());
    }
}

#endif // STUDENTTESTS_H_INCLUDED
