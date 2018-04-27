#include "CLine.h"
#include <GL\glut.h>
#include <iostream>
#include "Drawer.h"

// Constructors and Desctructors
CLine::CLine(Coord start, Coord end) : start(start), end(end) {
	coords.emplace_back(&this->start);
	coords.emplace_back(&this->end);
	SetPivot(&this->start);
}
CLine::~CLine() {}

// Getters and Setters
Coord CLine::GetStart()	{ return start; }
Coord CLine::GetEnd()	{ return end; }

void CLine::Draw() {
	Drawer::DrawLine(start, end);
}
