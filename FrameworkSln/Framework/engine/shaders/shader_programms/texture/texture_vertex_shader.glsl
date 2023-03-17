#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 2) in vec3 aColour;
layout(location = 3) in vec2 aTextCoord;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

out vec3 outColour;
out vec2 textCoord;

void main()
{
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(aPos, 1.0);
    outColour = aColour;
    textCoord = aTextCoord;
}
