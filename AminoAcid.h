#pragma once

#include <vector>
#include <algorithm>
#include "Atom.h"

class AminoAcid {
private:
	std::string threeAA;
	char oneAA;
	std::vector<Atom> atoms;
	unsigned int resIdx;

	static std::unordered_map<std::string, char> threeToOneAA;

public:
	AminoAcid(std::vector<std::string>&& aaInfo);

	auto& getResIdx() const { return resIdx; }
	auto& getAtoms() { return atoms; }
	auto& getAtom(std::string pdbAtomType) {
		return *std::find_if(atoms.begin(), atoms.end(),
			[pdbAtomType](const Atom& a) {
			return a.getPDBAtomType() == pdbAtomType; });
	}

	auto& getOneAA() const { return oneAA; }
	auto& getThreeAA() const { return threeAA; }
};