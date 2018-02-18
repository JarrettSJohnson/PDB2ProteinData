#pragma once

#include <vector>
#include <experimental/filesystem>
#include <algorithm>

#include "ProteinChain.h"
#include "Parser.h"


class Protein {
private:
	std::string PDBID;
	std::vector<ProteinChain> chains;
	Parser protParser;
public:
	Protein() = default;
	Protein(std::experimental::filesystem::path& pdbFile);

	auto& getChains() { return chains; }
	auto& getChain(char cID) {
		return *std::find_if(chains.begin(), chains.end(),
			[cID](const ProteinChain& c) { return c.getChainID() == cID; });
	}
	auto& getPDBID() const { return PDBID; }
};