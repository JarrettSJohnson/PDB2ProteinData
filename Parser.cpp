#include "Parser.h"

#include "utility.h"

void Parser::open(const std::string& file) {
	if (FILE.is_open()) {
		FILE.close();
		filename = file;
	}
	FILE.open(file);
	if (!FILE.is_open()) {
		std::cout << "Could not open " << file << std::endl;
		return;
	}
	getNextLine();

}

void Parser::open(const std::experimental::filesystem::path& filepath) {
	open(filepath.string());
}
void Parser::getNextLine() {
	if (!FILE.is_open()) {
		std::cout << filename << " has failed to open." << std::endl;
		return;
	}
	currLine.clear();
	std::string temp = "";
	getline(FILE, temp);
	currRawLine = temp;
	std::istringstream iss(temp);
	std::string tempL;
	while (iss >> tempL) {
		trimStr(tempL);
		currLine.push_back(tempL);
	}
	return;
}
std::string Parser::getNextInStr() {
	std::string str = currLine.front();
	currLine.pop_front();
	if (str.size() == 0) {
		std::cout << "Could not extract from line." << std::endl;
	}
	if (currLine.size() == 0) {
		getNextLine();
	}
	return str;
}
int Parser::getNextInInt() {
	return atoi(getNextInStr().c_str());
}
double Parser::getNextInDouble() {
	return atof(getNextInStr().c_str());
}
