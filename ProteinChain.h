#pragma once

#include <algorithm>

#include "AminoAcid.h"
#include "Parser.h"

class ProteinChain {
private:
	std::size_t length;
	std::vector<AminoAcid> residues;
	std::string seq;
	char chainID;
public:
	ProteinChain(std::vector<std::string>&& chainInfo);

	auto& getResidues() { return residues; }
	auto& getResidue(char resOneAA) {
		return *std::find_if(residues.begin(), residues.end(),
			[resOneAA](const AminoAcid& aa) {
			return aa.getOneAA() == resOneAA; });
	}
	auto& getChainID() const { return chainID; }
	auto& getSequence() const { return seq; }
};