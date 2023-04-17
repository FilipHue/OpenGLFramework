#include "demo_phong_texture.h"

void DemoPhongTexture::Init()
{
	p_shape_manager->CreateCube("Cube1", 1, 1, 1);
	p_shape_manager->CreateCube("Cube2", 1, 1, 1);
	p_shape_manager->CreateCube("Cube3", 1, 1, 1);
	p_shape_manager->CreateCube("Cube4", 1, 1, 1);
	p_shape_manager->CreateCube("Cube5", 1, 1, 1);
	p_shape_manager->CreateCube("Cube6", 1, 1, 1);
	p_shape_manager->CreateCube("Cube7", 10, 1, 10);
	p_shape_manager->CreateCube("Light", 0.1f, 0.1f, 0.1f);

	p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\container.png")).c_str(), "container");
	p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\container_specular.png")).c_str(), "container_sp");

	lightMoveSpeed = 2.0f;
	lightX = 0.0f;
	lightY = 0.5f;
	lightZ = 0.0f;

	light = new Light{
		glm::vec3(lightX, lightY, lightZ),
		glm::vec3(1.0f, 1.0f, 0.8f),

		glm::vec3(0.1f, 0.1f, 0.1f),
		glm::vec3(0.5f, 0.5f, 0.5f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		32.0f,

		"light"
	};

	model_matrix = glm::mat4(1);
}

void DemoPhongTexture::StartFrame()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, p_window->resolution.x, p_window->resolution.y);
}

void DemoPhongTexture::Update(double delta_time)
{
	light->position = glm::vec3(lightX, lightY, lightZ);

	model_matrix = glm::mat4(1);
	model_matrix = glm::translate(model_matrix, glm::vec3(-3.5, 0.0, -0.5));
	RenderMesh(meshes["Cube1"], shaders["PhongtShader"], model_matrix, "container", light);

	model_matrix = glm::mat4(1);
	model_matrix = glm::translate(model_matrix, glm::vec3(2.5, 0.0, -0.5));
	RenderMesh(meshes["Cube2"], shaders["PhongtShader"], model_matrix, "container", light);

	model_matrix = glm::mat4(1);
	model_matrix = glm::translate(model_matrix, glm::vec3(-0.5, 2.5, -0.5));
	RenderMesh(meshes["Cube3"], shaders["PhongtShader"], model_matrix, "container", light);

	model_matrix = glm::mat4(1);
	model_matrix = glm::translate(model_matrix, glm::vec3(-0.5, 0.0, -3.5));
	model_matrix = glm::rotate(model_matrix, glm::radians(45.0f), glm::vec3(1, 0, 0));
	model_matrix = glm::translate(model_matrix, glm::vec3(0.0, -0.5, -0.5));
	RenderMesh(meshes["Cube4"], shaders["PhongtShader"], model_matrix, "container", light);

	model_matrix = glm::mat4(1);
	model_matrix = glm::translate(model_matrix, glm::vec3(-3.5, 0.0, -3.5));
	model_matrix = glm::rotate(model_matrix, glm::radians(45.0f), glm::vec3(1, 1, 1));
	model_matrix = glm::translate(model_matrix, glm::vec3(-0.5, -0.5, -0.5));
	RenderMesh(meshes["Cube5"], shaders["PhongtShader"], model_matrix, "container", light);

	model_matrix = glm::mat4(1);
	model_matrix = glm::translate(model_matrix, glm::vec3(3.5, 0.0, -3.5));
	model_matrix = glm::rotate(model_matrix, glm::radians(45.0f), glm::vec3(1, -1, -1));
	model_matrix = glm::translate(model_matrix, glm::vec3(-0.5, -0.5, -0.5));
	RenderMesh(meshes["Cube6"], shaders["PhongtShader"], model_matrix, "container", light);

	model_matrix = glm::mat4(1);
	model_matrix = glm::translate(model_matrix, glm::vec3(-5, -3.0, -5));
	RenderMesh(meshes["Cube7"], shaders["PhongtShader"], model_matrix, "container", light);

	RenderMesh(meshes["Light"], shaders["SimpleShader"], glm::vec3(lightX, lightY, lightZ));
}

void DemoPhongTexture::EndFrame()
{
}

void DemoPhongTexture::OnInputUpdate(double delta_time, int mods)
{
	if (p_window->GetContinousPress(GLFW_KEY_UP) && mods != GLFW_MOD_SHIFT) {
		lightZ += delta_time * lightMoveSpeed;
	}

	if (p_window->GetContinousPress(GLFW_KEY_DOWN) && mods != GLFW_MOD_SHIFT) {
		lightZ -= delta_time * lightMoveSpeed;
	}

	if (p_window->GetContinousPress(GLFW_KEY_LEFT)) {
		lightX -= delta_time * lightMoveSpeed;
	}

	if (p_window->GetContinousPress(GLFW_KEY_RIGHT)) {
		lightX += delta_time * lightMoveSpeed;
	}

	if (p_window->GetContinousPress(GLFW_KEY_UP) && mods == GLFW_MOD_SHIFT) {
		lightY += delta_time * lightMoveSpeed;
	}

	if (p_window->GetContinousPress(GLFW_KEY_DOWN) && mods == GLFW_MOD_SHIFT) {
		lightY -= delta_time * lightMoveSpeed;
	}
}

void DemoPhongTexture::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_R) {
		lightX = 0.0f;
		lightY = 0.5f;
		lightZ = 0.0f;
	}
}

void DemoPhongTexture::OnKeyRelease(int key, int mods)
{
}

void DemoPhongTexture::OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y)
{
}

void DemoPhongTexture::OnMouseButtonPress(double x_pos, double y_pos, int key, int mods)
{
}

void DemoPhongTexture::OnMouseButttonRelease(double x_pos, double y_pos, int key, int mods)
{
}

void DemoPhongTexture::OnMouseScroll(double x_offset, double y_offset)
{
}
