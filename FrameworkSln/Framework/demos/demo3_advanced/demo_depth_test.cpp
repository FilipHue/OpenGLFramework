#include "demo_depth_test.h"

DemoDepthTest::DemoDepthTest()
{
}

void DemoDepthTest::Init()
{
    // The scene from the light demos \\
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

    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\container.png")).c_str(), "container", "diffuse");

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
    // ------------------------------ \\

    p_shape_manager->CreateCube("Cube11", 1.0, 1.0, 1.0);
    p_shape_manager->CreateCube("Cube12", 1.0, 1.0, 1.0);

    p_shape_manager->CreateRectangleY("Floor", 15.0, 15.0);

    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\metal.png")).c_str(), "metal", "diffuse");
    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\marble.jpg")).c_str(), "marble", "diffuse");


    /*
    * Uncomment the lines bellow to see what happens
    */

    //DisableDepthTest();
    //UseDepthFunction(GL_ALWAYS);
    //UseDepthFunction(GL_NEVER);
    //UseDepthFunction(GL_LESS);
    //UseDepthFunction(GL_EQUAL);
    //UseDepthFunction(GL_LEQUAL);
    //UseDepthFunction(GL_GREATER);
    //UseDepthFunction(GL_NOTEQUAL);
    //UseDepthFunction(GL_GEQUAL);
    //DisableDepthMask();
}

void DemoDepthTest::StartFrame()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, p_window->resolution.x, p_window->resolution.y);
}

void DemoDepthTest::Update(double delta_time)
{
    /*for (unsigned int i = 0; i < 10; i++)
    {
        glm::mat4 model_matrix = glm::mat4(1.0f);
        float angle = 20.0f * i;
        std::string cube_name = "Cube" + std::to_string(i + 1);

        model_matrix = glm::translate(model_matrix, cube_positions[i]);
        model_matrix = glm::rotate(model_matrix, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

        RenderMesh(meshes[cube_name.c_str()], shaders["TextureShader"], model_matrix, { "container" }, {});
    }*/

    /*
    * Use TextureShader to render the objects as usual
    * Use DepthShader to visualise the depth buffer. See the fragment shader for more information
    */

    glm::mat4 model_matrix = glm::mat4(1.0f);
    model_matrix = glm::translate(model_matrix, glm::vec3(-1.0f, 0.0f, -1.0f));
    RenderMesh(meshes["Cube11"], shaders["DepthShader"], model_matrix, { "marble" }, {});

    model_matrix = glm::mat4(1.0f);
    model_matrix = glm::translate(model_matrix, glm::vec3(2.0f, 0.0f, 0.0f));
    RenderMesh(meshes["Cube12"], shaders["DepthShader"], model_matrix, { "marble" }, {});

    model_matrix = glm::mat4(1.0f);
    model_matrix = glm::translate(model_matrix, glm::vec3(-7.5f, 0.0f, -7.5f));
    RenderMesh(meshes["Floor"], shaders["DepthShader"], model_matrix, { "metal" }, {});
}

void DemoDepthTest::EndFrame()
{
}

void DemoDepthTest::OnInputUpdate(double delta_time, int mods)
{
}

void DemoDepthTest::OnKeyPress(int key, int mods)
{
}

void DemoDepthTest::OnKeyRelease(int key, int mods)
{
}

void DemoDepthTest::OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y)
{
}

void DemoDepthTest::OnMouseButtonPress(double x_pos, double y_pos, int key, int mods)
{
}

void DemoDepthTest::OnMouseButttonRelease(double x_pos, double y_pos, int key, int mods)
{
}

void DemoDepthTest::OnMouseScroll(double x_offset, double y_offset)
{
}
