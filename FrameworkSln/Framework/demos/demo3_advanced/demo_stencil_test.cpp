#include "demo_stencil_test.h"

DemoStencilTest::DemoStencilTest()
{
}

void DemoStencilTest::Init()
{
    p_shape_manager->CreateCube("Cube0", 1.0, 1.0, 1.0);
    p_shape_manager->CreateCube("Cube1", 1.0, 1.0, 1.0);

    p_shape_manager->CreateRectangleY("Floor", 15.0, 15.0);

    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\metal.png")).c_str(), "metal", "diffuse");
    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\marble.jpg")).c_str(), "marble", "diffuse");

    scale = 1.05f;

    EnableStencilTest();
    UseDepthFunction(GL_LESS);
    UseStencilFunction(GL_NOTEQUAL, 1, 0xFF);
    UseStencilOption(GL_KEEP, GL_KEEP, GL_REPLACE);
}

void DemoStencilTest::StartFrame()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glViewport(0, 0, p_window->resolution.x, p_window->resolution.y);
}

void DemoStencilTest::Update(double delta_time)
{
    SetStencilMask(0x00);

    glm::mat4 model_matrix = glm::mat4(1.0f);
    model_matrix = glm::translate(model_matrix, glm::vec3(-7.5f, 0.0f, -7.5f));
    RenderMesh(meshes["Floor"], shaders["StencilShader"], model_matrix, { "metal" }, {});

    UseStencilFunction(GL_ALWAYS, 1, 0xFF);
    SetStencilMask(0xFF);

    model_matrix = glm::mat4(1.0f);
    model_matrix = glm::translate(model_matrix, glm::vec3(-1.0f, 0.0f, -1.0f));
    RenderMesh(meshes["Cube0"], shaders["StencilShader"], model_matrix, { "marble" }, {});

    model_matrix = glm::mat4(1.0f);
    model_matrix = glm::translate(model_matrix, glm::vec3(2.0f, 0.0f, 0.0f));
    RenderMesh(meshes["Cube1"], shaders["StencilShader"], model_matrix, { "marble" }, {});

    UseStencilFunction(GL_NOTEQUAL, 1, 0xFF);
    SetStencilMask(0x00);
    DisableDepthTest();

    model_matrix = glm::mat4(1.0f);
    model_matrix = glm::translate(model_matrix, glm::vec3(-1.0f, 0.0f, -1.0f));
    model_matrix = glm::scale(model_matrix, glm::vec3(scale, scale, scale));
    RenderMesh(meshes["Cube0"], shaders["SingleColourShader"], model_matrix, { "marble" }, {});

    model_matrix = glm::mat4(1.0f);
    model_matrix = glm::translate(model_matrix, glm::vec3(2.0f, 0.0f, 0.0f));
    model_matrix = glm::scale(model_matrix, glm::vec3(scale, scale, scale));
    RenderMesh(meshes["Cube1"], shaders["SingleColourShader"], model_matrix, { "marble" }, {});

    SetStencilMask(0xFF);
    UseStencilFunction(GL_ALWAYS, 0, 0xFF);
    EnableDepthTest();
}

void DemoStencilTest::EndFrame()
{
}

void DemoStencilTest::OnInputUpdate(double delta_time, int mods)
{
}

void DemoStencilTest::OnKeyPress(int key, int mods)
{
}

void DemoStencilTest::OnKeyRelease(int key, int mods)
{
}

void DemoStencilTest::OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y)
{
}

void DemoStencilTest::OnMouseButtonPress(double x_pos, double y_pos, int key, int mods)
{
}

void DemoStencilTest::OnMouseButttonRelease(double x_pos, double y_pos, int key, int mods)
{
}

void DemoStencilTest::OnMouseScroll(double x_offset, double y_offset)
{
}
