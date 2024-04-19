/*
* student.cpp
* Contains the function definitions for the student class.
* Mostly deals with printing, setting and getting student information.
*/

#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;

//default constructor that initializes values automatically upon class creation
Student::Student() {
	SetStudentID("NoID");
	SetFirstName("NoFirst");
	SetLastName("NoLast");
	SetEmailAddress("NoEmail");
	SetAge(-1);	
	SetDaysInCourse(-1, -2, -3);
	SetDegreeProgram(SOFTWARE);	
}

//overloaded constructor that has every value of the student class
Student::Student(string studentID, string firstName, string lastName, string emailAddress, 
		   int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram
		   degreeProgram) {

	SetStudentID(studentID);
	SetFirstName(firstName);
	SetLastName(lastName);
	SetEmailAddress(emailAddress);
	SetAge(age);
	SetDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);
	SetDegreeProgram(degreeProgram);
}

//mutator method that sets the student id
void Student::SetStudentID(string studentID) {
	this->studentID = studentID;
}

//mutator method that sets the first name
void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}

//mutator method that sets the last name
void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}

//mutator method that sets the email address
void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

//mutator method that sets the age
void Student::SetAge(int age) {
	this->age = age;
}

//mutator method that sets the number of days spent in each course
void Student::SetDaysInCourse(int course1, int course2, int course3) {
	
	this->daysInCourse[0] = course1;
	this->daysInCourse[1] = course2;
	this->daysInCourse[2] = course3;		
}

//mutator method that sets degree program 
void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

//accessor method that gets the student id
string Student::GetStudentID() const {
	return studentID;
}

//accessor method that gets the first name
string Student::GetFirstName() const {
	return firstName;
}

//accessor method that gets the last name
string Student::GetLastName() const {
	return lastName;
}

//accessor method that gets the email address
string Student::GetEmailAddress() const {
	return emailAddress;
}

//accessor method that gets the age
int Student::GetAge() const {
	return age;
}

//accessor method that gets the number of days in the course
int Student::GetDaysInCourse(int index) const {
	return daysInCourse[index];
}

//accessor method that gets the degree program
DegreeProgram Student::GetDegreeProgram() const {
	return degreeProgram;
}

//a print method that prints every category except for email in a readable tab seperated format
void Student::Print() const{
	
	string programTypes[] = { "Security", "Network", "Software" };    //Parallel string to the enum 
	cout << GetStudentID() << "\t";
	cout << "First Name: " << GetFirstName() << "\t";
	cout << "Last Name: " << GetLastName() << "\t";	
	cout << "Age: " << GetAge() << "\t";
	cout << "daysInCourse: {" << GetDaysInCourse(0) << ", " << GetDaysInCourse(1) << ", " << GetDaysInCourse(2) << "} ";
	cout << "Degree Program: " << programTypes[GetDegreeProgram()] << endl;
}


