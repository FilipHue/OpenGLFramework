#include "Demo.h"

Demo::Demo()
{
}

void Demo::Init()
{
	p_shape_manager->CreateCube("Cube0", 1.0, 1.0, 1.0);
	p_shape_manager->CreateCube("Cube1", 1.0, 1.0, 1.0);

	p_shape_manager->CreateRectangleY("Floor", 15.0, 15.0);

	p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\metal.png")).c_str(), "metal", "diffuse");
	p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\marble.jpg")).c_str(), "marble", "diffuse");
}

void Demo::StartFrame()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, p_window->resolution.x, p_window->resolution.y);
}

void Demo::Update(double delta_time)
{
	glm::mat4 model_matrix = glm::mat4(1.0f);
	model_matrix = glm::translate(model_matrix, glm::vec3(-1.0f, 0.0f, -1.0f));
	RenderMesh(meshes["Cube0"], shaders["TextureShader"], model_matrix, { "marble" }, {});

	model_matrix = glm::mat4(1.0f);
	model_matrix = glm::translate(model_matrix, glm::vec3(2.0f, 0.0f, 0.0f));
	RenderMesh(meshes["Cube1"], shaders["TextureShader"], model_matrix, { "marble" }, {});

	model_matrix = glm::mat4(1.0f);
	model_matrix = glm::translate(model_matrix, glm::vec3(-7.5f, 0.0f, -7.5f));
	RenderMesh(meshes["Floor"], shaders["TextureShader"], model_matrix, { "metal" }, {});
}

void Demo::EndFrame()
{
}

void Demo::OnInputUpdate(double delta_time, int mods)
{
}

void Demo::OnKeyPress(int key, int mods)
{
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
