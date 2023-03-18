#version 330 core

out vec4 fragColour;

in vec3 outColour;
in vec3 outPosition;
in vec2 outTexCoords;

in vec3 nearPoint;
in vec3 farPoint;

void main()
{
	fragColour = vec4(outColour, 1.0f);
}
