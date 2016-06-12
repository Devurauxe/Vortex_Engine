#pragma once

#include "ShapeData.h"

#include <GL/glew.h>

class Sprite
{
public:
	static ShapeData drawTriangle();
	static ShapeData drawCube();
	void draw();
};

