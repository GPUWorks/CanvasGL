#include "CTriangle.h"
#include <iostream>
#include <GL\glut.h>
#include "Drawer.h"


CTriangle::CTriangle(Coord c1, Coord c2, Coord c3) : c1(c1), c2(c2), c3(c3) {
	coords.emplace_back(&this->c1);
	coords.emplace_back(&this->c2);
	coords.emplace_back(&this->c3);
	SetPivot(&this->c1);
}
CTriangle::~CTriangle() {}

void CTriangle::Draw() {
	Drawer::DrawLine(c1, c2);
	Drawer::DrawLine(c2, c3);
	Drawer::DrawLine(c3, c1);
}
