#pragma once

#include <core.h>
#include "texture_manger.h"

class Texture2D
{
	friend class TextureManger;
public:
	Texture2D();
	~Texture2D();

	unsigned int GetTextureID();

private:
	void Init(const char* filePath);

private:
	int width;
	int height;
	int channels;

	unsigned char* imageData;
	unsigned int textureID;
};

