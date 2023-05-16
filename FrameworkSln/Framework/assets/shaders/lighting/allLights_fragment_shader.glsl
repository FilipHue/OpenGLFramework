#version 330 core

out vec4 fragColour;

in vec3 fragPosition;
in vec3 fragNormal;
in vec2 texCoords;

#define POINT_LIGHTS 4

struct Material {
	vec3 Ka;
	sampler2D Kd0;
	sampler2D Ksp0;
	float Ksh;
};

struct DirectLight {
	vec3 direction;
	vec3 colour;

	vec3 Ka;
	vec3 Kd;
	vec3 Ksp;
	float Ksh;
};

struct PointLight {
    vec3 position;
    vec3 colour;
    
    vec3 Ka;
    vec3 Kd;
    vec3 Ksp;
    float Ksh;

    float Kc;
    float Kl;
    float Kq;
};

struct Spotlight {
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
uniform DirectLight directLight;
uniform PointLight pointLights[POINT_LIGHTS];
uniform Spotlight spotlight;

vec3 ComputeDirectLight(DirectLight light, vec3 normal, vec3 viewDirection);
vec3 ComputePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDirection);
vec3 ComputeSpotlight(Spotlight light, vec3 normal, vec3 fragPos, vec3 viewDirection);

void main() 
{
    vec3 normal             = normalize(fragNormal);
    vec3 viewDirection      = normalize(viewPosition - fragPosition);

    vec3 result = ComputeDirectLight(directLight, normal, viewDirection);

    for(int i = 0; i < POINT_LIGHTS; i++) {
        result              += ComputePointLight(pointLights[i], normal, fragPosition, viewDirection);
    }

    result                  += ComputeSpotlight(spotlight, normal, fragPosition, viewDirection);

    fragColour              = vec4(result, 1.0f);
}

vec3 ComputeDirectLight(DirectLight light, vec3 normal, vec3 viewDirection)
{
    vec3 light_direction    = normalize(-light.direction);

    // diffuse shading
    float diff              = max(dot(normal, light_direction), 0.0);

    // specular shading
    vec3 reflectDirection   = reflect(-light_direction, normal);
    float spec              = pow(max(dot(viewDirection, reflectDirection), 0.0), material.Ksh);

    // combine results
    vec3 ambient            = light.Ka * vec3(texture(material.Kd0, texCoords));
    vec3 diffuse            = light.Kd * diff * vec3(texture(material.Kd0, texCoords));
    vec3 specular           = light.Ksp * spec * vec3(texture(material.Ksp0, texCoords));

    return (ambient + diffuse + specular);
}

vec3 ComputePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDirection)
{
    vec3 lightDirection     = normalize(light.position - fragPos);

    // diffuse shading
    float diff              = max(dot(normal, lightDirection), 0.0);

    // specular shading
    vec3 reflectDirection   = reflect(-lightDirection, normal);
    float spec = pow(max(dot(viewDirection, reflectDirection), 0.0), material.Ksh);

    // attenuation
    float distance          = length(light.position - fragPos);
    float attenuation       = 1.0 / (light.Kc + light.Kl * distance + light.Kq * (distance * distance));  
    
    // combine results
    vec3 ambient            = light.Ka * vec3(texture(material.Kd0, texCoords));
    vec3 diffuse            = light.Kd * diff * vec3(texture(material.Kd0, texCoords));
    vec3 specular           = light.Ksp * spec * vec3(texture(material.Ksp0, texCoords));

    ambient                 *= attenuation;
    diffuse                 *= attenuation;
    specular                *= attenuation;

    return (ambient + diffuse + specular);
}

vec3 ComputeSpotlight(Spotlight light, vec3 normal, vec3 fragPos, vec3 viewDirection)
{
    vec3 lightDirection     = normalize(light.position - fragPos);

    // diffuse shading
    float diff              = max(dot(normal, lightDirection), 0.0);

    // specular shading
    vec3 reflectDirection   = reflect(-lightDirection, normal);
    float spec              = pow(max(dot(viewDirection, reflectDirection), 0.0), material.Ksh);

    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation       = 1.0 / (light.Kc + light.Kl * distance + light.Kq * (distance * distance));    
    
    // spotlight intensity
    float theta             = dot(lightDirection, normalize(-light.direction)); 
    float epsilon           = light.in_cutoff_angle - light.out_cutoff_angle;
    float intensity         = clamp((theta - light.out_cutoff_angle) / epsilon, 0.0, 1.0);
    
    // combine results
    vec3 ambient            = light.Ka * vec3(texture(material.Kd0, texCoords));
    vec3 diffuse            = light.Kd * diff * vec3(texture(material.Kd0, texCoords));
    vec3 specular           = light.Ksp * spec * vec3(texture(material.Ksp0, texCoords));
    
    ambient                 *= attenuation * intensity;
    diffuse                 *= attenuation * intensity;
    specular                *= attenuation * intensity;
    
    return (ambient + diffuse + specular);
}
