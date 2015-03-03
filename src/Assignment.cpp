#include "Assignment.h"
#include "AssignmentType.h"

unsigned int Assignment::nextID = 0;

const string Assignment::defaultTitle = "Invalid";
const string Assignment::defaultCustomType = "Invalid";
const AssignmentType Assignment::defaultType = Quiz;
const unsigned int Assignment::defaultMaxScore = 100;

Assignment::Assignment()
{
    id = getNextID();
    title = defaultTitle;
    type = Custom;
    maxScore = defaultMaxScore;
    customType = defaultCustomType;
}

Assignment::Assignment(string titleVal, string sType, unsigned int iMaxScore)
{
    id = getNextID();
    title = titleVal;
    maxScore = iMaxScore;
    if (sType == "Quiz"){
        type = Quiz;
    } else if (sType == "Exam"){
        type = Exam;
    } else if (sType == "Program"){
        type = Program;
    } else if (sType == "Discussion"){
        type = Discussion;
    } else {
        type = Custom;
        customType = sType;
    }
}

Assignment::Assignment(string titleVal)
{
    id = getNextID();
    title = titleVal;
    maxScore = defaultMaxScore;
    type = defaultType;
}

Assignment::Assignment(string titleVal, string sType)
{
    id = getNextID();
    title = titleVal;
    maxScore = defaultMaxScore;
    if (sType == "Quiz"){
        type = Quiz;
    } else if (sType == "Exam"){
        type = Exam;
    } else if (sType == "Program"){
        type = Program;
    } else if (sType == "Discussion"){
        type = Discussion;
    } else {
        type = Custom;
        customType = sType;
    }
}

Assignment::Assignment(string titleVal, unsigned int iMaxScore)
{
    id = getNextID();
    title = titleVal;
    maxScore = iMaxScore;
    type = defaultType;
}

string Assignment::getID()
{
    stringstream convert;
    convert << "a" << id;
    return convert.str();
}

string Assignment::getType()
{
    if (type == Quiz){
        return "Quiz";
    } else if (type == Exam){
        return "Exam";
    } else if (type == Program){
        return "Program";
    } else if (type == Discussion){
        return "Discussion";
    } else if (type == Custom){
        return customType;
    } else {
        //figure out how to throw an error and throw one here
    }
}

void Assignment::setType(string customName)
{
    type = Custom;
    customType = customName;
}

unsigned int Assignment::getNextID()
{
    return nextID++;
}
