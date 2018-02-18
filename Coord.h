#pragma once

#include <cmath>
#include <iostream>

struct Coord {
	float x = 0.0;
	float y = 0.0;
	float z = 0.0;

	Coord() = default;
	Coord(float _x, float _y, float _z);
	float distance(const Coord& c) const;
	friend std::ostream& operator<<(std::ostream& os, const Coord& coord);
	
};
