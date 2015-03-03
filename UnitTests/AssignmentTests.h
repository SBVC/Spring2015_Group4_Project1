#ifndef ASSIGNMENTTESTS_H_INCLUDED
#define ASSIGNMENTTESTS_H_INCLUDED

#include "UnitTest++.h"
#include "Assignment.h"
#include "Assignment.cpp"
#include "AssignmentType.h"

using namespace std;

SUITE(AssignmentTests)
{
    // Test getID method.
    TEST(getIDTest) //only works if first test DO NOT CHANGE ORDER
    {
        Assignment assignment = Assignment(); // default (invalid) assignment
        CHECK_EQUAL("a0", assignment.getID());// should be ID a0 since it is first assignment
    }

    // Test getRawID method.
    TEST(getRawIDTest) //only works if second test DO NOT CHANGE ORDER
    {
        Assignment assignment = Assignment(); // default (invalid) again
        CHECK_EQUAL(1, assignment.getRawID());// should be 1 since it is second assignment
    }

    // Test if IDs are being assigned in order properly.
    TEST(idAssignmentsTest) //only works if third test DO NOT CHANGE ORDER
    {
        Assignment a2 = Assignment();
        Assignment a3 = Assignment();
        Assignment a4 = Assignment();
        CHECK_EQUAL("a2", a2.getID());
        CHECK_EQUAL("a3", a3.getID());
        CHECK_EQUAL("a4", a4.getID());
        CHECK_EQUAL(2, a2.getRawID());
        CHECK_EQUAL(3, a3.getRawID());
        CHECK_EQUAL(4, a4.getRawID());
    }

    // Tests ALL constructor forms.
    TEST(constructorsTest)
    {
        string title = "Custom Title";
        string customType = "Custom Type";
        unsigned int maxScore = 10;

        Assignment invalidAssignment = Assignment();
        CHECK_EQUAL(Assignment::defaultTitle, invalidAssignment.getTitle());
        CHECK_EQUAL(Assignment::defaultCustomType, invalidAssignment.getType());
        CHECK_EQUAL(Assignment::defaultMaxScore, invalidAssignment.getMaxScore());

        Assignment simpleAssignment = Assignment(title);
        CHECK_EQUAL(title, simpleAssignment.getTitle());
        CHECK_EQUAL(Assignment::defaultCustomType, simpleAssignment.getType());
        CHECK_EQUAL(Assignment::defaultMaxScore, simpleAssignment.getMaxScore());

        Assignment simpleAssignment2 = Assignment(title, customType);
        CHECK_EQUAL(title, simpleAssignment2.getTitle());
        CHECK_EQUAL(customType, simpleAssignment2.getType());
        CHECK_EQUAL(Assignment::defaultMaxScore, simpleAssignment2.getMaxScore());

        Assignment simpleAssignment3 = Assignment(title, maxScore);
        CHECK_EQUAL(title, simpleAssignment3.getTitle());
        CHECK_EQUAL(Assignment::defaultCustomType, simpleAssignment3.getType());
        CHECK_EQUAL(maxScore, simpleAssignment3.getMaxScore());

        Assignment assignment = Assignment(title, customType, maxScore);
        CHECK_EQUAL(title, assignment.getTitle());
        CHECK_EQUAL(customType, assignment.getType());
        CHECK_EQUAL(maxScore, assignment.getMaxScore());
    }

    // Test getMaxScore method.
    TEST(getMaxScoreTest)
    {
        Assignment assignment = Assignment();
        CHECK_EQUAL(Assignment::defaultMaxScore, assignment.getMaxScore());
    }

    // Test setMaxScore method.
    TEST(setMaxScoreTest)
    {
        unsigned int newMaxScore = 10;

        Assignment assignment = Assignment();
        assignment.setMaxScore(newMaxScore);
        CHECK_EQUAL(newMaxScore, assignment.getMaxScore());
    }

    // Test getTitle method.
    TEST(getTitleTest)
    {
        Assignment assignment = Assignment();
        CHECK_EQUAL(Assignment::defaultTitle, assignment.getTitle());
    }

    // Test getType method with the default type (should be Quiz).
    TEST(getTypeTest)
    {
        Assignment quizAssignment = Assignment("Some Title", Assignment::defaultType);
        //CHECK_EQUAL(Assignment::defaultType, quizAssignment.getType());
        CHECK_EQUAL(Assignment::defaultCustomType, quizAssignment.getType());
    }

    // Test getType method with a default object and a custom type.
    TEST(getCustomTypeTest)
    {
        string fakeTitle = "Fake";

        Assignment invalidAssignment = Assignment();
        CHECK_EQUAL(Assignment::defaultCustomType, invalidAssignment.getType());

        Assignment fakeAssignment = Assignment("Fake", fakeTitle);
        CHECK_EQUAL(fakeTitle, fakeAssignment.getType());
    }

    // Test setTitle method.
    TEST(setTitleTest)
    {
        string title = "Custom Title";

        Assignment assignment = Assignment();
        assignment.setTitle(title);
        CHECK_EQUAL(title, assignment.getTitle());
    }

    // Test setType method with enumerated value.
    // DEPRECATED
    TEST(setEnumeratedTypeTest)
    {
        Assignment invalidAssignment = Assignment();
        invalidAssignment.setType(Discussion);
        CHECK_EQUAL("Discussion", invalidAssignment.getType());
    }

    // Test setType method with string.
    TEST(setTypeTest)
    {
        string customType = "More Custom 2.0";

        Assignment invalidAssignment = Assignment();
        invalidAssignment.setType(customType);
        CHECK_EQUAL(customType, invalidAssignment.getType());
    }
}

#endif // ASSIGNMENTTESTS_H_INCLUDED
