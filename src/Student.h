#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>

using namespace std;

class Student{
    private:
        static int nextID;
        int        id;
        string     lastName;
        string     firstName;
    protected:
        static int get_nextID() { return nextID++; }
    public:
        // constructors
        Student();
        Student(string init_lastName, string init_firstName);
        Student(int init_id, string init_lastName, string init_firstName); // DEPRECATED

        // setters
        void set_lastName(string init_lastName){ lastName = init_lastName; }
        void set_firstName(string init_firstName){ firstName = init_firstName; }

        // getters
        int get_id(){ return id; }
        string get_lastName(){ return lastName; }
        string get_firstName(){ return firstName; }

        // defaults
        const static int defaultID;
        const static string defaultLastName;
        const static string defaultFirstName;

};

#endif // STUDENT_H_INCLUDED
