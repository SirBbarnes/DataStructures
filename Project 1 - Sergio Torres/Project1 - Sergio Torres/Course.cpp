//
//	Created by Sergio Torres on 1/22/19
//

#include "Course.h"

using namespace std;

//gets student code
const string &Course::getCode() {
	return code;
}

//sets student code
void Course::setCode(const string &code) {
	Course::code = code;
}

//gets course title
const string &Course::getTitle() {
	return title;
}

//sets course title
void Course::setTitle(const string &title) {
	Course::title = title;
}

//gets student grade
double Course::getGrade() {
	return grade;
}

//sets student code
void Course::setGrade(double grade) {
	Course::grade = grade;
}

//gets credit hour
uint8_t Course::getCreditHour() {
	return creditHour;
}

//sets credit hour
void Course::setCreditHour(uint8_t creditHour) {
	Course::creditHour = creditHour;
}

//function to set all values for course
void Course::setAll() {
	cout << "Enter Student Code: ";
	string cc1;
	cin >> cc1;

	cout << "Enter Title of Course: ";
	string tc1;
	cin >> tc1;

	cout << "Enter Course Grade: ";
	double gr1;
	cin >> gr1;

	cout << "Enter Course Credit Hour(s): ";
	uint8_t ch1;
	cin >> ch1;
}

//default course constructor
Course::Course() {

}

//Course constructor with parameters
Course::Course(std::string codePar, std::string titlePar, double gradePar, uint8_t creditHourPar) {
	code = codePar;
	title = titlePar;
	grade = gradePar;
	creditHour = creditHourPar;
}

//printing out course code, course title, course grade and credit hour
ostream& operator << (ostream& os, const Course &p) {
	os << "Course Code: " << p.code << ", Course Title: " << p.title << ", Course Grade: " << p.grade << ", Course Credit Hour(s): " << p.creditHour << endl;
	return os;
}
