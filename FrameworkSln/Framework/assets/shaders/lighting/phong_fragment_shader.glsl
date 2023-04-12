#version 330 core

out vec4 fragColour;

in vec3 fragPosition;
in vec3 fragNormal;

struct Material {
	vec3 Ka;
	vec3 Kd;
	vec3 Ksp;
	float Ksh;
};

struct Light {
	vec3 position;
	vec3 colour;

	vec3 Ka;
	vec3 Kd;
	vec3 Ksp;
	float Ksh;
};	
	
uniform vec3 objectColour;
uniform vec3 viewPosition;

uniform Material material;
uniform Light light;

void main() 
{
	// ambient
	vec3 ambient = light.Ka * light.colour * material.Ka;

	// diffuse
	vec3 normal = normalize(fragNormal);
	vec3 lightDirection = normalize(light.position - fragPosition);
	vec3 diffuse = max(dot(normal, lightDirection), 0.0) * light.colour * light.Kd * material.Kd;

	// specular
	vec3 viewDirection = normalize(viewPosition - fragPosition);
	vec3 reflectDirection = reflect(-lightDirection, normal);
	vec3 specular = pow(max(dot(viewDirection, reflectDirection), 0.0), material.Ksh) * material.Ksp * light.colour;

	// attenuation factor
	float d = distance(light.position, fragPosition); 
	float attenuationFactor = 1 / (1 + 0.14 * d + 0.07 * d * d);

	// result
	vec3 finalLight = (ambient + attenuationFactor * (specular + diffuse)) * objectColour;
	fragColour = vec4(finalLight, 1.0f);
}
