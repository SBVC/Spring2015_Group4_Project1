#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>

/*
Students should have a vector with Grade structs, each one has an assignment ID and a score.
Students should have getTotalScore, getGradePercentage, addAssignment, setScore, getScore

getScore, setScore, addAssignment expects an assignment ID

getGradePercentage gets all assignments (via their ids from the structs) and all scores and calculates a double percentage
*/

class Student{
    private:
        static int nextID;
        int        id;
        std::string     lastName;
        std::string     firstName;
    protected:
        static int get_nextID() { return nextID++; }
    public:
        // constructors
        Student();
        Student(std::string init_lastName, std::string init_firstName);
        Student(int init_id, std::string init_lastName, std::string init_firstName); // DEPRECATED

        // setters
        void set_lastName(std::string init_lastName)  { lastName = init_lastName; }
        void set_firstName(std::string init_firstName){ firstName = init_firstName; }

        // getters
        int get_id()          { return id; }
        std::string get_namedID();
        std::string get_lastName() { return lastName; }
        std::string get_firstName(){ return firstName; }

        // defaults
        const static int defaultID;
        const static std::string defaultLastName;
        const static std::string defaultFirstName;

};

#endif // STUDENT_H_INCLUDED
