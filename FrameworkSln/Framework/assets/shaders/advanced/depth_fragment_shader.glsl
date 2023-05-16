#version 330 core

out vec4 fragColor;

in vec3 outColour;
in vec2 textCoord;

uniform sampler2D ourTexture;

float near = 0.1;
float far = 100.0;

float liniarizeDepth(float depth)
{
    float z = depth * 2.0 - 1.0;
    return (2.0 * near * far) / (far + near - z * (far - near));
}

void main()
{
    // fragColor    = vec4(vec3(gl_FragCoord.z), 1.0f);

    // float depth;

    // depth        = liniarizeDepth(gl_FragCoord.z) / far;
    // fragColor    = vec4(vec3(depth), 1.0);
}