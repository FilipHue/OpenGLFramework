#include "demo_directional_light.h"

DemoDirectionLight::DemoDirectionLight()
{
}

void DemoDirectionLight::Init()
{
    p_shape_manager->CreateCube("Cube1", 1.0, 1.0, 1.0);
    p_shape_manager->CreateCube("Cube2", 1.0, 1.0, 1.0);
    p_shape_manager->CreateCube("Cube3", 1.0, 1.0, 1.0);
    p_shape_manager->CreateCube("Cube4", 1.0, 1.0, 1.0);
    p_shape_manager->CreateCube("Cube5", 1.0, 1.0, 1.0);
    p_shape_manager->CreateCube("Cube6", 1.0, 1.0, 1.0);
    p_shape_manager->CreateCube("Cube7", 1.0, 1.0, 1.0);
    p_shape_manager->CreateCube("Cube8", 1.0, 1.0, 1.0);
    p_shape_manager->CreateCube("Cube9", 1.0, 1.0, 1.0);
    p_shape_manager->CreateCube("Cube10", 1.0, 1.0, 1.0);

    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\container.png")).c_str(), "container");
    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\container_specular.png")).c_str(), "container_sp");

    light = new LightProperties{
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(-0.2f, -1.0f, -0.3f),
        glm::vec3(1.0f, 1.0f, 0.8f),

        glm::vec3(0.1f, 0.1f, 0.1f),
        glm::vec3(0.5f, 0.5f, 0.5f)
    };

    cube_positions = {
        glm::vec3(0.0f,  0.0f,  0.0f),
        glm::vec3(2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f,  2.0f, -2.5f),
        glm::vec3(1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };
}

void DemoDirectionLight::StartFrame()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, p_window->resolution.x, p_window->resolution.y);
}

void DemoDirectionLight::Update(double delta_time)
{
    for (unsigned int i = 0; i < 10; i++)
    {
        glm::mat4 model_matrix = glm::mat4(1.0f);
        float angle = 20.0f * i;
        std::string cube_name = "Cube" + std::to_string(i + 1);

        model_matrix = glm::translate(model_matrix, cube_positions[i]);
        model_matrix = glm::rotate(model_matrix, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

        RenderMesh(meshes[cube_name.c_str()], shaders["DirectionalShader"], model_matrix, "container", light);
    }
}

void DemoDirectionLight::EndFrame()
{
}

void DemoDirectionLight::OnInputUpdate(double delta_time, int mods)
{
}

void DemoDirectionLight::OnKeyPress(int key, int mods)
{
}

void DemoDirectionLight::OnKeyRelease(int key, int mods)
{
}

void DemoDirectionLight::OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y)
{
}

void DemoDirectionLight::OnMouseButtonPress(double x_pos, double y_pos, int key, int mods)
{
}

void DemoDirectionLight::OnMouseButttonRelease(double x_pos, double y_pos, int key, int mods)
{
}

void DemoDirectionLight::OnMouseScroll(double x_offset, double y_offset)
{
}
