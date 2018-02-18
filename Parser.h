#pragma once

#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <deque>
#include <experimental/filesystem>

/**
*	PARSER.H
*	~PARSER CLASS~
*	CREATED BY JARRETT S. JOHNSON
*	UPDATED DECEMBER 2017
*	YANG ZHANG LABORATORY
* 	UNIVERSITY OF MICHIGAN, ANN ARBOR CAMPUS
*	Desc: C++ Parser class to manage parsing files into simple C/C++ types and objects
*	Note: Use GCC versions 5 and newer
*	Note: std::deque preferred over std::queue due to std::queue's lack of .clear(), and inability to
*		be used in ranged-based for's.
*
*/


class Parser {
private:
	std::string filename;
	std::deque<std::string> currLine;
	std::string currRawLine;
	std::ifstream FILE;
public:
	Parser() = default;

	void open(const std::string& file);
	void open(const std::experimental::filesystem::path& file);
	void close() { FILE.close(); }
	inline std::string getFileName() const noexcept { return filename; }
	void getNextLine();
	std::string getNextInStr();
	int getNextInInt();
	double getNextInDouble();

	bool isOpen() { return FILE.is_open(); }
	bool eof() { return FILE.is_open() && FILE.eof(); }

	std::string getCurrLine() const noexcept { return currRawLine; }
	auto& getCurrLineAsWords() const noexcept { return currLine; }
};
