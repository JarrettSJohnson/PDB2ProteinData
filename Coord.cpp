#include "Coord.h"

Coord::Coord(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}

float Coord::distance(const Coord& c) const {
	float dx = c.x - x;
	float dy = c.y - y;
	float dz = c.z - z;
	float sqdDist = dx*dx + dy*dy + dz*dz;
	return sqrt(sqdDist);
}

std::ostream& operator<<(std::ostream& os, const Coord& coord){
	return os << "(" << coord.x << ", " << coord.y << ", " << coord.z << ")";
}