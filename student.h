/*
* student.h
* Header that contains class definitions as well as function declarations 
* for the student class. Used for mostly storing student information.
*/

#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student {
public:
	Student();                                                     //default constructor for student
	Student(string studentID, string firstName, string lastName,   //overloaded constructor for student
	        string emailAddress, int age, int daysInCourse1,
		    int daysInCourse2, int daysInCourse3, DegreeProgram
		    degreeProgram);

	void SetStudentID(string studentID);                           //mutator that sets student ID
	void SetFirstName(string firstName);                           //mutator that sets first name
	void SetLastName(string lastName);                             //mutator that sets last name
	void SetEmailAddress(string emailAddress);                     //mutator that sets email address
	void SetAge(int age);                                          //mutator that sets age
	void SetDaysInCourse(int course1, int course2, int course3 );  //mutator that sets # days in course 
	void SetDegreeProgram(DegreeProgram degreeProgram);            //mutator that sets the degree program

	string GetStudentID() const;                                   //accessor that gets student ID
	string GetFirstName() const;                                   //accessor that gets first name
	string GetLastName() const;                                    //accessor that gets last name
	string GetEmailAddress() const;                                //accessor that gets email address
	int GetAge() const;                                            //accessor that gets age
	int GetDaysInCourse(int index) const;                          //accessor that gets # days in course at a specific index
	DegreeProgram GetDegreeProgram() const;                        //accessor that gets degree program

	void Print() const;                                            //prints all relevant student information

private:
	string studentID;                                              //string that stores the student id
	string firstName;                                              //string that stores the first name of student
	string lastName;                                               //string that stores the last name of student
	string emailAddress;                                           //string that stores the e-mail address
	int age;                                                       //int that stores the age of the student
	int daysInCourse[3];                                           //int that stores the # of days spent in each course
	DegreeProgram degreeProgram;                                   //ernum that stores the degree program 

};

