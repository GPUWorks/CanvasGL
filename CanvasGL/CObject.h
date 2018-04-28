#pragma once
#include "Coord.h"
#include <vector>

class CObject {
public:
	std::vector<Coord*> coords;

	CObject();
	~CObject();

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

	virtual void Draw() = 0;

private:
	Coord *pivot = nullptr;

};

