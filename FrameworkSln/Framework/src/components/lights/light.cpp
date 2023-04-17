#include "light.h"

Light::Light(glm::vec3 position, glm::vec3 colour, glm::vec3 Ka, glm::vec3 Kd, glm::vec3 Ksp, float Ksh, std::string struct_name)
{
	this->position = position;
	this->colour = colour;

	this->Ka = Ka;
	this->Kd = Kd;
	this->Ksp = Ksp;
	this->Ksh = Ksh;

	struct_name != "" ? this->struct_name = struct_name + "." : this->struct_name = struct_name;
}

void Light::SendToShader(Shader* shader)
{
	shader->SetVec3(struct_name		+	"position",		position);
	shader->SetVec3(struct_name		+	"colour",		colour);

	shader->SetVec3(struct_name		+	"Ka",			Ka);
	shader->SetVec3(struct_name		+	"Kd",			Kd);
	shader->SetVec3(struct_name		+	"Ksp",			Ksp);
	shader->SetFloat(struct_name	+	"Ksh",			Ksh);
}
