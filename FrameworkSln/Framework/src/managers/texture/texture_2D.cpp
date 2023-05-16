#include "texture_2D.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Texture2D::Texture2D()
{
	width = 0;
	height = 0;
	channels = 0;

	texture_id = 0;

	image_data = nullptr;
}

void Texture2D::Init(std::string file_path)
{
	image_data = stbi_load(file_path.c_str(), &width, &height, &channels, 0);
	if (image_data == NULL) {
		TEXTURE_WARN("Error at initializing texture: {}", file_path);
		return;
	}

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, TextureManger::GetInternalFormat(channels), width, height, 0, TextureManger::GetPixelFormat(channels), GL_UNSIGNED_BYTE, image_data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(image_data);
}

void Texture2D::Init(int width, int height, int channels, unsigned char* image_data)
{
	this->width = width;
	this->height = height;
	this->channels = channels;

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, TextureManger::GetInternalFormat(channels), width, height, 0, TextureManger::GetPixelFormat(channels), GL_UNSIGNED_BYTE, image_data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
}

unsigned int Texture2D::GetTextureID()
{
	return texture_id;
}
