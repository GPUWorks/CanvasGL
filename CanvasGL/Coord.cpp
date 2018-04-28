#include "Coord.h"
#include <GL\glut.h>

Coord::Coord() : x(0), y(0) {}

Coord::Coord(float x, float y) {
	Set(x, y);
}


Coord::~Coord() {
}

float Coord::GetX() {
	return x;
}

float Coord::GetY() {
	return y;
}

void Coord::SetX(float x) {
	this->x = x;
}

void Coord::SetY(float y) {
	this->y = y;
}

void Coord::Set(float x, float y) {
	SetX(x);
	SetY(y);
}
