#version 330 core

float gridSize = 100.0;
float gridCellSize = 0.025;

vec4 gridColorThin = vec4(0.5, 0.5, 0.5, 1.0);
vec4 gridColorThick = vec4(0.0, 0.0, 0.0, 1.0);

const float gridMinPixelsBetweenCells = 2.0;

out vec2 uv;

const vec3 pos[4]		= vec3[4](  vec3(-1.0, 0.0, -1.0),  vec3( 1.0, 0.0, -1.0),  vec3( 1.0, 0.0,  1.0),  vec3(-1.0, 0.0,  1.0));
const int indices[6]	= int[6](0, 1, 2, 2, 3, 0);

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

void main()
{
	vec3 vpos			= pos[indices[gl_VertexID]]* gridSize;
	gl_Position			= projectionMatrix * viewMatrix * vec4(vpos, 1.0);
	uv					= vpos.xz;
}
