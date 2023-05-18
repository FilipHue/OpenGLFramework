#version 330 core

out vec4 fragColor;

in vec3 outColour;
in vec2 textCoord;

uniform sampler2D ourTexture;

void main()
{
    vec4 tex_colour;
    
    tex_colour = texture(ourTexture, textCoord) * vec4(outColour, 1.0f);
    if (tex_colour.a < 0.1) {
        discard;
    }

    fragColor = tex_colour;
}
