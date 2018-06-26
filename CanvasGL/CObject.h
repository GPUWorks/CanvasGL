#pragma once

#include <vector>
#include "Coord.h"
#include "CObject.h"
#include "Color.h"

class CObject {
public:
	std::vector<Coord*> coords;
	Color color;

	CObject();
	virtual ~CObject();

	virtual void OnStart();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void Destroy();

	void Move(float x, float y);
	void Translate(Coord c);
	void Rotate(float angle);
	void Scale(float sx, float sy);
	
	void SetPivot(Coord *c);
	Coord *GetPivot();

	virtual bool Belongs(Coord c);
	virtual void Draw() = 0;

private:
	Coord *pivot = nullptr;

};

