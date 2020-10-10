#pragma once
//
//	Created by Sergio Torres on 1/22/19
//

#ifndef Project1_STUDENT_H
#define Project1_STUDENT_H

#include "Person.h"
#include "Course.h"
#include <iostream>
#include <cstdint>
#include <vector>

class Student : public Person {

private:
	uint32_t totalCreditHours;
	uint32_t numberOfCourses;
	uint32_t uId;
	double gpa;

	std::vector<Course> courses;
public:

	Student();
	Student(uint32_t totalCreditHoursPar, uint32_t numberOfCoursesPar, uint32_t uIdPar, double gpaPar);

	uint32_t getTotalCreditHours();
	void setTotalCreditHours(uint32_t totalCreditHours);

	uint32_t getNumberOfCourses();
	void setNumberOfCourses(uint32_t numberOfCourses);

	uint32_t getUId();
	void setUId(uint32_t uId);

	double getGpa();
	void setGpa(double gpa);

	void addCourse();

	void deleteCourse();

	friend std::ostream& operator << (std::ostream &os, const Student &p);
};
#endif