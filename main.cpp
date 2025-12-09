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

	// Milestone 2
	int highestCount = 0;
	for (const auto& pair : traffic) {
		if (pair.second > highestCount) {
			highestCount = pair.second;
		}
	}
	cout << "\n";
	
	cout << "Busiest airport(s) with count " << highestCount << ":\n";
	for (const auto& pair : traffic) {
		if (pair.second == highestCount) {
			cout << pair.first << " " << pair.second << "\n";
		}
	}
	cout << "\n";

	// Milestone 3
	const int NUM_RANGES = 2;
	const int RANGES[NUM_RANGES][2] = { {5, 8}, {9,12} };

	for (int i = 0; i < NUM_RANGES; ++i) {
		const int LOWER = RANGES[i][0];
		const int UPPER = RANGES[i][1];

		cout << "Airports with traffic in range [" << LOWER << ", " << UPPER << "]:\n";
		for (const auto& pair : traffic) {
			if (pair.second >= LOWER && pair.second <= UPPER) {
				cout << pair.first << " " << pair.second << "\n";
			}
		}

		cout << "\n";

	}

	return 0;
}