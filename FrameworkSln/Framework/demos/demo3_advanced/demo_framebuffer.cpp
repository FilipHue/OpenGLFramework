#include "demo_framebuffer.h"

DemoFramebuffer::DemoFramebuffer()
{
}

void DemoFramebuffer::Init()
{
    p_shape_manager->CreateCube("Cube0", 1.0, 1.0, 1.0);
    p_shape_manager->CreateCube("Cube1", 1.0, 1.0, 1.0);

    p_shape_manager->CreateRectangleY("Floor", 15.0, 15.0);

    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\metal.png")).c_str(), "metal", "diffuse");
    p_texture_manager->LoadTexture2D((p_window->project_dir + std::string("\\assets\\textures\\container.png")).c_str(), "container", "diffuse");

    glGenFramebuffers(1, &fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);

    glGenTextures(1, &textureColorbuffer);
    glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, p_window->resolution.x, p_window->resolution.y, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureColorbuffer, 0);

    glGenRenderbuffers(1, &rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, p_window->resolution.x, p_window->resolution.y);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    vertices = {
        Vertex(glm::vec3(-1.0f, 1.0f, 0.0f), WHITE, glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 1.0f)),
        Vertex(glm::vec3(-1.0f, -1.0f, 0.0f), WHITE, glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 0.0f)),
        Vertex(glm::vec3(1.0f, -1.0f, 0.0f), WHITE, glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 0.0f)),
        Vertex(glm::vec3(1.0f, 1.0f, 0.0f), WHITE, glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 1.0f))
    };

    indices = {
        0, 1, 3,
        1, 2, 3
    };

    CreateMesh("Screen", vertices, indices, nullptr);
}

void DemoFramebuffer::StartFrame()
{
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    EnableDepthTest();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, p_window->resolution.x, p_window->resolution.y);
}

void DemoFramebuffer::Update(double delta_time)
{
    glm::mat4 model_matrix = glm::mat4(1.0f);
    model_matrix = glm::translate(model_matrix, glm::vec3(-1.0f, 0.01f, -1.0f));
    RenderMesh(meshes["Cube0"], shaders["TextureShader"], model_matrix, { "container" }, {});

    model_matrix = glm::mat4(1.0f);
    model_matrix = glm::translate(model_matrix, glm::vec3(2.0f, 0.01f, 0.0f));
    RenderMesh(meshes["Cube1"], shaders["TextureShader"], model_matrix, { "container" }, {});

    model_matrix = glm::mat4(1.0f);
    model_matrix = glm::translate(model_matrix, glm::vec3(-7.5f, 0.0f, -7.5f));
    RenderMesh(meshes["Floor"], shaders["TextureShader"], model_matrix, { "metal" }, {});
}

void DemoFramebuffer::EndFrame()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    DisableDepthTest();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    shaders["FramebufferShader"]->Use();

    glBindVertexArray(meshes["Screen"]->GetVAO());
    glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
    glDrawElementsBaseVertex(GL_TRIANGLES, meshes["Screen"]->GetIndices().size(),
        GL_UNSIGNED_INT, (const void*)(sizeof(unsigned int) * meshes["Screen"]->GetIndices()[0]), 0);
}

void DemoFramebuffer::OnInputUpdate(double delta_time, int mods)
{
}

void DemoFramebuffer::OnKeyPress(int key, int mods)
{
}

void DemoFramebuffer::OnKeyRelease(int key, int mods)
{
}

void DemoFramebuffer::OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y)
{
}

void DemoFramebuffer::OnMouseButtonPress(double x_pos, double y_pos, int key, int mods)
{
}

void DemoFramebuffer::OnMouseButttonRelease(double x_pos, double y_pos, int key, int mods)
{
}

void DemoFramebuffer::OnMouseScroll(double x_offset, double y_offset)
{
}
