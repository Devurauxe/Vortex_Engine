#include "Sprite.h"

#include <iostream>

ShapeData Sprite::drawTriangle()
{
	ShapeData tri;

	Vertex vertices[3];

	vertices[0].vertexPos.position.vec4(1.0f, -1.0f, 0.0f, 1.0f);
	vertices[0].color.rgba(255, 0, 0, 255);

	vertices[1].vertexPos.position.vec4(-1.0f, -1.0f, 0.0f, 1.0f);
	vertices[1].color.rgba(255, 0, 0, 255);

	vertices[2].vertexPos.position.vec4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[2].color.rgba(255, 0, 0, 255);

	GLuint vertexBufferID;
	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLushort indeces[] = { 0, 1, 2 };
	GLuint indexArrayBufferID;
	glGenBuffers(1, &indexArrayBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeces), indeces, GL_STATIC_DRAW);

	return tri;
}

void Sprite::draw()
{
}