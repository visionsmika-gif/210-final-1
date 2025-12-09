// COMSC-210 | Final Exam 1 | Mika Aquino
// IDE used: Visual Studio 2022

#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;


int main() {
	const string FILE_NAME = "data.txt";
	map<string, int> traffic;

	ifstream inputFile(FILE_NAME);
	if (!inputsFile) {
		cout << "ERROR: Unable to open the file " << FILE_NAME << ".\n";
		return 1;
	}

	string origin;
	string dest;
	while (inputFile >> origin) {
		inputFile >> dest;
		
		traffic[origin] = 0;
		traffic[dest] = 0;


	}



	return 0;
}