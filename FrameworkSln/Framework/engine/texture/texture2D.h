#pragma once

#include <core.h>
#include "texture_manger.h"

class Texture2D
{
	friend class TextureManger;
public:
	Texture2D();
	~Texture2D();

	/**
	  * Returns the texture's id at which it is binded in the buffer 
	  */
	unsigned int GetTextureID();

private:
	/**
	  * Method initializes the texture data and binds it
	  * @param filePath The path to the texture file
	  */
	void Init(const char* filePath);
	/**
	  * Method initializes the texture from the given texture data
	  * @param width The width of the texture
	  * @param height The height of the texture
	  * @param channels The number of colour channels
	  * @param imageData The texture data
	  */
	void Init(int width, int height, int channels, unsigned char* imageData);

private:
	int width;
	int height;
	int channels;

	unsigned char* imageData;
	unsigned int textureID;
};

