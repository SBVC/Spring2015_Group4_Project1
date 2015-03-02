/* 
 * File:   whiteboard.h
 *
 * Created on March 15, 2015
 */

#ifndef WHITEBOARD_H
#define WHITEBOARD_H

#include <string>

class Student{
private:
    int id;
    std::string lastName;
    std::string firstName;
    public:
    Student();
    Student(int init_id, std::string init_lastName, std::string init_firstName);
    // setters
    //void set_id(int init_id){ id = init_id; }
    //void set_lastName(std::string init_lastName){ lastName = init_lastName; }
    //void set_firstName(std::string init_firstName){ firstName = init_firstName; }
    
    // getters
    int get_id(){ return id; }
    std::string get_lastName(){ return lastName; }
    std::string get_firstName(){ return firstName; }
 
};

class Assignments { 
private:
    int aId, assignType, grade1, grade2, grade3, grade4, grade5;
public:
    Assignments();
    Assignments(int init_id, int init_assignType, int init_grade1, int init_grade2, int init_grade3, int init_grade4, int init_grade5 );

    // getters
    int get_id() { return aId; }
    int get_asnType() { return assignType; }
    int get_grade1() { return grade1; }
    int get_grade2() { return grade2; }
    int get_grade3() { return grade3; }
    int get_grade4() { return grade4; }
    int get_grade5() { return grade5; }
};

#endif 

