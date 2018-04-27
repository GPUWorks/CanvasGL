#include "CObject.h"
#include <iostream>
#include <glm\matrix.hpp>
#include <glm\glm.hpp>

void CObject::OnStart() {}
void CObject::OnUpdate() {}
void CObject::OnRender() {}
void CObject::Draw() {}

void CObject::Move(float x, float y) {
	for (auto &c : coords)
		c->Set(c->GetX() + x, c->GetY() + y);
}

void CObject::Translate(Coord c) {

}

void CObject::Rotate(float angle) {
	
	float cos = glm::cos(angle), sin = glm::sin(angle);
	glm::mat2 r = {
		cos,	-sin,
		sin,	cos
	};

	Coord *c1 = coords.at(0);
	Coord *c2 = coords.at(1);

	float x1 = c1->GetX(), x2 = c2->GetX(), y1 = c1->GetY(), y2 = c2->GetY();

	glm::mat2 mobj = {
		0, 0,
		x2 - x1, y2 - y1
	};

	glm::mat2 resp = r * mobj;

	c1->Set(x1, y1);
	c2->Set(resp[1][0] + x1, resp[1][1] + y1);

}

void CObject::Scale(float sx, float sy) {

}

void CObject::SetPivot(Coord *c) {
	this->pivot = c;
}

Coord *CObject::GetPivot() {
	return pivot;
}