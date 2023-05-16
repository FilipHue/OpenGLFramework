#pragma once

#include "texture_manager.h"

class Texture2D
{
	friend class TextureManger;
public:
	Texture2D();

	unsigned int GetTextureID();

private:
	/**
	 * @brief				Method for initializing the texture and binding it
	 * @param file_path		The path to the texture file
	*/
	void Init(std::string file_path);
	/**
	 * @brief				Method for intializing the texture from the given texture data
	 * @param width			The width of the texture
	 * @param height		The height of the texture
	 * @param channels		The number of colour channels
	 * @param imageData		The texture data
	*/
	void Init(int width, int height, int channels, unsigned char* imageData);

private:
	int width;
	int height;
	int channels;

	unsigned char* image_data;
	unsigned int texture_id;
};
