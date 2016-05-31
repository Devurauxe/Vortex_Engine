#pragma once

#include "texture.h"

#include <string>

class ImageLoader
{
public:
	static Texture loadPNG(std::string filePath);
};

