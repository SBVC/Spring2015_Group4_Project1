#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "AssignmentType.h"
#include <string>

class Assignment
{
    public:
        // Constructors
        Assignment();
        Assignment(std::string sTitle, std::string sType, unsigned int iMaxScore);
        Assignment(std::string sTitle);
        Assignment(std::string sTitle, std::string sType);
        Assignment(std::string sTitle, unsigned int iMaxScore);

        // Getters
        unsigned int getMaxScore() { return maxScore; }
        std::string  getID();
        unsigned int getRawID()    { return id; }
        std::string  getTitle()    { return title; }
        std::string  getType()     { return type; }

        // Setters
        void setMaxScore(unsigned int val) { maxScore = val; }
        void setTitle(std::string val)     { title = val; }
        void setType(AssignmentType val);                     // DEPRECATED
        void setType(std::string val)      { type  = val; }

        // Defaults
        const static std::string defaultTitle;
        const static std::string defaultCustomType;
        const static AssignmentType defaultType;  // DEPRECATED
        const static unsigned int defaultMaxScore;

    protected:
        static unsigned int getNextID() { return nextID++; }

    private:
        static unsigned int nextID;
        unsigned int        maxScore;
        unsigned int        id;
        std::string         title;
        std::string         type;
};

#endif // ASSIGNMENT_H
