#include "scene.h"

Scene::Scene()
{
	InitScene();
}

Scene::~Scene()
{
}

void Scene::CreateMesh(const char* name, std::vector<VertexFormat>& vertices, std::vector<unsigned int>& indices)
{
	unsigned int VAO;

	VAO = InitFromData(vertices, indices);

	meshes[name] = new Mesh(name, VAO, vertices, indices);
}

void Scene::RenderMesh(Mesh* mesh, Shader* shader, glm::vec3 position)
{
	if (!mesh || !shader) {
		std::cout << "Render error!" << std::endl;
		return;
	}

	glm::mat4 modelMatrix(1);
	modelMatrix = glm::translate(modelMatrix, position);
	SendToShader(shader, modelMatrix);

	glBindVertexArray(mesh->GetVAO());
	glDrawElementsBaseVertex(GL_TRIANGLES, mesh->GetIndices().size(),
		GL_UNSIGNED_INT, (const void*)(sizeof(unsigned int) * mesh->GetIndices()[0]), 0);
	glBindVertexArray(0);
}

void Scene::RenderMesh(Mesh* mesh, Shader* shader, glm::vec3 position, const char* textureName)
{
	if (!mesh || !shader || !textureName) {
		std::cout << "Render error!" << std::endl;
		return;
	}

	glm::mat4 modelMatrix(1);
	modelMatrix = glm::translate(modelMatrix, position);
	SendToShader(shader, modelMatrix);

	glBindVertexArray(mesh->GetVAO());
	glBindTexture(GL_TEXTURE_2D, textureManager->GetTexture2D(textureName)->GetTextureID());
	glDrawElementsBaseVertex(GL_TRIANGLES, mesh->GetIndices().size(),
		GL_UNSIGNED_INT, (const void*)(sizeof(unsigned int) * mesh->GetIndices()[0]), 0);
	glBindVertexArray(0);
}

void Scene::RenderMesh(Mesh* mesh, Shader* shader, glm::mat4 modelMatrix)
{
	if (!mesh || !shader) {
		std::cout << "Render error!" << std::endl;
		return;
	}

	SendToShader(shader, modelMatrix);

	glBindVertexArray(mesh->GetVAO());
	glDrawElementsBaseVertex(GL_TRIANGLES, mesh->GetIndices().size(),
		GL_UNSIGNED_INT, (const void*)(sizeof(unsigned int) * mesh->GetIndices()[0]), 0);
	glBindVertexArray(0);
}

void Scene::RenderMesh(Mesh* mesh, Shader* shader, glm::mat4 modelMatrix, const char* textureName)
{
	if (!mesh || !shader || !textureName) {
		std::cout << "Render error!" << std::endl;
		return;
	}

	SendToShader(shader, modelMatrix);

	glBindVertexArray(mesh->GetVAO());
	glBindTexture(GL_TEXTURE_2D, textureManager->GetTexture2D(textureName)->GetTextureID());
	glDrawElementsBaseVertex(GL_TRIANGLES, mesh->GetIndices().size(),
		GL_UNSIGNED_INT, (const void*)(sizeof(unsigned int) * mesh->GetIndices()[0]), 0);
	glBindVertexArray(0);
}

void Scene::InitScene()
{
	window = Engine::GetWindow();

	sceneCamera = new Camera();
	sceneCamera->projectionMatrix = glm::perspective(glm::radians(sceneCamera->zoom), (float)window->resolution.x / (float)window->resolution.y, 0.1f, 200.0f);

	cameraInput = new CameraInput(sceneCamera);
	sceneInput = new SceneInput(this);

	textureManager = new TextureManger();

	Shader* simpleShader = new Shader(
		"D:\\Diverse\\OpenGLFramework\\FrameworkSln\\Framework\\engine\\shaders\\shader_programms\\simple\\simple_vertex_shader.glsl",
		"D:\\Diverse\\OpenGLFramework\\FrameworkSln\\Framework\\engine\\shaders\\shader_programms\\simple\\simple_fragment_shader.glsl"
	);
	shaders["SimpleShader"] = simpleShader;

	Shader* gridShader = new Shader(
		"D:\\Diverse\\OpenGLFramework\\FrameworkSln\\Framework\\engine\\shaders\\shader_programms\\grid\\grid_vertex_shader.glsl",
		"D:\\Diverse\\OpenGLFramework\\FrameworkSln\\Framework\\engine\\shaders\\shader_programms\\grid\\grid_fragment_shader.glsl"
	);
	shaders["GridShader"] = gridShader;

	Shader* textureShader = new Shader(
		"D:\\Diverse\\OpenGLFramework\\FrameworkSln\\Framework\\engine\\shaders\\shader_programms\\texture\\texture_vertex_shader.glsl",
		"D:\\Diverse\\OpenGLFramework\\FrameworkSln\\Framework\\engine\\shaders\\shader_programms\\texture\\texture_fragment_shader.glsl"
	);
	shaders["TextureShader"] = textureShader;

	glDepthMask(GL_TRUE);
	glEnable(GL_DEPTH_TEST);
}

unsigned int Scene::InitFromData(std::vector<VertexFormat>& vertices, std::vector<unsigned int>& indices)
{
	unsigned int VAO;
	unsigned int VBO;
	unsigned int IBO;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

	// Vertex position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);

	// Vertex normal
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

	// Vertex colour
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

	// Vertex texel
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(3 * sizeof(glm::vec3)));

	glBindVertexArray(0);

	return VAO;
}

void Scene::SendToShader(Shader* shader, glm::mat4 modelMatrix)
{
	sceneCamera->viewMatrix = glm::lookAt(sceneCamera->position, sceneCamera->position + sceneCamera->forward, sceneCamera->up);

	shader->Use();

	shader->SetMat4("projectionMatrix", sceneCamera->projectionMatrix);
	shader->SetMat4("viewMatrix", sceneCamera->viewMatrix);
	shader->SetMat4("modelMatrix", modelMatrix);
}
