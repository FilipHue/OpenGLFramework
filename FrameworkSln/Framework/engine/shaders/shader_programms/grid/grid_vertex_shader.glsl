#version 330 core

layout (location = 0) in vec3 position;
layout (location = 2) in vec3 colour;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

out vec3 outColour;

void main()
{
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0f);

	outColour = colour;
}
