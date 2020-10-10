//
//	Created by Sergio Torres on 1/22/19
//

#include "Student.h"

using namespace std;

//gets Total Credit Hours
uint32_t Student::getTotalCreditHours() {
	return totalCreditHours;
}

//sets Total Credit Hours
void Student::setTotalCreditHours(uint32_t totalCreditHours) {
	Student::totalCreditHours = totalCreditHours;
}

//gets Number of Courses
uint32_t Student::getNumberOfCourses() {
	return numberOfCourses;
}

//sets Number of Courses
void Student::setNumberOfCourses(uint32_t numberOfCourses) {
	Student::numberOfCourses = numberOfCourses;
}

//gets Student Code
uint32_t Student::getUId() {
	return uId;
}

//sets Students Code
void Student::setUId(uint32_t uId) {
	Student::uId = uId;
}

//gets Gpa
double Student::getGpa() {
	return gpa;
}

//sets Gpa
void Student::setGpa(double gpa) {
	Student::gpa = gpa;
}

//adds a course to the courses vector
void Student::addCourse () {

}

//deletes a course from the courses vector
void Student::deleteCourse() {
	cout << "Which course would you like to delete? " << endl;
	string input;
	cin >> input;




}


//Default Student constructor
Student::Student() {

}

//Student constructor with parameters
Student::Student(uint32_t totalCreditHoursPar, uint32_t numberOfCoursesPar, uint32_t uIdPar, double gpaPar) {
	totalCreditHours = totalCreditHoursPar;
	numberOfCourses = numberOfCoursesPar;
	uId = uIdPar;
	gpa = gpaPar;
}

//printing total credit hours, number of courses, student code and gpa
ostream& operator << (ostream& os, const Student &p) {
	os << "Total Credit Hours: " << p.totalCreditHours << "\nNumber Of Courses: " << p.numberOfCourses << "\nUniversity Id: " << p.uId << "\nGpa: " << p.gpa << endl;
	return os;
}
