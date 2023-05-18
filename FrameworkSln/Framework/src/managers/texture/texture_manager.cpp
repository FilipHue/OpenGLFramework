#include "texture_manager.h"

#include <iostream>

void TextureManger::LoadTexture2D(std::string filePath, std::string name, std::string type, GLenum wrap_s, GLenum wrap_t, GLenum min_filter, GLenum mag_filter)
{
	Texture2D* texture2D;

	texture2D = new Texture2D();
	texture2D->Init(filePath, wrap_s, wrap_t, min_filter, mag_filter);

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

void TextureManger::EnableBlending()
{
	if (blend == false) {
		glEnable(GL_BLEND);
		blend = true;
	}
}

void TextureManger::DisableBlending()
{
	if (blend == true) {
		glDisable(GL_BLEND);
		blend = false;
	}
}

void TextureManger::UseBlendFunction(GLenum source_factor, GLenum dest_factor)
{
	glBlendFunc(source_factor, dest_factor);
}

void TextureManger::UseChannelBlendFunction(GLenum r_factor, GLenum g_factor, GLenum b_factor, GLenum a_factor)
{
	glBlendFuncSeparate(r_factor, g_factor, b_factor, a_factor);
}

GLuint TextureManger::GetPixelFormat(unsigned int channels)
{
	return pixel_format[channels];
}

GLuint TextureManger::GetInternalFormat(unsigned int channels)
{
	return internal_format[0][channels];
}
