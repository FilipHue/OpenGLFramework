#include "Test.h"

Test::Test()
{
}

Test::~Test()
{
}

void Test::Init()
{
	std::vector<VertexFormat> vertices1 = {
		VertexFormat(glm::vec3(-0.5f, -0.5f, 0.0f)),
		VertexFormat(glm::vec3(0.5f, -0.5f, 0.0f)),
		VertexFormat(glm::vec3(0.0f, 0.f, 0.0f))
	};

	std::vector<unsigned int> indices1 = {
		0, 1, 2
	};

	CreateMesh("Triangle1", vertices1, indices1);

	std::vector<VertexFormat> vertices2 = {
		VertexFormat(glm::vec3(0.0f, 1.0f, 0.0f)),
		VertexFormat(glm::vec3(1.0f, 0.0f, 0.0f)),
		VertexFormat(glm::vec3(1.0f, 1.0f, 0.0f))
	};

	std::vector<unsigned int> indices2 = {
		0, 1, 2
	};

	CreateMesh("Triangle2", vertices2, indices2);

	std::vector<VertexFormat> vertices3 = {
		VertexFormat(glm::vec3(0, 0, 0)),
		VertexFormat(glm::vec3(10, 0, 0), glm::vec3(0, 1, 0), GREEN, glm::vec2(1, 0)),
		VertexFormat(glm::vec3(10, 10 ,0), glm::vec3(0, 1, 0), RED, glm::vec2(1, 1)),
		VertexFormat(glm::vec3(0, 10, 0), glm::vec3(0, 1, 0), BLUE, glm::vec2(0, 1)),
		VertexFormat(glm::vec3(0, 0, 10)),
		VertexFormat(glm::vec3(10, 0, 10), glm::vec3(0, 1, 0), GREEN, glm::vec2(1, 0)),
		VertexFormat(glm::vec3(10, 10 ,10), glm::vec3(0, 1, 0), RED, glm::vec2(1, 1)),
		VertexFormat(glm::vec3(0, 10, 10), glm::vec3(0, 1, 0), BLUE, glm::vec2(0, 1)),
	};

	std::vector<unsigned int> indices3 = {
		0, 1, 2,
		0, 2, 3,
		1, 5, 6,
		1, 6, 2,
		4, 5, 6,
		4, 6, 7,
		0, 4, 7,
		0, 7, 3,
		0, 1, 5,
		0, 5, 4,
		3, 2, 6,
		3, 6, 7
	};

	CreateMesh("Cube1", vertices3, indices3);

	std::vector<VertexFormat> vertices4 = {
		VertexFormat(glm::vec3(0, 0, 0)),
		VertexFormat(glm::vec3(10, 0, 0), glm::vec3(0, 1, 0), RED, glm::vec2(1, 0)),
		VertexFormat(glm::vec3(10, 10, 0), glm::vec3(0, 1, 0), GREEN, glm::vec2(1, 1)),
		VertexFormat(glm::vec3(0, 10, 0), glm::vec3(0, 1, 0), BLUE, glm::vec2(0, 1))
	};

	std::vector<unsigned int> indices4 = {
		0, 1, 2,
		0, 2, 3
	};

	CreateMesh("Square1", vertices4, indices4);

	std::vector<VertexFormat> vertices5 = {
		VertexFormat(glm::vec3(0, 0, 0)),
		VertexFormat(glm::vec3(20, 0, 0), glm::vec3(0, 1, 0), RED, glm::vec2(1, 0)),
		VertexFormat(glm::vec3(20, 20, 0), glm::vec3(0, 1, 0), GREEN, glm::vec2(1, 1)),
		VertexFormat(glm::vec3(0, 20, 0), glm::vec3(0, 1, 0), BLUE, glm::vec2(0, 1))
	};

	std::vector<unsigned int> indices5 = {
		0, 1, 2,
		0, 2, 3
	};

	CreateMesh("Square2", vertices5, indices5);

	textureManager->LoadTexture2D("D:\\Diverse\\OpenGLFramework\\FrameworkSln\\Framework\\engine\\texture\\textures\\crate.jpg", "crate");
	textureManager->LoadTexture2D("D:\\Diverse\\OpenGLFramework\\FrameworkSln\\Framework\\engine\\texture\\textures\\default.png", "grid");

	/*std::map<std::string, Mesh*>::iterator it;
	for (it = meshes.begin(); it != meshes.end(); it++) {
		std::cout << it->second->GetMeshId() << std::endl;
	}*/
}

void Test::StartFrame()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, window->resolution.x, window->resolution.y);
}

void Test::Update(double delta_time)
{
	/*RenderMesh(meshes["Triangle1"], shaders["SimpleShader"], glm::vec3(0, 0, 0));
	RenderMesh(meshes["Triangle2"], shaders["SimpleShader"], glm::vec3(10, 0, 0))*/

	/*glm::mat4 modelCube = glm::mat4(1);
	RenderMesh(meshes["Cube1"], shaders["SimpleShader"], modelCube);*/

	RenderMesh(meshes["Square1"], shaders["TextureShader"], glm::mat4(1), "crate");
	RenderMesh(meshes["Square2"], shaders["SimpleShader"], glm::vec3(10, 0, 0));
}

void Test::EndFrame()
{
}

void Test::OnInputUpdate(double deltaTime, int mods)
{
}

void Test::OnKeyPress(int key, int mods)
{	
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
