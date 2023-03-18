#version 330 core

layout (location = 0) in vec3 position;
layout (location = 2) in vec3 colour;
layout (location = 3) in vec2 texCoords;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

out vec3 outColour;
out vec3 outPosition;
out vec2 outTexCoords;

out vec3 nearPoint;
out vec3 farPoint;

void main()
{

	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);

	outColour = colour;
	outTexCoords = texCoords;
	outPosition = position;
}
