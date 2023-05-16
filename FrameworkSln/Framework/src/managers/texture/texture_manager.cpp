#include "texture_manager.h"

#include <iostream>

void TextureManger::LoadTexture2D(std::string filePath, std::string name, std::string type)
{
	Texture2D* texture2D;

	texture2D = new Texture2D();
	texture2D->Init(filePath);

	textures_2D[name] = texture2D;
	textures_type_2D[name] = type;
}

Texture2D* TextureManger::GetTexture2D(std::string name)
{
	return textures_2D[name];
}

std::string TextureManger::GetTexture2DType(std::string name)
{
	return textures_type_2D[name];
}

GLuint TextureManger::GetPixelFormat(unsigned int channels)
{
	return pixel_format[channels];
}

GLuint TextureManger::GetInternalFormat(unsigned int channels)
{
	return internal_format[0][channels];
}
