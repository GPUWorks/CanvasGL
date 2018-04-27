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
	virtual void OnMouseButtonPressed(int button, int state, int x, int y);
	virtual void OnKeyboardKeyPressed(unsigned char key, int x, int y);
	virtual void OnSpecialKeyPressed(int key, int x, int y);

	void PlaceObject(CObject*);
	void SelectObject(CObject*);

private:
	CObject *selectedObject = nullptr;

	void Update();
	void Render();
	friend void HandleMouseInput(int button, int state, int x, int y);
	friend void HandleKeyboardInput(unsigned char key, int x, int y);
	friend void HandleSpecialInput(int key, int x, int y);
	friend void HandlePassiveMouseInput(int x, int y);
	friend void _Render();

};

