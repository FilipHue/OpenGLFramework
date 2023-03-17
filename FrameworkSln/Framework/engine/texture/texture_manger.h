#pragma once

#include <core.h>
#include "texture_utils.h"

class TextureManger
{
	friend class Texture2D;
public:
	TextureManger();
	~TextureManger();

	/**
	  * Loads a 2D texture from a file
	  */
	void LoadTexture2D(const char* filePath, const char* name);
	/**
	  * Returns the 2D texture with the given name
	  * @param name The name of the texture
	  * @return the texture with the given name
	  */
	Texture2D* GetTexture2D(const char* name);

	void LoadGridTexture();

private:
	/**
	  * Returns the respective pixel format depending on the number of channels
	  * Check - https://registry.khronos.org/OpenGL-Refpages/gl4/html/glTexParameter.xhtml - for more information
	  * @param channels The number of colour channels
	  * @return the pixel format
	  */
	static GLuint GetPixelFormat(unsigned int channels);
	/**
	  * Returns the respective internal format depending on the number of channels
	  * Check - https://registry.khronos.org/OpenGL-Refpages/gl4/html/glTexParameter.xhtml - for more information
	  * @param channels The number of colour channels
	  * @return the internal format
	  */
	static GLuint GetInternalFormat(unsigned int channels);

private:
	std::unordered_map<const char*, Texture2D*> textures2D;

	static constexpr GLuint pixelFormat[5] = { 0, GL_RED, GL_RG, GL_RGB, GL_RGBA };
	static constexpr GLuint internalFormat[4][5] = {
		{ 0, GL_R8, GL_RG8, GL_RGB8, GL_RGBA8 },
		{ 0, GL_R16, GL_RG16, GL_RGB16, GL_RGBA16 },
		{ 0, GL_R16F, GL_RG16F, GL_RGB16F, GL_RGBA16F },
		{ 0, GL_R32F, GL_RG32F, GL_RGB32F, GL_RGBA32F }
	};
};

