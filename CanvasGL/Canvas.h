#pragma once

#include <vector>
#include "CObject.h"

class Canvas {
public:
	std::vector<CObject*> objects;

	Canvas();
	~Canvas();
	
	void Start(int argc, char *argv[]);
	virtual void OnStart();
	virtual void OnUpdate();
	virtual void OnMouse();
	virtual void OnKeyboard();

	void PlaceObject(CObject*);
	void Zoom(float zoom);
	void MoveX(float offset);
	void MoveY(float offset);

private:
	float zoom;
	float xOffset;
	float yOffset;

	virtual void Init2D(float r, float g, float b);
	void Update();
	void Render();
	void DrawGrid();
	friend void HandleMouseInput(int button, int state, int x, int y);
	friend void HandleKeyboardInput(unsigned char key, int x, int y);
	friend void HandleSpecialInput(int key, int x, int y);
	friend void _Render();

};

