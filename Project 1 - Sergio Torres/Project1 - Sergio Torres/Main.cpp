//
//	Created by Sergio Torres on 1/22/19
//

#include <iostream>
#include <fstream>
#include <string>
#include "Records.h"

using namespace std;


int main() {

	Records  records;
	//calls openStFile function from Records.h
	records.openStFile();
	//calls openCoFile function from Records.h
	records.openCoFile();
	//calls displayMenu function from Records.h
	records.displayMenu();
	return 0;

}
