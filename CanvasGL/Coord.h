#pragma once
class Coord {
public:
	Coord();
	Coord(float x, float y);
	~Coord();

	float GetX();
	float GetY();
	void SetX(float x);
	void SetY(float y);
	void Set(float x, float y);

private:
	float x, y;

};

