#pragma once
class Color {
public:
	Color(unsigned char r, unsigned char g, unsigned char b);
	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	~Color();

	unsigned char GetRed();
	unsigned char GetGreen();
	unsigned char GetBlue();
	unsigned char GetAlpha();

	void SetRed(unsigned char r);
	void SetGreen(unsigned char g);
	void SetBlue(unsigned char b);
	void SetAlpha(unsigned char a);

	void Set(unsigned char r, unsigned char g, unsigned char b);
	void Set(unsigned char r, unsigned char g, unsigned char b, unsigned char a);


private:
	unsigned char r, g, b;
	unsigned char a;

};

