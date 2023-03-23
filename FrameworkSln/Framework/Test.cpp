#include "Test.h"

Test::Test()
{
}

Test::~Test()
{
}

void Test::Init()
{
	shapeManager->CreateRectangleX("Square1", 10, 10);
	shapeManager->CreateRectangleY("Square2", 10, 10);
	shapeManager->CreateRectangleZ("Square3", 50, 50);

	shapeManager->CreateCube("Cube1", 1, 1, 1);
	shapeManager->CreateCube("Cube2", 1, 1, 1);
	shapeManager->CreateCube("Cube3", 10, 1, 10);
	shapeManager->CreateCube("Cube4", 1, 1, 1);
	shapeManager->CreateCube("Cube5", 0.1, 0.1, 0.1);

	textureManager->LoadTexture2D("D:\\Diverse\\OpenGLFramework\\FrameworkSln\\Framework\\engine\\texture\\textures\\crate.jpg", "crate");
	textureManager->LoadTexture2D("D:\\Diverse\\OpenGLFramework\\FrameworkSln\\Framework\\engine\\texture\\textures\\default.png", "grid");

	lightMoveSpeed = 2.0f;
	lightX = 0.0f;
	lightY = 0.5f;
	lightZ = 0.0f;
}

void Test::StartFrame()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, window->resolution.x, window->resolution.y);
}

void Test::Update(double deltaTime)
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

void Test::OnInputUpdate(double deltaTime, int mods)
{
	if (window->GetKeyState(GLFW_KEY_UP) && mods != GLFW_MOD_SHIFT) {
		lightZ += deltaTime * lightMoveSpeed;
	}

	if (window->GetKeyState(GLFW_KEY_DOWN) && mods != GLFW_MOD_SHIFT) {
		lightZ -= deltaTime * lightMoveSpeed;
	}

	if (window->GetKeyState(GLFW_KEY_LEFT)) {
		lightX += deltaTime * lightMoveSpeed;
	}

	if (window->GetKeyState(GLFW_KEY_RIGHT)) {
		lightX -= deltaTime * lightMoveSpeed;
	}

	if (window->GetKeyState(GLFW_KEY_UP) && mods == GLFW_MOD_SHIFT) {
		lightY += deltaTime * lightMoveSpeed;
	}

	if (window->GetKeyState(GLFW_KEY_DOWN) && mods == GLFW_MOD_SHIFT) {
		lightY -= deltaTime * lightMoveSpeed;
	}

	/*lightX += cos(Engine::GetElapsedTime()) / 10;
	lightZ += sin(Engine::GetElapsedTime()) / 10;*/
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

void Test::OnMouseMove(double mouseX, double mouseY, double deltaX, double deltaY)
{
}

void Test::OnMouseButtonPress(double mouseX, double mouseY, int button, int mods)
{
}

void Test::OnMouseButttonRelease(double mouseX, double mouseY, int button, int mods)
{
}

void Test::OnMouseScroll(double mouseX, double mouseY, double deltaX, double deltaY)
{
}

void Test::OnWindowResize(int width, int height)
{
}
