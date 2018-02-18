#include "AminoAcid.h"

AminoAcid::AminoAcid(std::vector<std::string>&& aaInfo) {
	if (aaInfo.size() == 0) {
		return;
	}
	resIdx = std::stoi(aaInfo.front().substr(22, 4));
	threeAA = aaInfo.front().substr(17, 3);
	oneAA = threeToOneAA[threeAA];
	for (auto&& line : aaInfo) {
		atoms.emplace_back(std::move(line));
	}
}


std::unordered_map<std::string, char> AminoAcid::threeToOneAA{
	{ "ALA", 'A' },
	{ "CYS", 'C' },
	{ "ASP", 'D' },
	{ "GLU", 'E' },
	{ "PHE", 'F' },
	{ "GLY", 'G' },
	{ "HIS", 'H' },
	{ "ILE", 'I' },
	{ "LYS", 'K' },
	{ "LEU", 'L' },
	{ "MET", 'M' },
	{ "ASN", 'N' },
	{ "PRO", 'P' },
	{ "GLN", 'Q' },
	{ "ARG", 'R' },
	{ "SER", 'S' },
	{ "THR", 'T' },
	{ "VAL", 'V' },
	{ "TRP", 'W' },
	{ "TYR", 'Y' },
};