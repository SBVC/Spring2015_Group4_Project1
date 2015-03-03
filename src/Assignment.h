#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "AssignmentType.h"
#include <string>

using namespace std;

class Assignment
{
    public:
        // Constructors
        Assignment();
        Assignment(string sTitle, string sType, unsigned int iMaxScore);
        Assignment(string sTitle);
        Assignment(string sTitle, string sType);
        Assignment(string sTitle, unsigned int iMaxScore);

        // Getters
        unsigned int getMaxScore() { return maxScore; }
        string       getID();
        unsigned int getRawID()    { return id; }
        string       getTitle()    { return title; }
        string       getType()     { return type; }

        // Setters
        void setMaxScore(unsigned int val) { maxScore = val; }
        void setTitle(string val)          { title = val; }
        void setType(AssignmentType val);                     // DEPRECATED
        void setType(string val)           { type  = val; }

        // Defaults
        const static string defaultTitle;
        const static string defaultCustomType;
        const static AssignmentType defaultType;  // DEPRECATED
        const static unsigned int defaultMaxScore;

    protected:
        unsigned int getNextID() { return nextID++; }

    private:
        static unsigned int nextID;
        unsigned int        maxScore;
        unsigned int        id;
        string              title;
        string              type;
};

//#include "Assignment.cpp" //why is this needed here? it wasn't needed before
// why WAS that needed and now breaks everything and had to be removed?!

#endif // ASSIGNMENT_H
