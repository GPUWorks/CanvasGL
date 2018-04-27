#include "Drawer.h"
#include "Coord.h"
#include "GL\glut.h"



Drawer::Drawer() {}
Drawer::~Drawer() {}

void Drawer::DrawLine(Coord c1, Coord c2) {
	glBegin(GL_LINES);
		glColor3f(1,1,1);
		glVertex2f(c1.GetX() / glutGet(GLUT_WINDOW_WIDTH), c1.GetY() / glutGet(GLUT_WINDOW_HEIGHT));
		glVertex2f(c2.GetX() / glutGet(GLUT_WINDOW_WIDTH), c2.GetY() / glutGet(GLUT_WINDOW_HEIGHT));
	glEnd();
}

void Drawer::DrawLine(Coord c1, Coord c2, Color color) {
	glBegin(GL_LINES);
	glColor4ub(color.GetRed(), color.GetGreen(), color.GetBlue(), color.GetAlpha());
	glVertex2f(c1.GetX() / glutGet(GLUT_WINDOW_WIDTH), c1.GetY() / glutGet(GLUT_WINDOW_HEIGHT));
	glVertex2f(c2.GetX() / glutGet(GLUT_WINDOW_WIDTH), c2.GetY() / glutGet(GLUT_WINDOW_HEIGHT));
	glEnd();
}

void Drawer::DrawDot(Coord c) {
	glBegin(GL_POINTS);
		glColor3f(1,1,1);
		glPointSize(5.0f);
		glVertex2f(c.GetX() / glutGet(GLUT_WINDOW_WIDTH), c.GetY() / glutGet(GLUT_WINDOW_HEIGHT));
	glEnd();
}