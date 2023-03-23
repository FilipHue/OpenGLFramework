#version 330 core

out vec4 fragColor;

in vec3 outColour;

void main()
{
    fragColor = vec4(outColour, 1.0f);
}