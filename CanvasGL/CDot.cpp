#include "CDot.h"
#include <GL\glut.h>
#include "Drawer.h"


CDot::CDot(Coord coord) : coord(coord) {
	coords.emplace_back(&coord);
	SetPivot(&coord);
}
CDot::~CDot() {}

Coord CDot::GetCoord() { return coord; }
void CDot::SetCoord(Coord c) { this->coord = c; }

void CDot::Draw() {
	Drawer::DrawDot(coord);
}