#version 110

in vec4 position;
in vec4 color;

out vec4 fragmentColor;

void main()
{
	gl_Position = position;
	
	fragmentColor = color;
}