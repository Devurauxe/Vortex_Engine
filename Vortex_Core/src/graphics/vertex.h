#pragma once

#include "Vector.h"
#include <GL/glew.h>

struct Position
{
	Vector position;
};

struct Color
{
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;

	void rgba(GLubyte _r, GLubyte _g, GLubyte _b, GLubyte _a)
	{
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}
};

struct Vertex
{
	Position vertexPos;
	Color color;
};