#version 330 core

out vec4 fragColour;

in vec3 fragPosition;
in vec3 fragNormal;
in vec2 texCoords;

struct Material {
	vec3 Ka;
	sampler2D Kd;
	sampler2D Ksp;
	float Ksh;
};

struct Light {
	vec3 position;
	vec3 direction;
	vec3 colour;

	vec3 Ka;
	vec3 Kd;
	vec3 Ksp;
	float Ksh;

	float Kc;
	float Kl;
	float Kq;

	float in_cutoff_angle;
	float out_cutoff_angle;
};	

uniform vec3 viewPosition;

uniform Material material;
uniform Light light;

void main() 
{
	// ambient
	vec3 ambient			= light.Ka * texture(material.Kd, texCoords).rgb;

	// diffuse
	vec3 normal				= normalize(fragNormal);
	vec3 lightDirection		= normalize(light.position - fragPosition);
	vec3 diffuse			= light.Kd * max(dot(normal, lightDirection), 0.0) * texture(material.Kd, texCoords).rgb;

	// specular
	vec3 viewDirection		= normalize(viewPosition - fragPosition);
	vec3 reflectDirection	= reflect(-lightDirection, normal);
	vec3 specular			= light.Ksp * pow(max(dot(viewDirection, reflectDirection), 0.0), material.Ksh) * texture(material.Ksp, texCoords).rgb;

	// attenuation factor
	float d					= distance(light.position, fragPosition); 
	float attenuationFactor = 1.0 / (light.Kc + light.Kl * d + light.Kq * d * d);

	// result
	vec3 finalLight			= attenuationFactor * (ambient + specular + diffuse);
	fragColour				= vec4(finalLight, 1.0f);
}