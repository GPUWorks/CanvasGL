#pragma once

#include "Canvas.h"

class CanvasApp {
public:
	static Canvas canvas;

	CanvasApp();
	~CanvasApp();
	static void Start(int argc, char *argv[]);

};

