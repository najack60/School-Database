//Lab3
//Name: Nathaniel Colbert
//SID: 007281086
//Due: 11/20/2020

/*
This lab covers the following:
	[1] Classes
	[2] Inheritance
	[3] Overloading

Task:
This program simulates a school database that stores the information of students and faculty. To finish this lab,
you must do the following:
	[1] Add two new text files to the program named 'faculty.txt' and 'students.txt'. You will find these textfiles
		on BlackBoard.
	[2] Add the three header files 'personType.h', 'studentType.h', and 'facultyType.h' that we've finished/will
		finish by the time we complete LectureActivity8
	[3] Run the program and play with it. See how it works, then take a screenshot.

	*Depending on whether or not you've done Lecture Activities 6-8, this could be the easiest or the hardest lab for you.

Instructions to submit:
	[1] Send an email to me (005823892@coyote.csusb.edu) with the CPP file, all three header files, and 1 screenshot of your
		program working.
	[2]	The subject line of the email MUST be in the following format:

		CSE2000Q2S [lastname][firstname] LAB3
*/

//includes
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//classes
#include "personType.h"
#include "studentType.h"
#include "facultyType.h"

int main()
{
	//two vectors; one for students, one for faculty
	vector<studentType> students;
	vector<facultyType> faculty;

	//read the two input and load them into the vectors
	ifstream infile;
	ofstream outfile;

	//read and load students
	infile.open("students.txt");
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			studentType temp;
			string tempString;
			getline(infile, tempString);
			temp.setFirstName(tempString);
			getline(infile, tempString);
			temp.setLastName(tempString);
			getline(infile, tempString);
			temp.setAge(stoi(tempString));
			getline(infile, tempString);
			temp.setSID(tempString);
			getline(infile, tempString);
			temp.setMajor(tempString);
			getline(infile, tempString);
			temp.setGPA(stod(tempString));
			//push back to vector
			students.push_back(temp);
		}
		infile.close();
	}
	else
	{
		cout << "The file 'students.txt' could not be opened" << endl;
	}

	infile.open("faculty.txt");
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			facultyType temp;
			string tempString;
			getline(infile, tempString);
			temp.setFirstName(tempString);
			getline(infile, tempString);
			temp.setLastName(tempString);
			getline(infile, tempString);
			temp.setAge(stoi(tempString));
			getline(infile, tempString);
			temp.setDiscipline(tempString);
			getline(infile, tempString);
			temp.setSalary(stod(tempString));
			//push back to vector
			faculty.push_back(temp);
		}
		infile.close();
	}
	else
	{
		cout << "The file 'faculty.txt' could not be opened" << endl;
	}

	//for debugging purposes
	/*for (int i = 0; i < faculty.size(); i++)
	{
		faculty[i].print();
		cout << endl;
	}*/

	string command = "";

	while (command != "exit")
	{
		cout << "******************************************************************" << endl
			<< "**                    School Database Program                   **" << endl
			<< "******************************************************************" << endl << endl
			<< "LIST OF COMMANDS:" << endl << endl
			<< "o 'addStud'     - Add a new student." << endl
			<< "o 'delStud'     - Delete an existing student." << endl
			<< "o 'searchStud'  - Search students. " << endl
			<< "o 'sPrint'      - Print all student info." << endl << endl
			<< "o 'addFacul'    - Add a new faculty member." << endl
			<< "o 'delFacul'    - Delete an existing faculty member. " << endl
			<< "o 'fPrint'      - Print all faculty info. " << endl << endl
			<< "o 'exit'        - Exit the program. " << endl << endl
			<< "******************************************************************" << endl << endl
			<< " > ";
		cin >> command;
		cout << endl;

		if (command == "addStud")
		{
			studentType temp;
			string tempString = "";
			bool isNew = true;
			cin.ignore();
			cout << "ADDING NEW STUDENT" << endl
				<< "- enter first name: ";
			getline(cin, tempString);
			temp.setFirstName(tempString);

			cout << "- enter last name: ";
			getline(cin, tempString);
			temp.setLastName(tempString);

			cout << "- enter student ID: ";
			getline(cin, tempString);
			temp.setSID(tempString);

			cout << "- enter age: ";
			getline(cin, tempString);
			temp.setAge(stoi(tempString));

			cout << "- enter major: ";
			getline(cin, tempString);
			temp.setMajor(tempString);

			cout << "- enter GPA: ";
			getline(cin, tempString);
			temp.setGPA(stod(tempString));

			for (int i = 0; i < students.size(); i++)
			{
				if (students[i] == temp)
				{
					cout << endl << "Student already exists in this database. " << endl << endl;
					isNew = false;
					break;
				}
			}

			if (isNew)
			{
				students.push_back(temp);
				cout << endl << "New Student successfully added to database." << endl << endl;
			}
		}
		else if (command == "delStud")
		{
			studentType temp;
			string tempString = "";
			bool found = false;
			cin.ignore();
			cout << "Enter search criteria to find and delete:" << endl
				<< "- enter first name: ";
			getline(cin, tempString);
			temp.setFirstName(tempString);

			cout << "- enter last name: ";
			getline(cin, tempString);
			temp.setLastName(tempString);

			cout << "- enter student ID: ";
			getline(cin, tempString);
			temp.setSID(tempString);

			for (int i = 0; i < students.size(); i++)
			{
				if (students[i] == temp)
				{
					found = true;
					cout << endl << "Student with matching criteria found: " << endl << endl;
					students[i].print();
					cout << endl << endl << "Are you sure you want to delete this item? Enter [Y/N]" << endl;

					string command2 = "";
					while (command2 != "Y" && command2 != "N")
					{
						cout << " > ";
						cin >> command2;

						if (command2 == "Y")
						{
							//delete item
							vector<studentType>::iterator it = students.begin();
							for (int j = 0; j < i; j++)
							{
								it++;
							}
							students.erase(it);
							it = students.begin();
						}
						else if (command2 != "N")
						{
							cout << "Not a valid response. Please enter [Y/N]" << endl;
						}
					}
					break;
				}
			}
			if (!found)
			{
				cout << endl << endl << "No item was found with this search." << endl << endl;
			}
		}
		else if (command == "searchStud")
		{
			cout << endl << "Enter a criteria to search by: " << endl
				<< " Enter [1] to print all students on the Dean's List (3.50 GPA or higher). " << endl
				<< " Enter [2] to print all students on academic probation (2.00 GPA or lower). " << endl;
			string command2 = "";
			while (command2 != "1" && command2 != "2")
			{
				cout << " > ";
				cin >> command2;
				if (command2 == "1")
				{
					cout << "STUDENTS ON THE DEANS LIST: " << endl;
					for (int i = 0; i < students.size(); i++)
					{
						if (students[i] >= 3.5)
						{
							students[i].print();
							cout << endl;
						}
					}
				}
				else if (command2 == "2")
				{
					cout << "STUDENTS ON ACADEMIC PROBATION: " << endl;
					for (int i = 0; i < students.size(); i++)
					{
						if (students[i] <= 2.0)
						{
							students[i].print();
							cout << endl;
						}
					}
				}
				else
				{
					cout << "Not a valid response. Please enter 1 or 2." << endl;
				}
			}

		}
		else if (command == "sPrint")
		{
			for (int i = 0; i < students.size(); i++)
			{
				students[i].print();
				cout << endl;
			}
		}
		else if (command == "addFacul")
		{
			facultyType temp;
			string tempString = "";
			bool isNew = true;
			cin.ignore();
			cout << "ADDING NEW FACULTY MEMBER:" << endl
				<< "- enter first name: ";
			getline(cin, tempString);
			temp.setFirstName(tempString);

			cout << "- enter last name: ";
			getline(cin, tempString);
			temp.setLastName(tempString);

			cout << "- enter age: ";
			getline(cin, tempString);
			temp.setAge(stoi(tempString));

			cout << "- enter discipline: ";
			getline(cin, tempString);
			temp.setDiscipline(tempString);

			cout << "- enter salary: ";
			getline(cin, tempString);
			temp.setSalary(stod(tempString));

			for (int i = 0; i < faculty.size(); i++)
			{
				if (faculty[i] == temp)
				{
					cout << endl << "Faculty member already exists in this database. " << endl << endl;
					isNew = false;
					break;
				}
			}

			if (isNew)
			{
				faculty.push_back(temp);
				cout << endl << "New Faculty Member successfully added to database." << endl << endl;
			}
		}
		else if (command == "delFacul")
		{
			facultyType temp;
			string tempString = "";
			bool found = false;
			cin.ignore();
			cout << "Enter search criteria to find and delete:" << endl
				<< "- enter first name: ";
			getline(cin, tempString);
			temp.setFirstName(tempString);

			cout << "- enter last name: ";
			getline(cin, tempString);
			temp.setLastName(tempString);

			for (int i = 0; i < faculty.size(); i++)
			{
				if (faculty[i] == temp)
				{
					found = true;
					cout << endl << "Faculty member with matching criteria found: " << endl << endl;
					faculty[i].print();
					cout << endl << endl << "Are you sure you want to delete this item? Enter [Y/N]" << endl;

					string command2 = "";
					while (command2 != "Y" && command2 != "N")
					{
						cout << " > ";
						cin >> command2;

						if (command2 == "Y")
						{
							//delete item
							vector<facultyType>::iterator it = faculty.begin();
							for (int j = 0; j < i; j++)
							{
								it++;
							}
							faculty.erase(it);
							it = faculty.begin();
						}
						else if (command2 != "N")
						{
							cout << "Not a valid response. Please enter [Y/N]" << endl;
						}
					}
					break;
				}
			}
			if (!found)
			{
				cout << endl << endl << "No item was found with this search." << endl << endl;
			}
		}
		else if (command == "fPrint")
		{
			for (int i = 0; i < faculty.size(); i++)
			{
				faculty[i].print();
				cout << endl;
			}
		}
		else if (command != "exit")
		{
			cout << "Sorry, that is not a valid command. " << endl << endl;
		}
	}

	return 0;
}