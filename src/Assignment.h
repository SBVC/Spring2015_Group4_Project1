#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "AssignmentType.h"
#include <string>

using namespace std;

class Assignment
{
    public:
        Assignment();
        Assignment(string titleVal, string sType, unsigned int iMaxScore);
        Assignment(string titleVal);
        Assignment(string titleVal, string sType);
        Assignment(string titleVal, unsigned int iMaxScore);
        unsigned int getMaxScore() { return maxScore; }
        void setMaxScore(unsigned int val) { maxScore = val; }
        string getID();
        unsigned int getRawID() { return id; }
        string getTitle() { return title; }
        void setTitle(string val) { title = val; }
        string getType();
        void setType(AssignmentType val) { type = val; }
        void setType(string customName);
    //protected:
    private:
        static unsigned int nextID;
        unsigned int maxScore;
        unsigned int id;
        string title;
        string customType;
        AssignmentType type;
};

#include "Assignment.cpp" //why

#endif // ASSIGNMENT_H