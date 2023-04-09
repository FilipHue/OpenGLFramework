#include "Test.h"

Test::Test()
{
}

void Test::Init()
{
	p_shape_manager->CreateRectangleX("Square1", 10, 10);
	p_shape_manager->CreateRectangleY("Square2", 10, 10);
	p_shape_manager->CreateRectangleZ("Square3", 50, 50);

	p_shape_manager->CreateCube("Cube1", 1, 1, 1);
	p_shape_manager->CreateCube("Cube2", 1, 1, 1);
	p_shape_manager->CreateCube("Cube3", 10, 1, 10);
	p_shape_manager->CreateCube("Cube4", 1, 1, 1);
	p_shape_manager->CreateCube("Cube5", 0.1f, 0.1f, 0.1f);

	/*textureManager->LoadTexture2D("D:\\Diverse\\OpenGLFramework\\FrameworkSln\\Framework\\engine\\texture\\textures\\crate.jpg", "crate");
	textureManager->LoadTexture2D("D:\\Diverse\\OpenGLFramework\\FrameworkSln\\Framework\\engine\\texture\\textures\\default.png", "grid");*/

	lightMoveSpeed = 2.0f;
	lightX = 0.0f;
	lightY = 0.5f;
	lightZ = 0.0f;
}

void Test::StartFrame()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, p_window->resolution.x, p_window->resolution.y);
}

void Test::Update(double delta_time)
{
	RenderMesh(meshes["Cube1"], shaders["PhongShader"], glm::vec3(-3.5, 0, -0.5), glm::vec3(lightX, lightY, lightZ));
	RenderMesh(meshes["Cube2"], shaders["PhongShader"], glm::vec3(2.5, 0, -0.5), glm::vec3(lightX, lightY, lightZ));
	RenderMesh(meshes["Cube3"], shaders["PhongShader"], glm::vec3(-5, -3.0, -5), glm::vec3(lightX, lightY, lightZ));
	RenderMesh(meshes["Cube4"], shaders["PhongShader"], glm::vec3(-0.5, 2.5, -0.5), glm::vec3(lightX, lightY, lightZ));
	RenderMesh(meshes["Cube5"], shaders["SimpleShader"], glm::vec3(lightX, lightY, lightZ));
}

void Test::EndFrame()
{
}

void Test::OnInputUpdate(double delta_time, int mods)
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

void Test::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_R) {
		lightX = 0.0f;
		lightY = 0.5f;
		lightZ = 0.0f;
	}
}

void Test::OnKeyRelease(int key, int mods)
{
}

void Test::OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y)
{
}

void Test::OnMouseButtonPress(double x_pos, double y_pos, int key, int mods)
{
}

void Test::OnMouseButttonRelease(double x_pos, double y_pos, int key, int mods)
{
}

void Test::OnMouseScroll(double x_offset, double y_offset)
{
}
