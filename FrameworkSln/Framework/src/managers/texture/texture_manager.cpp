#include "texture_manager.h"

void TextureManger::LoadTexture2D(const char* filePath, const char* name)
{
	Texture2D* texture2D;

	texture2D = new Texture2D();
	texture2D->Init(filePath);

	textures_2D[name] = texture2D;
}

Texture2D* TextureManger::GetTexture2D(const char* name)
{
	return textures_2D[name];
}

GLuint TextureManger::GetPixelFormat(unsigned int channels)
{
	return pixel_format[channels];
}

GLuint TextureManger::GetInternalFormat(unsigned int channels)
{
	return internal_format[0][channels];
}
