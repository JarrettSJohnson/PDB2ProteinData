#include <iostream>
#include <string>
#include <experimental/filesystem>
#include <random>
#include <algorithm>
#include <vector>
#include "Protein.h"


int main(int argc, char** argv) {

	if (argc != 2) {
		std::cout << "Wrong num of arguments.\n";
	}
	std::string pdbFilename = argv[1];

	std::experimental::filesystem::path pdbFile(pdbFilename);
	Protein prot(pdbFile);
	std::cout << "Protein Name: " << pdbFile.stem() << std::endl;
	std::cout << "No. of Chains: " << prot.getChains().size() << std::endl;
	for (auto&& chain : prot.getChains()) {
		std::cout << "ChainID: " << chain.getChainID() << std::endl;
		std::cout << "Seq: " << chain.getSequence() << std::endl;
	}

	std::random_device rd;
	auto mt = std::mt19937(rd());
	//Retrieve Random Protein Chains' Residues Vector
	std::uniform_int_distribution<int> chainDist(0,
		prot.getChains().size() - 1);
	auto& randChain1ResVec = prot.getChains()[chainDist(mt)].getResidues();
	auto& randChain2ResVec = prot.getChains()[chainDist(mt)].getResidues();

	//Retreive Random Residues' Atoms Vector
	std::uniform_int_distribution<int> chain1ResDist(0,
		randChain1ResVec.size() - 1);
	std::uniform_int_distribution<int> chain2ResDist(0,
		randChain2ResVec.size() - 1);
	auto& randAtoms1Vec = randChain1ResVec[chain1ResDist(mt)].getAtoms();
	auto& randAtoms2Vec  = randChain2ResVec[chain2ResDist(mt)].getAtoms();

	//Retrieve Random Atoms' Coords
	std::uniform_int_distribution<int> atom1Dist(0,
		randAtoms1Vec.size() - 1);
	std::uniform_int_distribution<int> atom2Dist(0,
		randAtoms2Vec.size() - 1);
	auto& randAtom1 = randAtoms1Vec[atom1Dist(mt)].getCoord();
	auto& randAtom2 = randAtoms2Vec[atom2Dist(mt)].getCoord();
	
	//Finally print out this random distance
	std::cout << "Distance: " << randAtom1.distance(randAtom2) << 
		" Angstroms. " << std::endl;

	//Trying out the getByParam functions.
	auto& someCoord = prot.getChain('A').getResidue('L').getAtom("CB").getCoord();
	std::cout << someCoord << std::endl;
	return 0;
}