#include "Assignment.h"
#include "AssignmentType.h"

unsigned int Assignment::nextID = 0;

Assignment::Assignment()
{
    id = nextID;    nextID++;
    title = "Title";
    type = Custom;
    maxScore = 100;
    customType = "Invalid";
}

Assignment::Assignment(string titleVal, string sType, unsigned int iMaxScore)
{
    id = nextID;    nextID++;
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
    id = nextID;    nextID++;
    title = titleVal;
    maxScore = 100;
    type = Quiz;
}

Assignment::Assignment(string titleVal, string sType)
{
    id = nextID;    nextID++;
    title = titleVal;
    maxScore = 100;
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
    id = nextID;    nextID++;
    title = titleVal;
    maxScore = iMaxScore;
    type = Quiz;
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
        // this is terrible, pretend it doesn't exist, okay?
        return "DUN FUCKED UP AND DID SOMETHING IMPOSSIBLE";
    }
}

void Assignment::setType(string customName)
{
        type = Custom;
        customType = customName;
}
