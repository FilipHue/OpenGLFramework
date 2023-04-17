#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 colour;
layout (location = 2) in vec3 normal;
layout (location = 3) in vec2 textureCoords;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

out vec3 fragPosition;
out vec3 fragNormal;
out vec2 texCoords;

void main()
{
	fragPosition	= vec3(modelMatrix * vec4(position, 1.0f));
	fragNormal		= mat3(transpose(inverse(modelMatrix))) * normal;
	texCoords		= textureCoords;

	gl_Position		= projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0f);
}