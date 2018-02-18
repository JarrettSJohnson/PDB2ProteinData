#pragma once

#include <string>
#include <algorithm>
#include <cctype>


/*
Credit:	https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring/27788112
*/
static inline void ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
		return !std::isspace(ch);
	}));
}

static inline void rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch);
	}).base(), s.end());
}

static inline void trimStr(std::string &s) {
	ltrim(s);
	rtrim(s);
}