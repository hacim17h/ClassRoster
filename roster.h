/*
* roster.h
* Header that contains class definitions as well as function declarations
* for the roster class. Used for mostly adding and removing from the roster.
*/


#pragma once
#include "student.h"
#include "degree.h"
using namespace std;

class Roster {
public:

	//a destructor that frees the memory of the pointers used
	~Roster(); 
	
	//allows the student object to be populated using a wide range of parameters
	void Add(string studentID, string firstName, string lastName, string emailAddress, int age,  
		 int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);	

	//function that removes the student from the roster if they exist. Prints an error if they do not	
	void Remove(string studentID);                                                                 
	
	//function that goes through every student in the roster and calls the print function to print every student
	void PrintAll();
	
	//function that prints the average # of days a student spent on a course based upon their ID.
	void PrintAverageDaysInCourse(string studentID); 

	//function that checks to see if an email is valid and if it is invalid prints the invalid email
	void PrintInvalidEmails();

	//function that prints all students that have the selected degree program
	void PrintByDegreeProgram(DegreeProgram degreeProgram); 

	//accessor that gets the number of students in the roster
	int GetNumberOfStudents() const;

	//accessor that gets the classRosterArray pointer
	Student* GetClassRoster() const;
	
	//overloaded accressor that gets the classRosterArray at a specific index
	Student* GetClassRoster(int index) const;


private:
	int numberOfStudents = 0;       //helper integer that stores the current number of students in the classRosterArray
	Student* classRosterArray[5];   //stores all of the student objects and will hold all of the parsed information when added

};