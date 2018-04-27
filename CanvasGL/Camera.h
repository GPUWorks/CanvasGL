#pragma once
class Camera {
public:
	Camera();
	~Camera();
	
	static float zoom;

	static void Initialize(float r, float g, float b, float a);
	static void Translate(float x, float y);
	static void Zoom(float value);

private:
	static float r, g, b, a;
	static float xOffset;
	static float yOffset;

	static void Refresh();

};

