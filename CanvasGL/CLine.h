#pragma once

#include "CObject.h"
#include "Coord.h"

class CLine : virtual public CObject {
private:
	Coord start;
	Coord end;

public:
	CLine(Coord start, Coord end);
	~CLine();

	Coord GetStart();
	Coord GetEnd();
	virtual void Draw() override;

};

