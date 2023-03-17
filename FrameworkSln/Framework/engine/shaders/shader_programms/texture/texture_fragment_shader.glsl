#version 330 core

out vec4 fragColor;

in vec3 outColour;
in vec2 textCoord;

uniform sampler2D ourTexture;

void main()
{
    fragColor = texture(ourTexture, textCoord) * vec4(outColour, 1.0f);
}
