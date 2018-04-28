#pragma once

#include "Coord.h"

class Camera {
public:
	Camera();
	~Camera();
	
	static float zoom;
	static float xOffset;
	static float yOffset;

	static void Initialize(float r, float g, float b, float a);
	static void Translate(float x, float y);
	static void Zoom(float value);
	static Coord ScreenToWorld(Coord c);

private:
	static float r, g, b, a;

	static void Refresh();

};

