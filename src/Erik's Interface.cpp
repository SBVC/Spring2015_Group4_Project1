//Created on March 3, 2015

#include<iostream>
using namespace std;

void studentSearchMenu();								//Prototype for student search menu

/* temporarily commented out
int main()
{
    cout << "Welcome to WhiteBoard" << endl << endl;
    cout << "Please select one of the following: " << endl;
	cout << "1. List all students" << endl;
	cout << "2. Search for a student" << endl;
	cout << "3. Add a new student" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter [1-4]" << endl;

	int input;
	cin >> input;
	switch (input)									//The cout in this switch statement will change once I get the proper
	{												//functinos from you guys.
		case 1:
			cout << "You chose option 1" << endl;
			break;
		case 2:
			studentSearchMenu();					//Did this so it looks cleaner in main
			break;
		case 3:
			cout << "You chose option 3" << endl;
			break;
		case 4:
			cout << "You chose option 4" << endl;
			break;
		case 20966:
			cout << "You entered the back door" << endl;
			break;
		default:
			cout << "Invalid entry. Please select again" << endl;
			break;
	}


	system("pause");
	return 0;
}
//*/

void studentSearchMenu()									//This function just prints the student search menu
{
	cout << "How do you want to search for the student?\n";
	cout << "1. Search by student ID\n";
	cout << "2. Search by student last name\n";
	cout << "3. Search by student first name\n";
	cout << "4. Search by student total grade\n";
	cout << "5. Return to main menu\n";
	cout << "Enter [1-5]: ";
	int input;
	cin >> input;
	switch (input)
	{
		case 1:
			cout << "You chose to search by student ID\n";
			break;
		case 2:
			cout << "You chose to search by students last name\n";
			break;
		case 3:
			cout << "You chose to search by students first name\n";
			break;
		case 4:
			cout << "You chose to search by students total grade\n";
			break;
		case 5:
			cout << "You chose to return to the main menu\n";
			break;
		default:
			cout << "Invalid entry. Please try again.";
			break;
	}
}
