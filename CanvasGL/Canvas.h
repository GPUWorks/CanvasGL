#pragma once

#include <vector>
#include "CObject.h"

class Canvas {
public:
	std::vector<CObject*> objects;
	std::vector<CObject*> ghostObjects;

	Canvas();
	~Canvas();

	// Life Cyle
	void Start(int argc, char *argv[]);
	virtual void OnStart();
	virtual void OnUpdate();

	// Bindings
	virtual void OnMouseButtonPressed(int button, int state, int x, int y);
	virtual void OnKeyboardKeyPressed(unsigned char key, int x, int y);
	virtual void OnSpecialKeyPressed(int key, int x, int y);

	// Actions
	void PlaceObject(CObject*);
	void SelectObject(CObject*);
	void RemoveObject(CObject*);

private:
	CObject *selectedObject = nullptr;
	CObject *buldingObject = nullptr;
	bool isBuilding = false;
	Coord mousePos = {};

	// Life Cycle
	void Update();
	void Render();

	// Actions
	void StartObjectBuilding(CObject *object);
	void FinishObjectBuilding(bool success);

	// Binding
	friend void HandleMouseInput(int button, int state, int x, int y);
	friend void HandleKeyboardInput(unsigned char key, int x, int y);
	friend void HandleSpecialInput(int key, int x, int y);
	friend void HandlePassiveMouseInput(int x, int y);
	friend void _Render();

};

