#pragma once
//
//	Created by Sergio Torres on 1/22/19
//

#ifndef Project1_RECORDS_H
#define Project1_RECORDS_H

#include <iostream>
#include <cstdint>
#include "Student.h"


class Records: public Student{
private: 
	uint32_t numberOfStudents;
	double averageGpa;

	std::vector<Student> students;
public: 
	void displayMenu();
	void openStFile();
	void openCoFile();
	void printRecords();
	void printSingleRec();
	void addStudent();
	void deleteStudent();

	Records();
	Records(uint32_t numberOfStudentsPar, double averageGpaPar);

	uint32_t getNumberOfStudents();
	void setNumberOfStudents();

	double getAverageGpa();
	void setAverageGpa();

	friend std::ostream& operator << (std::ostream &os, const Records &p);
};
#endif //Project1_RECORDS_H