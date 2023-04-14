#include "demo_phong.h"

DemoPhong::DemoPhong()
{
}

void DemoPhong::Init()
{
	p_shape_manager->CreateCube("Cube1", 1, 1, 1);
	p_shape_manager->CreateCube("Cube2", 1, 1, 1);
	p_shape_manager->CreateCube("Cube3", 1, 1, 1);
	p_shape_manager->CreateCube("Cube4", 1, 1, 1);
	p_shape_manager->CreateCube("Cube5", 1, 1, 1);
	p_shape_manager->CreateCube("Cube6", 1, 1, 1);
	p_shape_manager->CreateCube("Cube7", 10, 1, 10);
	p_shape_manager->CreateCube("Light", 0.1f, 0.1f, 0.1f);

	lightMoveSpeed = 2.0f;
	lightX = 0.0f;
	lightY = 0.5f;
	lightZ = 0.0f;

	model_matrix = glm::mat4(1);
}

void DemoPhong::StartFrame()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, p_window->resolution.x, p_window->resolution.y);
}

void DemoPhong::Update(double delta_time)
{
	LightProperties* light = new LightProperties{
		glm::vec3(lightX, lightY, lightZ),
		glm::vec3(1.0f, 1.0f, 0.8f),
		glm::vec3(0.2f, 0.2f, 0.2f),
		glm::vec3(0.5f, 0.5f, 0.5f)
	};

	model_matrix = glm::mat4(1);
	model_matrix = glm::translate(model_matrix, glm::vec3(-3.5, 0.0, -0.5));
	RenderMesh(meshes["Cube1"], shaders["PhongShader"], model_matrix, NULL, light);

	model_matrix = glm::mat4(1);
	model_matrix = glm::translate(model_matrix, glm::vec3(2.5, 0.0, -0.5));
	RenderMesh(meshes["Cube2"], shaders["PhongShader"], model_matrix, NULL, light);

	model_matrix = glm::mat4(1);
	model_matrix = glm::translate(model_matrix, glm::vec3(-0.5, 2.5, -0.5));
	RenderMesh(meshes["Cube3"], shaders["PhongShader"], model_matrix, NULL, light);

	model_matrix = glm::mat4(1);
	model_matrix = glm::translate(model_matrix, glm::vec3(-0.5, 0.0, -3.5));
	model_matrix = glm::rotate(model_matrix, glm::radians(45.0f), glm::vec3(1, 0, 0));
	model_matrix = glm::translate(model_matrix, glm::vec3(0.0, -0.5, -0.5));
	RenderMesh(meshes["Cube4"], shaders["PhongShader"], model_matrix, NULL, light);

	model_matrix = glm::mat4(1);
	model_matrix = glm::translate(model_matrix, glm::vec3(-3.5, 0.0, -3.5));
	model_matrix = glm::rotate(model_matrix, glm::radians(45.0f), glm::vec3(1, 1, 1));
	model_matrix = glm::translate(model_matrix, glm::vec3(-0.5, -0.5, -0.5));
	RenderMesh(meshes["Cube5"], shaders["PhongShader"], model_matrix, NULL, light);

	model_matrix = glm::mat4(1);
	model_matrix = glm::translate(model_matrix, glm::vec3(3.5, 0.0, -3.5));
	model_matrix = glm::rotate(model_matrix, glm::radians(45.0f), glm::vec3(1, -1, -1));
	model_matrix = glm::translate(model_matrix, glm::vec3(-0.5, -0.5, -0.5));
	RenderMesh(meshes["Cube6"], shaders["PhongShader"], model_matrix, NULL, light);

	model_matrix = glm::mat4(1);
	model_matrix = glm::translate(model_matrix, glm::vec3(-5, -3.0, -5));
	RenderMesh(meshes["Cube7"], shaders["PhongShader"], model_matrix, NULL, light);

	RenderMesh(meshes["Light"], shaders["SimpleShader"], glm::vec3(lightX, lightY, lightZ));
}

void DemoPhong::EndFrame()
{
}

void DemoPhong::OnInputUpdate(double delta_time, int mods)
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

void DemoPhong::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_R) {
		lightX = 0.0f;
		lightY = 0.5f;
		lightZ = 0.0f;
	}
}

void DemoPhong::OnKeyRelease(int key, int mods)
{
}

void DemoPhong::OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y)
{
}

void DemoPhong::OnMouseButtonPress(double x_pos, double y_pos, int key, int mods)
{
}

void DemoPhong::OnMouseButttonRelease(double x_pos, double y_pos, int key, int mods)
{
}

void DemoPhong::OnMouseScroll(double x_offset, double y_offset)
{
}
