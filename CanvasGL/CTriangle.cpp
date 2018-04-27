#include "CTriangle.h"
#include <iostream>
#include <GL\glut.h>
#include "Drawer.h"


CTriangle::CTriangle(Coord c1, Coord c2, Coord c3) : c1(c1), c2(c2), c3(c3) {
	coords.emplace_back(&c1);
	coords.emplace_back(&c2);
	coords.emplace_back(&c3);
}
CTriangle::~CTriangle() {}

void CTriangle::Draw() {
	std::cout << "Drawing triangle" << std::endl;
	Drawer::DrawLine(c1, c2);
	Drawer::DrawLine(c2, c3);
	Drawer::DrawLine(c3, c1);
}
