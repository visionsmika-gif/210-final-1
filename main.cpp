// COMSC-210 | Final Exam 1 | Mika Aquino
// IDE used: Visual Studio 2022

#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;


int main() {
	// Milestone 1
	const string FILE_NAME = "data.txt";
	map<string, int> traffic;

	ifstream inputFile(FILE_NAME);
	if (!inputFile) {
		cout << "ERROR: Unable to open the file " << FILE_NAME << ".\n";
		return 1;
	}

	string origin;
	string dest;
	while (inputFile >> origin) {
		inputFile >> dest;
		
		if (traffic.find(origin) == traffic.end()) {
			traffic[origin] = 0;
		}
		if (traffic.find(dest) == traffic.end()) {
			traffic[dest] = 0;
		}
		++traffic[origin];
		++traffic[dest];
	}

	cout << "All airport traffic counts:\n";
	for (const auto& pair : traffic) {
		cout << pair.first << " " << pair.second << "\n";
	}


	return 0;
}