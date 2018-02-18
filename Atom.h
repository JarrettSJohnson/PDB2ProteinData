#pragma once

#include <string>
#include <unordered_map>

#include "Coord.h"

class Atom {
private:
	Coord coord;
	std::string pdbAtomType;
public:
	Atom(std::string&& atomLine);
	
	auto& getPDBAtomType() const { return pdbAtomType; }
	auto& getCoord() const { return coord; }
};