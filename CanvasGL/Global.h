#pragma once

#include "Canvas.h"

class Global {
public:

	static Canvas canvas;

	Global();
	~Global();
	static void Start(int argc, char *argv[]);

};

