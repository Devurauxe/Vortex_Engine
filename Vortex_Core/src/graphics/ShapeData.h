#pragma once

#include "vertex.h"

struct ShapeData
{
	ShapeData() : vertices(0), indeces(0) {}

	Vertex *vertices;
	GLushort *indeces;
	float vertexArraySize;
	float indecesArraySize;
};