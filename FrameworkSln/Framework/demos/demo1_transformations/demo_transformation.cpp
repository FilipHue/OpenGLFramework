#include "demo_transformation.h"

DemoTransformation::DemoTransformation()
{
}

void DemoTransformation::Init()
{
	p_shape_manager->CreateCube("Cube1", 1.0f, 1.0f, 1.0f);
	p_shape_manager->CreateCube("Cube2", 1.0f, 1.0f, 1.0f);
	p_shape_manager->CreateCube("Cube3", 1.0f, 1.0f, 1.0f);
	p_shape_manager->CreateCube("Cube4", 1.0f, 1.0f, 1.0f);
	p_shape_manager->CreateCube("Cube5", 1.0f, 1.0f, 1.0f);

	p_texture_manager->LoadTexture2D("D:\\Diverse\\OpenGLFramework\\FrameworkSln\\Framework\\assets\\textures\\container.png", "container", "diffuse");

	c1_pos_x = 0.0f;
	c1_pos_y = 0.0f;
	move_direction_x = 1.0f;
	move_direction_y = 0.0f;
	move_speed = 5.0f;
}

void DemoTransformation::StartFrame()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, p_window->resolution.x, p_window->resolution.y);
}

void DemoTransformation::Update(double delta_time)
{
	{
		if (c1_pos_x > 5.0f && c1_pos_y == 0.0f) {
			c1_pos_x = std::max(floor(c1_pos_x), 0.0f);
			move_direction_x = 0.0f;
			move_direction_y = 1.0f;
		}

		if (c1_pos_y > 5.0f && c1_pos_x == 5.0f) {
			c1_pos_y = std::max(floor(c1_pos_x), 0.0f);
			move_direction_x = -1.0f;
			move_direction_y = 0.0f;
		}

		if (c1_pos_x < 0.0f && c1_pos_y == 5.0f) {
			c1_pos_x = std::max(floor(c1_pos_x), 0.0f);
			move_direction_x = 0.0f;
			move_direction_y = -1.0f;
		}

		if (c1_pos_y < 0.0f && c1_pos_x == 0.0f) {
			c1_pos_y = std::max(floor(c1_pos_y), 0.0f);
			move_direction_x = 1.0f;
			move_direction_y = 0.0f;
		}

		c1_pos_x += (float)delta_time * move_speed * move_direction_x;
		c1_pos_y += (float)delta_time * move_speed * move_direction_y;

		RenderMesh(meshes["Cube1"], shaders["SimpleShader"], glm::vec3(c1_pos_x, c1_pos_y, -5.0f));
	}

	{

	}
}

void DemoTransformation::EndFrame()
{
}

void DemoTransformation::OnInputUpdate(double delta_time, int mods)
{
}

void DemoTransformation::OnKeyPress(int key, int mods)
{
}

void DemoTransformation::OnKeyRelease(int key, int mods)
{
}

void DemoTransformation::OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y)
{
}

void DemoTransformation::OnMouseButtonPress(double x_pos, double y_pos, int key, int mods)
{
}

void DemoTransformation::OnMouseButttonRelease(double x_pos, double y_pos, int key, int mods)
{
}

void DemoTransformation::OnMouseScroll(double x_offset, double y_offset)
{
}
