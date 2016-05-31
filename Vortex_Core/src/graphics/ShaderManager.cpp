#include "ShaderManager.h"
#include "error_handler.h"

#include <iostream>
#include <fstream>
#include <vector>

ShaderManager::ShaderManager() : _numAttributes(0), _programID(0), _vertexShaderID(0), _fragmentShaderID(0)
{

}


ShaderManager::~ShaderManager()
{
}

void ShaderManager::compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath)
{
	//Vertex and fragment shaders are successfully compiled.
	//Now time to link them together into a program.
	//Get a program object.
	_programID = glCreateProgram();

	// Create the vertex shader
	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	// Check if the vertex shader was created
	if (_vertexShaderID == 0)
		fatalError("Vertex shader failed to be created!");

	// Create the fragment shader
	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	// Check if the fragment shader was created
	if (_fragmentShaderID == 0)
		fatalError("Fragment shader failed to be created!");

	// Compile the necessary shaders
	compileShader(vertexShaderFilePath, _vertexShaderID);
	compileShader(fragmentShaderFilePath, _fragmentShaderID);
}

void ShaderManager::linkShaders()
{
	//Attach our shaders to our program
	glAttachShader(_programID, _vertexShaderID);
	glAttachShader(_programID, _fragmentShaderID);

	//Link our program
	glLinkProgram(_programID);

	//Note the different functions here: glGetProgram* instead of glGetShader*.
	GLint isLinked = 0;
	glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<char> errorLog(maxLength);
		glGetProgramInfoLog(_programID, maxLength, &maxLength, &errorLog[0]);

		//We don't need the program anymore.
		glDeleteProgram(_programID);
		//Don't leak shaders either.
		glDeleteShader(_vertexShaderID);
		glDeleteShader(_fragmentShaderID);

		std::printf("%s\n", &(errorLog[0]));
		fatalError("Shaders failed to link!");
	}

	//Always detach and delete shaders after a successful link.
	glDetachShader(_programID, _vertexShaderID);
	glDetachShader(_programID, _fragmentShaderID);
	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);
}

void ShaderManager::addAttribute(const std::string& attributeName)
{
	glBindAttribLocation(_programID, _numAttributes++, attributeName.c_str());
}

void ShaderManager::use()
{
	glUseProgram(_programID);

	for (int i = 0; i < _numAttributes; i++)
	{
		glEnableVertexAttribArray(i);
	}
}

void ShaderManager::unuse()
{
	glUseProgram(0);

	for (int i = 0; i < _numAttributes; i++)
	{
		glDisableVertexAttribArray(i);
	}
}

void ShaderManager::compileShader(const std::string filePath, GLuint id)
{
	// Open the shader file to prepare for compilation
	std::ifstream shaderFile(filePath);
	// Check if the shader file failed to open
	if (shaderFile.fail())
		fatalError("Failed to open " + filePath);

	// Create variables to hold the shader code for compilation, which in this
	// case will only be one string variable
	std::string fileContents = "";
	std::string line;

	// Get the lines of shader code and format the lines correctly
	while (std::getline(shaderFile, line))
		fileContents += line + "\n";

	// Close the vertex shader file
	shaderFile.close();

	// Identify the source of the shader and compile it
	const char* contentsPtr = fileContents.c_str();
	glShaderSource(id, 1, &contentsPtr, nullptr);

	glCompileShader(id);

	GLint success = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

	// Check for failure to compile shader
	if (success == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

		// Provide the infolog
		// Exit with failure
		glDeleteShader(id); // Don't leak the shader

		std::printf("%s\n", &(errorLog[0]));
		fatalError("Shader " + filePath + " failed to compile");
	}
}