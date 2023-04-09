#version 330 core

out vec4 fragColour;

in vec3 fragPosition;
in vec3 fragNormal;

uniform vec3 lightPosition;
uniform vec3 lightColour;
uniform vec3 objectColour;
uniform vec3 viewPosition;

uniform vec3 Ka;
uniform vec3 Kd;
uniform vec3 Ksp;
uniform float Ksh;

void main() 
{
	// ambient
	vec3 ambient = Ka * lightColour;

	// diffuse
	vec3 normal = normalize(fragNormal);
	vec3 lightDirection = normalize(lightPosition - fragPosition);
	vec3 diffuse = max(dot(normal, lightDirection), 0.0) * lightColour * Kd;

	// specular
	vec3 viewDirection = normalize(viewPosition - fragPosition);
	vec3 reflectDirection = reflect(-lightDirection, normal);
	vec3 specular = pow(max(dot(viewDirection, reflectDirection), 0.0), 32) * Ksp * lightColour;

	// attenuation factor
	float d = distance(lightPosition, fragPosition); 
	float attenuationFactor = 1 / (1 + 0.14 * d + 0.07 * d * d);

	// result
	vec3 finalLight = (ambient + attenuationFactor * (specular + diffuse)) * objectColour;
	fragColour = vec4(finalLight, 1.0f);
}