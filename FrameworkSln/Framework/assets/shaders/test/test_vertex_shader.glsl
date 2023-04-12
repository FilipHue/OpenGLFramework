#version 330

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColour;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

out vec3 outColour;

void main()
{
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(aPos, 1.0);
    outColour = aColour;
}