#include "spotlight.h"

Spotlight::Spotlight(
	glm::vec3 position, glm::vec3 direction, glm::vec3 colour,
	glm::vec3 Ka, glm::vec3 Kd, glm::vec3 Ksp, float Ksh,
	float Kc, float Kl, float Kq,
	float inner_cutoff_angle, float outer_cutoff_angle,
	std::string struct_name) : Light(position, colour, Ka, Kd, Ksp, Ksh, struct_name)
{
	this->direction = direction;
	
	this->Kc = Kc;
	this->Kl = Kl;
	this->Kq = Kq;

	this->inner_cutoff_angle = inner_cutoff_angle;
	this->outer_cutoff_angle = outer_cutoff_angle;
}

void Spotlight::SendToShader(Shader* shader)
{
	shader->SetVec3(struct_name		+	"position",				position);
	shader->SetVec3(struct_name		+	"direction",			direction);
	shader->SetVec3(struct_name		+	"colour",				colour);
										
	shader->SetVec3(struct_name		+	"Ka",					Ka);
	shader->SetVec3(struct_name		+	"Kd",					Kd);
	shader->SetVec3(struct_name		+	"Ksp",					Ksp);
	shader->SetFloat(struct_name	+	"Ksh",					Ksh);
										
	shader->SetFloat(struct_name	+	"Kc",					Kc);
	shader->SetFloat(struct_name	+	"Kl",					Kl);
	shader->SetFloat(struct_name	+	"Kq",					Kq);
										
	shader->SetFloat(struct_name	+	"in_cutoff_angle",		inner_cutoff_angle);
	shader->SetFloat(struct_name	+	"out_cutoff_angle",		outer_cutoff_angle);

}
