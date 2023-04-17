#include "directional_light.h"

DirectionalLight::DirectionalLight(
	glm::vec3 position, glm::vec3 direction, glm::vec3 colour,
	glm::vec3 Ka, glm::vec3 Kd, glm::vec3 Ksp, float Ksh,
	std::string struct_name) : Light(position, colour, Ka, Kd, Ksp, Ksh, struct_name)
{
	this->direction = direction;
}

void DirectionalLight::SendToShader(Shader* shader)
{
	shader->SetVec3(struct_name		+	"direction",	direction);
	shader->SetVec3(struct_name		+	"colour",		colour);

	shader->SetVec3(struct_name		+	"Ka",			Ka);
	shader->SetVec3(struct_name		+	"Kd",			Kd);
	shader->SetVec3(struct_name		+	"Ksp",			Ksp);
	shader->SetFloat(struct_name	+	"Ksh",			Ksh);
}
