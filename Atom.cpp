#include "Atom.h"

#include "utility.h"

Atom::Atom(std::string&& atomLine) {
	pdbAtomType = atomLine.substr(12, 4);
	trimStr(pdbAtomType);
	float x = std::stof(atomLine.substr(30, 8));
	float y = std::stof(atomLine.substr(38, 8));
	float z = std::stof(atomLine.substr(46, 8));
	coord = Coord(x, y, z);
}

