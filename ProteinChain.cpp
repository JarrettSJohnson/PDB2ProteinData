#include "ProteinChain.h"

ProteinChain::ProteinChain(std::vector<std::string>&& chainInfo) {
	if (chainInfo.size() == 0) {
		return;
	}
	chainID = chainInfo[0].substr(21, 1).at(0);
	auto idx = std::stoi(chainInfo.front().substr(22, 4));
	std::vector<std::string> localResInfo;
	for (auto&& line : chainInfo) {
		auto thisIdx = std::stoi(line.substr(22, 4));
		if (thisIdx != idx) {
			auto& newRes = residues.emplace_back(std::move(localResInfo));
			seq += newRes.getOneAA();
			localResInfo.clear();
			idx = thisIdx;
			continue;
		}
		localResInfo.emplace_back(std::move(line));
	}
	//Handles the last case
	if (localResInfo.size() > 0) {
		residues.emplace_back(std::move(localResInfo));
	}

	length = residues.back().getResIdx() - residues.front().getResIdx() + 1;
}

