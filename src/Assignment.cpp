#include "Assignment.h"
#include "AssignmentType.h"
#include <sstream>
#include <iostream>

using namespace std;

unsigned int Assignment::nextID = 0;

const string Assignment::defaultTitle = "Invalid";
const string Assignment::defaultCustomType = "Invalid";
const AssignmentType Assignment::defaultType = Quiz;
const unsigned int Assignment::defaultMaxScore = 100;

Assignment::Assignment()
{
    id = getNextID();
    title = defaultTitle;
    type = defaultCustomType;
    maxScore = defaultMaxScore;
}

Assignment::Assignment(string sTitle, string sType, unsigned int iMaxScore)
{
    id = getNextID();
    title = sTitle;
    maxScore = iMaxScore;
    type = sType;
}

Assignment::Assignment(string sTitle)
{
    id = getNextID();
    title = sTitle;
    maxScore = defaultMaxScore;
    type = defaultCustomType;
}

Assignment::Assignment(string sTitle, string sType)
{
    id = getNextID();
    title = sTitle;
    maxScore = defaultMaxScore;
    type = sType;
}

Assignment::Assignment(string sTitle, unsigned int iMaxScore)
{
    id = getNextID();
    title = sTitle;
    maxScore = iMaxScore;
    type = defaultCustomType;
}

string Assignment::getID()
{
    stringstream convert;
    convert << "a" << id;
    return convert.str();
}

// DEPRECATED
void Assignment::setType(AssignmentType val)
{
    // Log for using deprecated code.
    clog << "Assignment a" << id << " was assigned a type using the deprecated setType(AssignmentType val) method." << endl;

    if (val == Quiz){
        type = "Quiz";
    } else if (val == Exam){
        type = "Exam";
    } else if (val == Program){
        type = "Program";
    } else if (val == Discussion){
        type = "Discussion";
    } else {
        type = defaultCustomType;
        // detailed error message about using invalid type AND deprecated method
        cerr << "Assignment a" << id << " was assigned an invalid type using the deprecated setType(AssignmentType val) method. Assignment a" << id << "'s type has been defaulted to " << defaultCustomType << "." << endl;
    }
}
