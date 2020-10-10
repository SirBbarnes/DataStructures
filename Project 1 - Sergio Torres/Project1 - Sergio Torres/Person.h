#pragma once
//
//	Created by Sergio Torres on 1/22/19
//

#ifndef Project1_PERSON_H
#define Project1_PERSON_H

#include <iostream>
#include <cstdint>
#include <string>

class Person {

private:
	std::string name;
	uint32_t age;

public:

	//construct default person object
	Person();
	//construct person object
	Person(std::string namePar, uint32_t agePar);


	const std::string &getName();
	void setName(const std::string &name);

	uint32_t getAge();
	void setAge(uint32_t age);

	friend std::ostream& operator << (std::ostream &os, const Person &p);
};

#endif //Project1_PERSON_H
