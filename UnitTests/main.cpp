#include <iostream>
#include "UnitTest++.h"
#include "Assignment.h"
//#include "Assignment.cpp" // WHY
#include "AssignmentType.h"

using namespace std;

namespace
{
    TEST(AssignmentGetIDTest)
    {
        // THIS ONLY WORKS IF IT IS FIRST
        Assignment assignment = Assignment();
        CHECK_EQUAL("a0", assignment.getID());
    }

    //*
    TEST(AssignmentGetRawIDTest)
    {
        // THIS ONLY WORKS IF IT IS SECOND
        Assignment assignment = Assignment();
        CHECK_EQUAL(1, assignment.getRawID());
    }
    //*/

    TEST(AssignmentInitializeTest)
    {
        Assignment invalidAssignment = Assignment();
        Assignment simpleAssignment = Assignment("Simple Title"); // doesn't exist
        Assignment simpleAssignment2 = Assignment("Simpler Title", "Custom Type"); //doesn't exist
        Assignment simpleAssignment3 = Assignment("Simplest Title", 100); //doesn't exist
        Assignment assignment = Assignment("Title", "Type", 100);
        CHECK_EQUAL("Title", assignment.getTitle());
        CHECK_EQUAL("Type", assignment.getType());
        CHECK_EQUAL(100, assignment.getMaxScore());
    }

    TEST(AssignmentGetMaxScoreTest)
    {
        Assignment assignment = Assignment();
        CHECK_EQUAL(100, assignment.getMaxScore());
    }

    TEST(AssignmentSetMaxScoreTest)
    {
        Assignment assignment = Assignment();
        assignment.setMaxScore(10);
        CHECK_EQUAL(10, assignment.getMaxScore());
    }

    TEST(AssignmentGetTitleTest)
    {
        Assignment assignment = Assignment();
        CHECK_EQUAL("Title", assignment.getTitle());
    }

    TEST(AssignmentGetTypeTest)
    {
        //we test both a custom (invalid)
        // and quiz (one of the enumerated types)
        Assignment invalidAssignment = Assignment();
        CHECK_EQUAL("Invalid", invalidAssignment.getType());
        Assignment quizAssignment = Assignment("Some Title", "Quiz");
        CHECK_EQUAL("Quiz", quizAssignment.getType());
    }

    TEST(AssignmentSetTypeTest)
    {
        string custom = "More Custom 2.0";
        Assignment invalidAssignment = Assignment();
        invalidAssignment.setType(custom);
        CHECK_EQUAL(custom, invalidAssignment.getType());
        invalidAssignment.setType(Discussion);
        CHECK_EQUAL("Discussion", invalidAssignment.getType());
    }
}

int main()
{
    return UnitTest::RunAllTests();
}
