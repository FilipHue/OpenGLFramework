#include "texture2D.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Texture2D::Texture2D()
{
	width = 0;
	height = 0;
	channels = 0;

	textureID = 0;

	imageData = nullptr;
}

Texture2D::~Texture2D()
{
}

void Texture2D::Init(const char* filePath)
{
	imageData = stbi_load(filePath, &width, &height, &channels, 0);
	if (imageData == NULL) {
		std::cout << "Error at initializing texture: " << filePath << std::endl;
		return;
	}

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, TextureManger::GetInternalFormat(channels), width, height, 0, TextureManger::GetPixelFormat(channels), GL_UNSIGNED_BYTE, imageData);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(imageData);
}

unsigned int Texture2D::GetTextureID()
{
	return textureID;
}
