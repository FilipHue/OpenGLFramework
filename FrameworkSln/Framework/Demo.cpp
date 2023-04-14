#include "Demo.h"

Demo::Demo()
{
}

void Demo::Init()
{
	p_shape_manager->CreateRectangleX("Square1", 10, 10);
	p_shape_manager->CreateRectangleY("Square2", 10, 10);
	p_shape_manager->CreateRectangleZ("Square3", 50, 50);

	p_shape_manager->CreateCube("Cube1", 1, 1, 1);
	p_shape_manager->CreateCube("Cube2", 1, 1, 1);
	p_shape_manager->CreateCube("Cube3", 10, 1, 10);
	p_shape_manager->CreateCube("Cube4", 1, 1, 1);
	p_shape_manager->CreateCube("Cube5", 0.1f, 0.1f, 0.1f);

	//p_shape_manager->CreateRectangleY("Screen", p_window->resolution.x, p_window->resolution.y);

	p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\container.png")).c_str(), "container");
	p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\container_specular.png")).c_str(), "container_sp");

	lightMoveSpeed = 2.0f;
	lightX = 0.0f;
	lightY = 0.5f;
	lightZ = 0.0f;

	shaders["PhongtShader"]->SetInt("material.Kd", 0);
	shaders["PhongtShader"]->SetInt("material.Ksp", 1);
}

void Demo::StartFrame()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, p_window->resolution.x, p_window->resolution.y);
}

void Demo::Update(double delta_time)
{
	LightProperties* light1 = new LightProperties{
		glm::vec3(lightX, lightY, lightZ),
		glm::vec3(1.0f, 1.0f, 0.8f),
		glm::vec3(0.2f, 0.2f, 0.2f),
		glm::vec3(0.5f, 0.5f, 0.5f)
	};

	RenderMesh(meshes["Cube1"], shaders["PhongtShader"], glm::vec3(-3.5, 0, -0.5), "container", light1);
	RenderMesh(meshes["Cube2"], shaders["PhongtShader"], glm::vec3(2.5, 0, -0.5), "container", light1);
	RenderMesh(meshes["Cube3"], shaders["PhongtShader"], glm::vec3(-5, -3.0, -5), "container", light1);
	RenderMesh(meshes["Cube4"], shaders["PhongtShader"], glm::vec3(-0.5, 2.5, -0.5), "container", light1);
	RenderMesh(meshes["Cube5"], shaders["SimpleShader"], glm::vec3(lightX, lightY, lightZ));
}

void Demo::EndFrame()
{
}

void Demo::OnInputUpdate(double delta_time, int mods)
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

void Demo::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_R) {
		lightX = 0.0f;
		lightY = 0.5f;
		lightZ = 0.0f;
	}
}

void Demo::OnKeyRelease(int key, int mods)
{
}

void Demo::OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y)
{
}

void Demo::OnMouseButtonPress(double x_pos, double y_pos, int key, int mods)
{
}

void Demo::OnMouseButttonRelease(double x_pos, double y_pos, int key, int mods)
{
}

void Demo::OnMouseScroll(double x_offset, double y_offset)
{
}
