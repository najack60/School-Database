#pragma once
#include<iostream>
#include<string>
using namespace std;

class personType {

public:
	//setter functions "mutator functions"
	void setFirstName(string);
	void setLastName(string);
	void setAge(int);

	//getter functions "accessor functions"
	string getFirstName();
	string getLastName();
	int getAge();

	//print funtion
	void print();

	////constructors
	//Default Constructor
	personType();

	//Other Constructors
	personType(string, string, int);
	personType(string, string);

protected:
	string firstName;
	string lastName;
	int age;
};

//setter function definitions
void personType::setFirstName(string s) {
	firstName = s;
}
void personType::setLastName(string s) {
	lastName = s;
}
void personType::setAge(int i) {
	age = i;
}

//getter function definitions
string personType::getFirstName() {
	return firstName;
}
string personType::getLastName() {
	return lastName;
}
int personType::getAge() {
	return age;
}

void personType::print() {
	cout << "- First Name: " << firstName << endl;
	cout << "- Last Name: " << lastName << endl;
	cout << "- Age: " << age << endl;
}

personType::personType() {

	firstName = "n/a";
	lastName = "n/a";
	age = -1;

}

personType::personType(string s1, string s2, int i) {

	firstName = s1;
	lastName = s2;
	age = i;
}

personType::personType(string s1, string s2) {

	firstName = s1;
	lastName = s2;
	age = -1;
}
