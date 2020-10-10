//
//	Created by Sergio Tores on 1/22/19
//
#include <fstream>
#include <sstream>
#include "Records.h"

using namespace std;

//opens student csv file
void Records::openStFile() {
	Course course;
	fstream inputStFile;

	inputStFile.open("default.csv", ios::in);
	string line, field, temp;

	while (getline(inputStFile, line)) {
		stringstream ss(line);
		while (getline(ss, temp, ',')) {
			
		}

	}
	inputStFile.close();
}

//opens course csv file
void Records::openCoFile() {
	Course course;
	ifstream inputCoFile;

	inputCoFile.open("coursesDefaults.csv", ios::in);
	string line, field, temp;

	while (getline(inputCoFile, line)) {
		stringstream ss(line);
		while (getline(ss, temp, ',')) {

		}

	}
	inputCoFile.close();
}

//function to print all records
void Records::printRecords() {

}

//function to print single record
void Records::printSingleRec() {

}

//function to add student
void Records::addStudent() {

}

//function to delete student
void Records::deleteStudent() {

}

//function to display menu
void Records::displayMenu() {
	Student student;

	cout << "	Welcome to Florida Simple Student Record System" << endl;
	cout << "	-----------------------------------------------" << endl;
	cout << "Please select one of the following: " << endl;
	cout << " [0] Press 0 to quit" << endl;
	cout << " [1] Print all the records" << endl;
	cout << " [2] Print the record for a single student" << endl;
	cout << " [3] Add a student" << endl;
	cout << " [4] Delete a student" << endl;
	cout << " [5] Add a course to a student" << endl;
	cout << " [6] Delete a course from a student" << endl;

	cout << " Enter your selection: ";
	int sel1;
	cin >> sel1;

	switch (sel1) {
	case 0:
		break;
	case 1: printRecords();
		break;
	case 2: printSingleRec();
		break;
	case 3: addStudent();
		break;
	case 4: deleteStudent();
		break;
	case 5: 
		break;
	case 6: student.deleteCourse();
		break;
	default: cout << "That is not an option" << endl; break;
	}
	system("pause");
}


//gets number of students
uint32_t Records::getNumberOfStudents() {
	return numberOfStudents;
}

//sets number of students
void Records::setNumberOfStudents() {
	Records::numberOfStudents = numberOfStudents;
}

//gets average gpa
double Records::getAverageGpa() {
	return averageGpa;
}

//sets average gpa
void Records::setAverageGpa() {
	Records::averageGpa = averageGpa;
}

//default Records constructor
Records::Records() {

}

//Records constructor with parameters
Records::Records(uint32_t numberOfStudentsPar, double averageGpaPar) {
	numberOfStudents = numberOfStudentsPar;
	averageGpa = averageGpaPar;
}

//printing number of students and average gpa
ostream& operator << (ostream& os, const Records &p) {
	os << "Number of Students: " << p.numberOfStudents << "Average GPA: " << p.averageGpa << endl;
	return os;
}