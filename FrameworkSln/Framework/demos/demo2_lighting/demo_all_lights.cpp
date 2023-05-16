#include "demo_all_lights.h"

DemoAllLights::DemoAllLights()
{
}

void DemoAllLights::Init()
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

    p_shape_manager->CreateCube("PointLight1", 0.1f, 0.1f, 0.1f);
    p_shape_manager->CreateCube("PointLight2", 0.1f, 0.1f, 0.1f);
    p_shape_manager->CreateCube("PointLight3", 0.1f, 0.1f, 0.1f);
    p_shape_manager->CreateCube("PointLight4", 0.1f, 0.1f, 0.1f);

    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\container.png")).c_str(), "container", "diffuse");
    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\container_specular.png")).c_str(), "container_sp", "specular");

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

    point_light_positions = {
        glm::vec3(0.7f,  0.2f,  2.0f),
        glm::vec3(2.3f, -3.3f, -4.0f),
        glm::vec3(-4.0f,  2.0f, -12.0f),
        glm::vec3(0.0f,  0.0f, -3.0f)
    };

    light = new DirectionalLight{
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(-0.2f, -1.0f, -0.3f),
        glm::vec3(1.0f, 0.0f, 0.0f),

        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.05f, 0.05f, 0.05f),
        glm::vec3(0.2f, 0.2f, 0.2f),
        32.0f,

        "directLight"
    };
    lights.push_back(light);

    for (int i = 0; i < point_light_positions.size(); i++) {
        point_lights.push_back(new PointLight{
            point_light_positions[i],
            glm::vec3(0.0f, 1.0f, 0.0f),

            glm::vec3(0.01f, 0.01f, 0.01f),
            glm::vec3(0.1f, 0.1f, 0.1f),
            glm::vec3(0.1f, 0.1f, 0.1f),
            32.0f,

            1.0f,
            0.14f,
            0.07f,

            "pointLights[" + std::to_string(i) + "]"
            }
        );
        lights.push_back(point_lights[i]);
    }

    spotlight = new Spotlight{
        p_scene_camera->GetCameraPosition(),
        p_scene_camera->GetCameraForward(),
        glm::vec3(0.0f, 0.0f, 0.1f),

        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.1f, 0.1f, 0.1f),
        glm::vec3(1.0f, 1.0f, 1.0f),
        32.0f,

        1.0f,
        0.09f,
        0.032f,

        glm::cos(glm::radians(10.0f)),
        glm::cos(glm::radians(15.0f)),

        "spotlight"
    };
    lights.push_back(spotlight);
}

void DemoAllLights::StartFrame()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, p_window->resolution.x, p_window->resolution.y);
}

void DemoAllLights::Update(double delta_time)
{
    spotlight->position = p_scene_camera->GetCameraPosition();
    spotlight->direction = p_scene_camera->GetCameraForward();

    for (unsigned int i = 0; i < point_lights.size(); i++) {
        RenderMesh(
            meshes["PointLight" + std::to_string(i + 1)],
            shaders["SimpleShader"], point_light_positions[i], {}, {});
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        glm::mat4 model_matrix = glm::mat4(1.0f);
        float angle = 20.0f * i;
        std::string cube_name = "Cube" + std::to_string(i + 1);

        model_matrix = glm::translate(model_matrix, cube_positions[i]);
        model_matrix = glm::rotate(model_matrix, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

        RenderMesh(
            meshes[cube_name.c_str()],
            shaders["AllLightsShader"], model_matrix, { "container" }, lights);
    }
}

void DemoAllLights::EndFrame()
{
}

void DemoAllLights::OnInputUpdate(double delta_time, int mods)
{
}

void DemoAllLights::OnKeyPress(int key, int mods)
{
}

void DemoAllLights::OnKeyRelease(int key, int mods)
{
}

void DemoAllLights::OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y)
{
}

void DemoAllLights::OnMouseButtonPress(double x_pos, double y_pos, int key, int mods)
{
}

void DemoAllLights::OnMouseButttonRelease(double x_pos, double y_pos, int key, int mods)
{
}

void DemoAllLights::OnMouseScroll(double x_offset, double y_offset)
{
}
