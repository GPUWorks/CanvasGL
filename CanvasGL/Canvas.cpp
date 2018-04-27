#include <GL\glut.h>
#include "Canvas.h"
#include <iostream>
#include "CanvasApp.h"
#include "CLine.h"
#include "CTriangle.h"
#include "CDot.h"
#include "Drawer.h"

Canvas CanvasApp::canvas = {};

Canvas::Canvas() : zoom(1.0f), xOffset(0.0f), yOffset(0.0f) {
	objects = {};
}


Canvas::~Canvas() {

}

void Canvas::Start(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Canvas");
	Init2D(0, 0, 0);
	glutDisplayFunc(_Render);
	glutMouseFunc(HandleMouseInput);
	glutKeyboardFunc(HandleKeyboardInput);
	glutSpecialFunc(HandleSpecialInput);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	OnStart();
	CLine *line1 = new CLine(Coord(300, 300), Coord(500, 700));
	CTriangle *tri = new CTriangle(Coord(1000,5000), Coord(2000,3000), Coord(4000,3500));
	PlaceObject(line1);
	PlaceObject(tri);

	glutMainLoop();

}

void Canvas::Update() {
	OnUpdate();
	for (auto &obj : objects)
		obj->OnUpdate();
}

void Canvas::Render() {
	CanvasApp::canvas.DrawGrid();
	for (auto &obj : objects) {
		obj->OnRender();
		obj->Draw();
	}
}

void Canvas::PlaceObject(CObject *object) {
	objects.emplace_back(object);
	object->OnStart();
}

void Canvas::Init2D(float r, float g, float b) {
	glClearColor(r, g, b, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xOffset, zoom + xOffset, yOffset, zoom + yOffset);
	glMatrixMode(GL_MODELVIEW);
}

void _Render() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	CanvasApp::canvas.Update();
	CanvasApp::canvas.Render();

	glutPostRedisplay();
	glFlush();
}

void Canvas::OnStart() {}
void Canvas::OnUpdate() {}

void HandleMouseInput(int button, int state, int x, int y) {
	
	// Scroll Event
	if ((button == 3) || (button == 4)) {
		if (state == GLUT_UP) return; // Disregard redundant GLUT_UP events
		if (button == 3) {
			CanvasApp::canvas.Zoom(0.1f);
		} else {
			CanvasApp::canvas.Zoom(-0.1f);
		}
	}

}

void HandleKeyboardInput(unsigned char key, int x, int y) {


}

void HandleSpecialInput(int key, int x, int y) {

	if (key == GLUT_KEY_RIGHT) {
		CanvasApp::canvas.MoveX(0.01);
	}

	if (key == GLUT_KEY_LEFT) {
		CanvasApp::canvas.MoveX(-0.01);
	}

	if (key == GLUT_KEY_UP) {
		CanvasApp::canvas.MoveY(0.01);
	}

	if (key == GLUT_KEY_DOWN) {
		CanvasApp::canvas.MoveY(-0.01);
	}

}

void Canvas::OnMouse() {

}

void Canvas::OnKeyboard() {

}

void Canvas::DrawGrid() {

	Color color = Color(255, 255, 255, 15);
	float nLines = 100000, interval = 100;

	for (int i = -nLines; i < nLines; i += interval)
		Drawer::DrawLine(Coord(-999999, i), Coord(999999, i), color);
	for (int i = -nLines; i < nLines; i += interval)
		Drawer::DrawLine(Coord(i, -999999), Coord(i, 999999), color);

	Drawer::DrawLine(Coord(-999999, 100), Coord(999999, 100), Color(255,0,0,100));
	Drawer::DrawLine(Coord(100, -999999), Coord(100, 999999), Color(255, 0, 0, 100));

}

void Canvas::MoveX(float offset) {
	this->xOffset += offset;
	Init2D(0, 0, 0);
}

void Canvas::MoveY(float offset) {
	this->yOffset += offset;
	Init2D(0, 0, 0);
}

void Canvas::Zoom(float zoom) {
	this->zoom -= zoom;
	Init2D(0, 0, 0);
}