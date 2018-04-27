#pragma once

#include "Coord.h"
#include "Color.h"

class Drawer {
public:
	Drawer();
	~Drawer();
	
	static void DrawLine(Coord c1, Coord c2);
	static void DrawLine(Coord c1, Coord c2, Color color);
	static void DrawDot(Coord coord);

};

