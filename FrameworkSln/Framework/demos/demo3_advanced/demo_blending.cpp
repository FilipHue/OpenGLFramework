#include "demo_blending.h"

DemoBlending::DemoBlending()
{
}

void DemoBlending::Init()
{
    p_shape_manager->CreateCube("Cube0", 1.0, 1.0, 1.0);
    p_shape_manager->CreateCube("Cube1", 1.0, 1.0, 1.0);

    p_shape_manager->CreateRectangleY("Floor", 15.0, 15.0);

    p_shape_manager->CreateRectangleZ("Pane0", 1.0, 1.0);
    p_shape_manager->CreateRectangleZ("Pane1", 1.0, 1.0);
    p_shape_manager->CreateRectangleZ("Pane2", 1.0, 1.0);
    p_shape_manager->CreateRectangleZ("Pane3", 1.0, 1.0);
    p_shape_manager->CreateRectangleZ("Pane4", 1.0, 1.0);

    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\metal.png")).c_str(), "metal", "diffuse");
    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\marble.jpg")).c_str(), "marble", "diffuse");
    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\transparent_window.png")).c_str(), "window", "diffuse");
    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\grass.png")).c_str(), "grass", "diffuse", GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);

    positions = {
        glm::vec3(-1.0f, 0.0f, 0.01f),
        glm::vec3(2.0f, 0.0f, 1.01f),
        glm::vec3(0.0f, 0.0f, 0.7f),
        glm::vec3(-0.3f, 0.0f, -2.3f),
        glm::vec3(0.5f, 0.0f, -0.6f)
    };

    p_texture_manager->EnableBlending();
    p_texture_manager->UseBlendFunction(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void DemoBlending::StartFrame()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, p_window->resolution.x, p_window->resolution.y);

    sorted.clear();
    for (unsigned int i = 0; i < positions.size(); i++)
    {
        float distance = glm::length(p_scene_camera->GetCameraPosition() - positions[i]);
        sorted[distance] = positions[i];
    }
}

void DemoBlending::Update(double delta_time)
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

    for (std::map<float, glm::vec3>::reverse_iterator it = sorted.rbegin(); it != sorted.rend(); ++it)
    {
        std::string name = "Pane";

        model_matrix = glm::mat4(1.0f);
        model_matrix = glm::translate(model_matrix, it->second);

        name += std::to_string(std::distance(sorted.rbegin(), it));
        RenderMesh(meshes[name], shaders["BlendShader"], model_matrix, { "window" }, {});
    }
}

void DemoBlending::EndFrame()
{
}

void DemoBlending::OnInputUpdate(double delta_time, int mods)
{
}

void DemoBlending::OnKeyPress(int key, int mods)
{
}

void DemoBlending::OnKeyRelease(int key, int mods)
{
}

void DemoBlending::OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y)
{

}

void DemoBlending::OnMouseButtonPress(double x_pos, double y_pos, int key, int mods)
{
}

void DemoBlending::OnMouseButttonRelease(double x_pos, double y_pos, int key, int mods)
{
}

void DemoBlending::OnMouseScroll(double x_offset, double y_offset)
{
}
