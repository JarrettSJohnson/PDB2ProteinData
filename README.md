# PDB2ProteinData
Converts PDB file to manageable objects broken down into protein molecule, chain, residue, atom, and coordinate.

# Build #

Tested on MSVC version 15.4.1 with C++17 features turned on

Tested on g++ version 7.2.1 with C++17 features turned on and linked to lstd++fs

g++ -std=c++17 *.cpp -O2 -lstdc++fs
