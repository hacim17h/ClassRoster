/*
* roster.cpp
* Contains the function definitions for the roster class.
* Mostly deals with removing and adding student objects but
* also deals with various calculations upon student data.
*/

#include <iostream>
#include <cstring>
#include <array>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

//destructor that frees memory on the classRosterArray when delete is called
Roster::~Roster() {
	cout << endl << "In Roster Destructor freeing memory..." << endl;
	int i;
	for (i = 0; i < GetNumberOfStudents(); ++i)
	{
		delete classRosterArray[i];
	}
}

//allows the student object to be populated using a wide range of parameters
void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	if (numberOfStudents < 5)
	{
		classRosterArray[numberOfStudents] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1,
			daysInCourse2, daysInCourse3, degreeprogram);
		numberOfStudents++;
	}

}

//function that removes the student from the roster if they exist. Prints an error if they do not
void Roster::Remove(string studentID) {
	int i;
	int j;
	int requestedID = -1;   //stores the index of the student requested if the studentID matches
	int copyStart = -1;     //stores the index after the deleted item as the startin point of copying the remaining items
	bool exists = false;    //a boolean that stores if the studentID exists or not
	Student* tmpRoster[5];  //a temporary roster to hold unremoved students

	for (i = 0; i < numberOfStudents; ++i) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			exists = true;
			requestedID = i;
			copyStart = i + 1;  // takes the requested ID's index and goes past it to set copy start point

			//starts at the location after the student to be deleted and copies the remaining entires to a temporary array
			for (j = copyStart; j < numberOfStudents; ++j) {


				tmpRoster[(j - copyStart)] = new Student(classRosterArray[j]->GetStudentID(), classRosterArray[j]->GetFirstName(),
					classRosterArray[j]->GetLastName(), classRosterArray[j]->GetEmailAddress(),
					classRosterArray[j]->GetAge(), classRosterArray[j]->GetDaysInCourse(0),
					classRosterArray[j]->GetDaysInCourse(1), classRosterArray[j]->GetDaysInCourse(2),
					classRosterArray[j]->GetDegreeProgram());
			}

			//starts at the location of the student to be deleted and replaces entries with the remaining that aren't deleted
			for (j = requestedID; j < numberOfStudents - 1; ++j) {
				delete classRosterArray[j];  // deletes the old student data to make space for the new student that will replace it
				classRosterArray[j] = new Student(tmpRoster[j - requestedID]->GetStudentID(), tmpRoster[j - requestedID]->GetFirstName(),
					tmpRoster[j - requestedID]->GetLastName(), tmpRoster[j - requestedID]->GetEmailAddress(),
					tmpRoster[j - requestedID]->GetAge(), tmpRoster[j - requestedID]->GetDaysInCourse(0),
					tmpRoster[j - requestedID]->GetDaysInCourse(1), tmpRoster[j - requestedID]->GetDaysInCourse(2),
					tmpRoster[j - requestedID]->GetDegreeProgram());
				delete tmpRoster[j - requestedID];  //deletes the temporary student after the information has been copied

			}
			numberOfStudents--;			
			break;
		}

	}
	if (exists == false) {
		cout << "Error. The student by the ID " << studentID << " does not exist." << endl;
	}

}

//function that goes through every student in the roster and calls the print function to print every student
void Roster::PrintAll() {
	int i;
	for (i = 0; i < numberOfStudents; ++i)
	{
		GetClassRoster(i)->Print();
	}
}

//function that prints the average # of days a student spent on a course based upon their ID.
void Roster::PrintAverageDaysInCourse(string studentID) {
	int i;
	int totalDays = 0;               //stores all of the days between the three courses added together
	int averageCourseDays = 0;       //stores the average days spent on each course
	const int NUMBER_OF_COURSES = 3; //stores a fixed value for the number of courses included in report
	bool exists = false;             //a boolean that stores if the studentID exists or not

	for (i = 0; i < numberOfStudents; ++i) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			exists = true;
		    
			totalDays += classRosterArray[i]->GetDaysInCourse(0);
			totalDays += classRosterArray[i]->GetDaysInCourse(1);
			totalDays += classRosterArray[i]->GetDaysInCourse(2);
			averageCourseDays = (totalDays / NUMBER_OF_COURSES);
			cout << "The average number of days spent on each course for student " << studentID;
			cout << " was: " << averageCourseDays << endl;
			break;
		}

	}
	if (exists == false) {
		cout << "Error. The student by the ID " << studentID << " does not exist." << endl;
	}
}

//function that checks to see if an email is valid and if it is invalid prints the invalid email
void Roster::PrintInvalidEmails() {
	int i;
	string emails[5];
	for (i = 0; i < numberOfStudents; ++i) {
		if (strchr(classRosterArray[i]->GetEmailAddress().c_str(), '@') == nullptr) {
			cout << "The e-mail address " << classRosterArray[i]->GetEmailAddress() << " is invalid." << endl;
		}
		else if (strchr(classRosterArray[i]->GetEmailAddress().c_str(), '.') == nullptr) {
			cout << "The e-mail address " << classRosterArray[i]->GetEmailAddress() << " is invalid." << endl;
		}
		else if (strchr(classRosterArray[i]->GetEmailAddress().c_str(), ' ') != nullptr) {
			cout << "The e-mail address " << classRosterArray[i]->GetEmailAddress() << " is invalid." << endl;
		}
	}

}

//function that prints all students that have the selected degree program
void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
	int i;

	bool exists = false;             //a boolean that stores if the studentID exists or not

	for (i = 0; i < numberOfStudents; ++i) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			exists = true;
			classRosterArray[i]->Print();
		}

	}
	if (exists == false) {
		cout << "Currently, No Student is enrolled in this degree program." << endl;
	}

}

//a helper accessor that assists in getting the current size of the student array
int Roster::GetNumberOfStudents() const {
	return numberOfStudents;
}

//a default constructor that helps the destructor when the object is called initially
Student* Roster::GetClassRoster() const {
	return *classRosterArray;
}

//overloaded accessor that allows the user to get a specific index from the array
Student* Roster::GetClassRoster(int index) const {
	return classRosterArray[index];
}