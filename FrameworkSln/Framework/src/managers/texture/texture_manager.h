#pragma once

#include <unordered_map>

#include <core.h>

#include <glad/glad.h>

#include "texture_2D.h"

class TextureManger
{
	friend class Texture2D;
public:
	/**
	 * @brief				Method for loading a 2D texture from a file
	 * @param file_path		The path to the texture file
	 * @param name			The name of the texture with which is identified (given by the caller: crate.jpg -> crate) 
	 * @param wrap_s		The function for the texture wrap mode on the horizontal axis (s-axis)
	 * @param wrap_t		The function for the texture wrap mode on the vertical axis (t-axis)
	 * @param min_filter	The function for texture minification filter
	 * @param mag_filter	The function for texture magnification filter
	*/
	void LoadTexture2D(std::string file_path, std::string name, std::string type, GLenum wrap_s = GL_REPEAT, GLenum wrap_t = GL_REPEAT, GLenum min_filter = GL_LINEAR, GLenum mag_filter = GL_LINEAR);
	Texture2D* GetTexture2D(std::string name);
	std::string GetTexture2DType(std::string name);

	void EnableBlending();
	void DisableBlending();

	void UseBlendFunction(GLenum source_factor, GLenum dest_factor);
	void UseChannelBlendFunction(GLenum r_factor, GLenum g_factor, GLenum b_factor, GLenum a_factor);

private:
	/**
	 * @brief				Method for returning the respective pixel format depending on the number of channels
	 * @brief				See https://registry.khronos.org/OpenGL-Refpages/gl4/html/glTexParameter.xhtml for more information
	 * @param channels		The number of colour channels
	 * @return				The pixel format
	*/
	static GLuint GetPixelFormat(unsigned int channels);
	/**
	 * @brief				Method for returning the respective internal format depending on the number of channels
	 * @brief				See https://registry.khronos.org/OpenGL-Refpages/gl4/html/glTexParameter.xhtml for more information
	 * @param channels		The number of colour channels
	 * @return				The internal format
	*/
	static GLuint GetInternalFormat(unsigned int channels);

private:
	std::unordered_map<std::string, Texture2D*> textures_2D;
	std::unordered_map<std::string, std::string> textures_type_2D;

	static constexpr GLuint pixel_format[5] = { 0, GL_RED, GL_RG, GL_RGB, GL_RGBA };
	static constexpr GLuint internal_format[4][5] = {
		{ 0, GL_R8, GL_RG8, GL_RGB8, GL_RGBA8 },
		{ 0, GL_R16, GL_RG16, GL_RGB16, GL_RGBA16 },
		{ 0, GL_R16F, GL_RG16F, GL_RGB16F, GL_RGBA16F },
		{ 0, GL_R32F, GL_RG32F, GL_RGB32F, GL_RGBA32F }
	};

	bool blend;
};

