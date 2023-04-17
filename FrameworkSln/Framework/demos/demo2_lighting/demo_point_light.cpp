#include "demo_point_light.h"

DemoPointLight::DemoPointLight()
{
}

void DemoPointLight::Init()
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
    p_shape_manager->CreateCube("Light", 0.1, 0.1, 0.1);

    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\container.png")).c_str(), "container");
    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\container_specular.png")).c_str(), "container_sp");

    light = new PointLight{
        glm::vec3(lightX, lightY, lightZ),
        glm::vec3(1.0f, 1.0f, 0.8f),

        glm::vec3(0.2f, 0.2f, 0.2f),
        glm::vec3(0.5f, 0.5f, 0.5f),
        glm::vec3(1.0f, 1.0f, 1.0f),
        32.0f,

        1.0f,
        0.09f,
        0.032f, 

        "light"
    };

    lightX = 0.0f;
    lightY = 0.5f;
    lightZ = 5.0f;

    lightMoveSpeed = 2.0f;

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

void DemoPointLight::StartFrame()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, p_window->resolution.x, p_window->resolution.y);
}

void DemoPointLight::Update(double delta_time)
{
    light->position = glm::vec3(lightX, lightY, lightZ);

    for (unsigned int i = 0; i < 10; i++)
    {
        glm::mat4 model_matrix = glm::mat4(1.0f);
        float angle = 20.0f * i;
        std::string cube_name = "Cube" + std::to_string(i + 1);

        model_matrix = glm::translate(model_matrix, cube_positions[i]);
        model_matrix = glm::rotate(model_matrix, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

        RenderMesh(meshes[cube_name.c_str()], shaders["PointShader"], model_matrix, "container", light);
    }
    RenderMesh(meshes["Light"], shaders["SimpleShader"], glm::vec3(lightX, lightY, lightZ), NULL, NULL);
}

void DemoPointLight::EndFrame()
{
}

void DemoPointLight::OnInputUpdate(double delta_time, int mods)
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

void DemoPointLight::OnKeyPress(int key, int mods)
{
    if (key == GLFW_KEY_R) {
        lightX = 0.0f;
        lightY = 0.5f;
        lightZ = 5.0f;
    }
}

void DemoPointLight::OnKeyRelease(int key, int mods)
{
}

void DemoPointLight::OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y)
{
}

void DemoPointLight::OnMouseButtonPress(double x_pos, double y_pos, int key, int mods)
{
}

void DemoPointLight::OnMouseButttonRelease(double x_pos, double y_pos, int key, int mods)
{
}

void DemoPointLight::OnMouseScroll(double x_offset, double y_offset)
{
}
