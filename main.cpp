/*
* main.cpp 
* Contains the main function and overall sets up the presentation of the program.
* Various helper functions or output manipulations take place here.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

//A helper function that converts a string into the proper degree program enums.
DegreeProgram StringToEnum(string input) {
    DegreeProgram degree; 
    if (input == "SECURITY"){
        degree = SECURITY;
        return degree;
    }
    if (input == "NETWORK") {
        degree = NETWORK;
        return degree;
    }
    if (input == "SOFTWARE") {
        degree = SOFTWARE;
        return degree;
    }   
    else {
        degree = SOFTWARE;
        return degree;
    }
}

int main()
{
   
    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                   "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                   "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                   "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                   "A5,Micah,Calloway,mcal252@wgu.edu,35,1,3,3,SOFTWARE" };

    string parsedData[15][5];       //stores the parsed data from the student data string array
    int elementCount = 0;           //keeps track of the number of students within the studen data
    int currentPosition = 0;        //keeps track of the current position inside of the string
    string currentString = "None";  //keeps track of the current string being used in student data
    int i;

    //main loop body that actually parses the data
    for (i = 0; i < 5; ++i) {
        currentString = studentData[i];

        //searches for commas in the string and parses it seperating each string value between the commas and storing it
        while (currentString.find(',', currentPosition) != string::npos) {

            if (currentString.find(',', currentPosition) != string::npos) {                
                //stores a substring based upon the current position and the length is the distance between the next comma and the current position
                parsedData[elementCount][i] = currentString.substr(currentPosition, (currentString.find(',', currentPosition) - currentPosition));

                //updates the current position to be right after first comma encountered
                currentPosition = (currentString.find(',', currentPosition)) + 1;
                elementCount++;
            }
        }
        //get final value if the string had comma seperated values in it
        if (currentPosition > 0) {
            parsedData[elementCount][i] = currentString.substr(currentPosition, (currentString.find(',', currentPosition) - currentPosition));
            //cout << "the current value is " << parsedData[elementCount][i] << endl;
            currentPosition = 0;
            elementCount = 0;
        }
    }
    

    //prints out basic information like course title, language used, name, and id
    cout << "-----------------------------------------------------" << endl;
    cout << "Course: Scripting and Programming Applications - C867" << endl; 
    cout << "Language Used : C++" << endl; 
    cout << "WGU Student ID : 010663003" << endl; 
    cout << "Name: Micah Calloway" << endl;
    cout << "-----------------------------------------------------" << endl;
    
    
    Roster classRoster;  //creates an instance of roster 

    //adds each student to the roster using the parsed data
    for (i = 0; i < 5; ++i) {
        classRoster.Add(parsedData[0][i], parsedData[1][i], parsedData[2][i], parsedData[3][i], stoi(parsedData[4][i]),
               stoi(parsedData[5][i]), stoi(parsedData[6][i]), stoi(parsedData[7][i]), StringToEnum(parsedData[8][i]));
    }    
    
    //prints all students
    classRoster.PrintAll();      
    cout << endl;

    //prints all invalid emails 
    classRoster.PrintInvalidEmails();  
    cout << endl;

    //loops and prints average days in course for each student    
    for (i = 0; i < classRoster.GetNumberOfStudents(); ++i) {
        classRoster.PrintAverageDaysInCourse(classRoster.GetClassRoster(i)->GetStudentID());
    }
    cout << endl;

    //prints all people by degree program
    classRoster.PrintByDegreeProgram(SOFTWARE);
    cout << endl;

    //removes student A3 and reprints information
    classRoster.Remove("A3");
    cout << endl;
       
    classRoster.PrintAll();
    cout << endl;

    classRoster.Remove("A3");    

    //calls destructor to free data 
    delete classRoster.GetClassRoster();            
}