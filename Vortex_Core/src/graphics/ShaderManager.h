#pragma once

#include <string>
#include <GL/glew.h>

class ShaderManager
{
public:
	ShaderManager();
	~ShaderManager();

	void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);
	void linkShaders();
	void addAttribute(const std::string& attributeName);
	void use();
	void unuse();

private:

	int _numAttributes;

	void compileShader(const std::string filePath, GLuint id);

	GLuint _vertexShaderID;
	GLuint _fragmentShaderID;

public:
	GLuint _programID;
};

