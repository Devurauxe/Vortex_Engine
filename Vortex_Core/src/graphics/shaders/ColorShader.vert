#version 110

in vec2 position;
in vec4 color;

out vec4 fragmentColor;

void main()
{
	gl_Position = vec4(position, 0.0f, 1.0f);
	
	fragmentColor = color;
}