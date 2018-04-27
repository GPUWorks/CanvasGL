#pragma once
#include "Coord.h"
#include <vector>

class CObject {
public:
	std::vector<Coord*> coords;

	virtual void OnStart();
	virtual void OnUpdate();
	virtual void OnRender();

	void Translate(Coord c);
	void Rotate(float angle);
	void Scale(float sx, float sy);

	virtual void Draw() = 0;

};

