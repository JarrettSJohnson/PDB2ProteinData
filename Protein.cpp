#include "Protein.h"

Protein::Protein(std::experimental::filesystem::path& pdbFile) {
	protParser.open(pdbFile);

	if (!protParser.isOpen()) {
		return;
	}
	auto line = protParser.getCurrLine();
	auto currChain = ' ';
	std::vector<std::string> localProtChainStr;
	while (!protParser.eof()) {
		line = protParser.getCurrLine();
		auto lineSize = line.size();
		if (lineSize > 4 && line.substr(0, 4) == "ATOM") {
			auto thisChain = line.substr(21, 1)[0];
			if (lineSize > 22 && thisChain != currChain) {
					currChain = thisChain;
			}
			localProtChainStr.emplace_back(protParser.getCurrLine());
		}
		else if (lineSize > 3 && line.substr(0, 3) == "TER") {
			if (localProtChainStr.size() > 0) {
				chains.emplace_back(std::move(localProtChainStr)); //Avoids copy
				localProtChainStr.clear();
			}
		}
		protParser.getNextLine();
	}
	protParser.close();
}
