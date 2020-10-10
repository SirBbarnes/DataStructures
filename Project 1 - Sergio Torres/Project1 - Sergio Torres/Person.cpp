//
//	Createcd by Sergio Torres on 1/22/19
//

#include "Person.h"

using namespace std;

//gets Person name
const string &Person::getName() {
	return name;
}

//sets Person name
void Person::setName(const string &name) {
	Person::name = name;
}

//gets Person age
uint32_t Person::getAge() {
	return age;
}

//sets Person age
void Person::setAge(uint32_t age) {
	Person::age = age;
}

//default Person constructor
Person::Person() {

}

//Person constructor with parameters
Person::Person(std::string namePar, uint32_t agePar) {
	name = namePar;
	age = agePar;
}

//printing name and age
ostream& operator << (ostream& os, const Person &p) {
	os << "Name: " << p.name << "\n Age: " << p.age << endl;
	return os;
}
