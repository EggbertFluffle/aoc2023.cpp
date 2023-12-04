#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctype.h>	

std::string spellings[] = {
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

std::vector<std::string> LoadFileData(const char* path);
int getCalibratedLine(std::string line);
int charToInt(char c);

int main() {
	std::vector<std::string> lines = LoadFileData("input");
	// std::vector<std::string> lines = LoadFileData("example");
	int sum = 0;

	for(int i = 0; i < lines.size(); i++) {
		sum += getCalibratedLine(lines[i]);
	}

	std::cout << sum << "\n";

	return 0;
}

int getCalibratedLine(std::string line) {
	std::vector<u_int8_t> nums;
	for(int i = 0; i < line.size(); i++) {
		if(isdigit(line.at(i))) nums.push_back(charToInt(line.at(i)));
		for(int s = 0; s < 9; s++) {
			if(line.substr(i).find(spellings[s]) == 0) {
				nums.push_back(s + 1);
			}
		}	
	}

	return (nums.front() * 10) + nums.back();
}

std::vector<std::string> LoadFileData(const char* path) {
	using namespace std;
	fstream file;
	file.open(path);

	vector<string> lines;
	string currentLine;

	if(file.is_open() == false) {
		cout << "File could not be opened" << "\n";
		return lines;
	}

	while(getline(file, currentLine)) {
		lines.push_back(currentLine);
	}

	file.close();
	return lines;
}

int charToInt(char c) {
	return c - '0';
}
