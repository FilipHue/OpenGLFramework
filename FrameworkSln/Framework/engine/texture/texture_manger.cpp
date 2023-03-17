#include "texture_manger.h"

TextureManger::TextureManger()
{
}

TextureManger::~TextureManger()
{
}

void TextureManger::LoadTexture2D(const char* filePath, const char* name)
{
	Texture2D* texture2D;

	texture2D = new Texture2D();
	texture2D->Init(filePath);

	textures2D[name] = texture2D;
}

Texture2D* TextureManger::GetTexture2D(const char* name)
{	
	return textures2D[name];
}

void TextureManger::LoadGridTexture()
{
	int width = 512;
	int height = 512;
	int channels = 3;
	int size = width * height * channels;
	unsigned char* imageData = new unsigned char[size];

	for (int i = 0; i < size; i++) {
		imageData[i] = rand() % 256;
	}

	Texture2D* texture2D;

	texture2D = new Texture2D();
	texture2D->Init(width, height, channels, imageData);

	textures2D["gridTexture"] = texture2D;
}

GLuint TextureManger::GetPixelFormat(unsigned int channels)
{
	return pixelFormat[channels];
}

GLuint TextureManger::GetInternalFormat(unsigned int channels)
{
	return internalFormat[0][channels];
}
