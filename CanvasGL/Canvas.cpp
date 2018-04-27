#include <GL\glut.h>
#include "Canvas.h"
#include <iostream>
#include "CanvasApp.h"
#include "CLine.h"
#include "CTriangle.h"
#include "CDot.h"
#include "Drawer.h"
#include "Camera.h"

Canvas CanvasApp::canvas = {};

Canvas::Canvas() : objects({}) {}
Canvas::~Canvas() {}

void Canvas::Start(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Canvas");

	Camera::Initialize(0,0,0,0);
	Camera::Translate(-0.36f, -0.50f);
	Camera::Zoom(-1);

	glutDisplayFunc(_Render);
	glutMouseFunc(HandleMouseInput);
	glutKeyboardFunc(HandleKeyboardInput);
	glutSpecialFunc(HandleSpecialInput);
	glutPassiveMotionFunc(HandlePassiveMouseInput);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	OnStart();

	PlaceObject(new CLine(Coord(300, 300), Coord(500, 700)));
	PlaceObject(new CLine(Coord(500, 750), Coord(900, 100)));
	PlaceObject(new CTriangle(Coord(1600, 200), Coord(1600, 400), Coord(1000, 250)));
		
	glutMainLoop();

}

void Canvas::Update() {
	OnUpdate();
	for (auto &obj : objects)
		obj->OnUpdate();
}

void Canvas::Render() {
	Drawer::DrawGrid(100, Color(255, 255, 255, 15));
	for (auto &obj : objects) {
		obj->OnRender();
		obj->Draw();
		if (selectedObject == obj && obj->GetPivot() != nullptr) Drawer::DrawPivot(*obj->GetPivot());
	}
}

void Canvas::PlaceObject(CObject *object) {
	objects.emplace_back(object);
	object->OnStart();
}

void Canvas::SelectObject(CObject *object) {
	this->selectedObject = object;
}

void HandleMouseInput(int button, int state, int x, int y) {
	
	// Scroll Event
	if ((button == 3) || (button == 4)) {
		if (button == 3) {
			Camera::Zoom(0.1f);
		} else {
			Camera::Zoom(-0.1f);
		}
	}

	CanvasApp::canvas.OnMouseButtonPressed(button, state, x, y);

}

void HandleKeyboardInput(unsigned char key, int x, int y) {

	CObject *selected = CanvasApp::canvas.selectedObject;
	if (selected != nullptr) {
	
		float moveSpeed = 10;
		if (key == 'w') {
			selected->Move(0, moveSpeed);
		}

		if (key == 's') {
			selected->Move(0, -moveSpeed);
		}

		if (key == 'd') {
			selected->Move(moveSpeed, 0);
		}


		if (key == 'a') {
			selected->Move(-moveSpeed, 0);
		}

		if (key == 27) { // ESC
			CanvasApp::canvas.selectedObject = nullptr;
		}

	}

	if (key == 9) { // TAB
		std::cout << "TAB" << std::endl;
		Canvas &canvas = CanvasApp::canvas;

		std::cout << (canvas.selectedObject == nullptr) << " && " << !canvas.objects.empty() << std::endl;
		if (canvas.selectedObject == nullptr && !canvas.objects.empty())
			canvas.SelectObject(canvas.objects.at(0));

		for (int i = 0; i < canvas.objects.size(); i++)
			if (canvas.objects.at(i) == canvas.selectedObject) {
				std::cout << "TRUE ";
				if (i != canvas.objects.size() - 1) canvas.SelectObject(canvas.objects.at(i + 1));
				else canvas.SelectObject(canvas.objects.at(0));
				break;
			}
		std::cout << std::endl << std::endl;
	}

	CanvasApp::canvas.OnKeyboardKeyPressed(key, x, y);
}

float speed = 0.01f;
void HandleSpecialInput(int key, int x, int y) {

	if (key == GLUT_KEY_RIGHT) {
		Camera::Translate(speed * Camera::zoom, 0);
	}

	if (key == GLUT_KEY_LEFT) {
		Camera::Translate(-speed * Camera::zoom, 0);
	}

	if (key == GLUT_KEY_UP) {
		Camera::Translate(0, speed * Camera::zoom);
	}

	if (key == GLUT_KEY_DOWN) {
		Camera::Translate(0, -speed * Camera::zoom);
	}

	CanvasApp::canvas.OnSpecialKeyPressed(key, x, y);

}

void HandlePassiveMouseInput(int x, int y) {

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
void Canvas::OnMouseButtonPressed(int button, int state, int x, int y) {}
void Canvas::OnKeyboardKeyPressed(unsigned char key, int x, int y) {}
void Canvas::OnSpecialKeyPressed(int key, int x, int y) {}