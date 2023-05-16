#include "scene.h"

Scene::Scene()
{
	Init();
}

void Scene::CreateMesh(const char* name, std::vector<Vertex>& vertices, std::vector<unsigned int>& indices, Material* material)
{
	unsigned int VAO;

	VAO = InitFromData(vertices, indices);

	meshes[name] = new Mesh(name, VAO, vertices, indices, material);
}

void Scene::RenderMesh(Mesh* mesh, Shader* shader, glm::vec3 position, std::vector<std::string> texture_names, std::vector<Light*> lights)
{
	glm::mat4 model_matrix(1);
	model_matrix = glm::translate(model_matrix, position);

	RenderMesh(mesh, shader, model_matrix, texture_names, lights);
}

void Scene::RenderMesh(Mesh* mesh, Shader* shader, glm::mat4 model_matrix, std::vector<std::string> texture_names, std::vector<Light*> lights)
{
	if (!mesh || !shader) {
		RENDER_ERROR("Mesh or shader missing");
		return;
	}

	SendToShader(mesh, shader, model_matrix, lights.empty() ? 0 : 1);

	if (!lights.empty()) {
		glm::vec3 object_colour = glm::vec3(GREY.red, GREY.green, GREY.blue);
		glm::vec3 view_position = p_scene_camera->GetCameraPosition();

		for (auto light : lights) {
			light->SendToShader(shader);
		}

		shader->SetVec3("objectColour", object_colour);
		shader->SetVec3("viewPosition", view_position);
	}

	if (!texture_names.empty()) {
		unsigned int diffuse_count = 0;
		unsigned int specular_count = 0;

		for (int i = 0; i < texture_names.size(); i++) {
			std::string texture_location = "";
			glActiveTexture(GL_TEXTURE0 + i);
			if (p_texture_manager->GetTexture2DType(texture_names[i]) == "diffuse") {
				texture_location = texture_location + "Kd" + std::to_string(diffuse_count);
				diffuse_count++;
			}
			else if (p_texture_manager->GetTexture2DType(texture_names[i]) == "specular") {
				texture_location = texture_location + "Ksp" + std::to_string(specular_count);
				specular_count++;
			}
			shader->SetInt(("material." + texture_location).c_str(), i);

			glBindTexture(GL_TEXTURE_2D, p_texture_manager->GetTexture2D(texture_names[i])->GetTextureID());
		}
	}

	glBindVertexArray(mesh->GetVAO());
	glDrawElementsBaseVertex(GL_TRIANGLES, mesh->GetIndices().size(),
		GL_UNSIGNED_INT, (const void*)(sizeof(unsigned int) * mesh->GetIndices()[0]), 0);
	glBindVertexArray(0);
}

void Scene::EnableDepthTest()
{	
	if (depth_test == false) {
		glEnable(GL_DEPTH_TEST);
		depth_test = true;
	}
}

void Scene::DisableDepthTest()
{
	if (depth_test == true) {
		glDisable(GL_DEPTH_TEST);
		depth_test = false;
	}
}

void Scene::EnableDepthMask()
{
	if (depth_mask == false) {
		glDepthMask(GL_TRUE);
		depth_mask = true;
	}
}

void Scene::DisableDepthMask()
{
	if (depth_mask == true) {
		glDepthMask(GL_FALSE);
		depth_mask = false;
	}
}

void Scene::EnableStencilTest()
{
	if (stencil_test == false) {
		glEnable(GL_STENCIL_TEST);
		stencil_test = true;
	}
}

void Scene::DisableStencilTest()
{
	if (stencil_test == true) {
		glDisable(GL_STENCIL_TEST);
		stencil_test = false;
	}
}

void Scene::SetStencilMask(GLuint mask)
{
	if (stencil_test == false) {
		RENDER_WARN("Stencil test is disabled");
		return;
	}

	glStencilMask(mask);
}

void Scene::UseStencilFunction(GLenum function, GLint reference, GLuint mask)
{
	if (stencil_test == false) {
		RENDER_WARN("Stencil test is disabled");
		return;
	}

	glStencilFunc(function, reference, mask);
}

void Scene::UseStencilOption(GLenum stencil_fail, GLenum stencil_pass_depth_fail, GLenum both_pass)
{
	if (stencil_test == false) {
		RENDER_WARN("Stencil test is disabled");
		return;
	}

	glStencilOp(stencil_fail, stencil_pass_depth_fail, both_pass);
}

void Scene::UseDepthFunction(GLenum function)
{
	if (depth_test == false) {
		RENDER_WARN("Depth testing is disabled");
		return;
	}

	glDepthFunc(function);
}

void Scene::Init()
{
	p_window = Engine::GetWindow();

	p_scene_camera = new Camera();
	p_scene_camera->SetPerspective(p_scene_camera->GetCameraZoom(), (float)p_window->resolution.x / p_window->resolution.y, 0.1f, 200.0f);
	p_camera_input = new CameraInput(p_scene_camera);
	p_scene_input = new SceneInput(this);

	p_shape_manager = new ShapeManager(this);
	p_texture_manager = new TextureManger();

	depth_test = true;
	depth_mask = true;

	std::unordered_map<std::string, std::string> vertex_files;
	std::unordered_map<std::string, std::string> fragment_files;

	FileManager::GetShaderFiles(p_window->project_dir + "\\assets\\shaders", vertex_files, fragment_files);

	for (
		auto vertex_file = vertex_files.begin(), fragment_file = fragment_files.begin();
		vertex_file != vertex_files.end() && fragment_file != fragment_files.end(); vertex_file++, fragment_file++) {

		Shader* new_shader = new Shader(vertex_file->second.c_str(), fragment_file->second.c_str());
		shaders[vertex_file->first] = new_shader;
	}

	glDepthMask(GL_TRUE);
	glEnable(GL_DEPTH_TEST);
}

unsigned int Scene::InitFromData(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices)
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

	// Vertex colour
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec3)));

	// Vertex normal
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(2 * sizeof(glm::vec3)));

	// Vertex texel
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(glm::vec3)));

	glBindVertexArray(0);

	return VAO;
}

void Scene::SendToShader(Mesh* mesh, Shader* shader, glm::mat4 model_matrix, bool with_material)
{
	p_scene_camera->SetViewMatrix(glm::lookAt(p_scene_camera->GetCameraPosition(), p_scene_camera->GetCameraPosition() + p_scene_camera->GetCameraForward(), p_scene_camera->GetCameraUp()));

	shader->Use();

	glm::mat4 projection = p_scene_camera->GetProjection();
	glm::mat4 view = p_scene_camera->GetView();

	shader->SetMat4("projectionMatrix", projection);
	shader->SetMat4("viewMatrix", view);
	shader->SetMat4("modelMatrix", model_matrix);

	if (with_material) {
		if (mesh->GetMaterial() != nullptr) {
			glm::vec3 Ka = mesh->GetMaterial()->Ka;
			glm::vec3 Kd = mesh->GetMaterial()->Kd;
			glm::vec3 Ksp = mesh->GetMaterial()->Ksp;
			float Ksh = mesh->GetMaterial()->Ksh;

			shader->SetVec3("material.Ka", Ka);
			shader->SetVec3("material.Kd", Kd);
			shader->SetVec3("material.Ksp", Ksp);
			shader->SetFloat("material.Ksh", Ksh);
		}
		else {
			if (!mesh->GetError()) {
				RENDER_WARN("Mesh object {} has no material attached", mesh->GetMeshId());
				mesh->HasError(true);
			}
			return;
		}
	}
}
