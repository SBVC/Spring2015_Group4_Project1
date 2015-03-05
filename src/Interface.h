#ifndef INTERFACE_H
#define INTERFACE_H

/*
list -> go through vector of students/assignments, output info
add new -> ask for each property, then call constructor, add to vector
search, students:
  ID,
  last name,
  first name,
  total grade ... ? percentage? points? most assignments?
search, assignments:
  ID,
  title/name,
  type,
  maxScore

Classes? Interface? Whiteboard?
list students just needs a vector, same with list assignments
searching / adding new are interface things
*/

class Interface
{
    public:
        Interface();
        virtual ~Interface();
        void mainMenu();
    protected:
        void listStudents();
        void listAssignments();
        void addNewStudent();
        void addNewAssignment();
        void searchStudentsMenu();
        void searchAssignmentsMenu();
        void searchStudentsByID();
        void searchStudentsByLastName();
        void searchStudentsByFirstName();
        void searchAssignmentsByID();
        void searchAssignmentsByType();
        void searchAssignmentsByTitle();
    private:
};

#endif // INTERFACE_H
