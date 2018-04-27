#include "Color.h"


// Constructos and Destructos
Color::Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b), a(255) {}
Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : r(r), g(g), b(b), a(a) {}
Color::~Color() {}

// Setters and Getters
unsigned char	Color::GetRed()		{ return r; }
unsigned char	Color::GetGreen()	{ return g; }
unsigned char	Color::GetBlue()	{ return b; }
unsigned char	Color::GetAlpha()	{ return a; }

void Color::SetRed(unsigned char r)		{ this->r = r; }
void Color::SetGreen(unsigned char g)	{ this->g = g; }
void Color::SetBlue(unsigned char b)	{ this->b = b; }
void Color::SetAlpha(unsigned char a)			{ this->a = a; }

void Color::Set(unsigned char r, unsigned char g, unsigned char b) {
	SetRed(r); SetGreen(g); SetBlue(b);
}

void Color::Set(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
	SetRed(r); SetGreen(g); SetBlue(b); SetAlpha(a);
}


