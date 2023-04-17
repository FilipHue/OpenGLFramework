#pragma once

#include <unordered_map>

#include "../lights/light.h"

#include "../../world.h"

#include "scene_input.h"

#include "../camera/camera.h"
#include "../camera/camera_input.h"
#include "../mesh/mesh.h"
#include "../../managers/texture/texture_manager.h"
#include "../../managers/shape/shape_manager.h"
#include "../../managers/shader/shader.h"

#include "../../managers/file/file_manager.h"

class Scene : public World
{
	friend class SceneInput;
	friend class ShapeManager;

public:
	Camera* p_scene_camera;
	CameraInput* p_camera_input;
	SceneInput* p_scene_input;
	TextureManger* p_texture_manager;
	ShapeManager* p_shape_manager;

protected:
	Scene();

	void CreateMesh(const char* name, std::vector<Vertex>& vertices, std::vector<unsigned int>& indices, Material* material);

	void RenderMesh(Mesh* mesh, Shader* shader, glm::vec3 position, const char* texture_name = NULL, Light* light_props = NULL);
	void RenderMesh(Mesh* mesh, Shader* shader, glm::mat4 model_matrix, const char* texture_name = NULL, Light* light_props = NULL);

protected:
	Window* p_window;
	std::unordered_map<std::string, Mesh*> meshes;
	std::unordered_map<std::string, Shader*> shaders;

private:
	void Init();
	/**
	 * @brief				Method for creating the VAO, VBO and IBO of the mesh object
	 * @param vertices		The verticies of the mesh used for initializing the VBO
	 * @param indices		The indicies of the mesh used for initializing the IBO
	 * @return				Returns the VAO of the object
	*/
	unsigned int InitFromData(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices);
	/**
	 * @brief				Method for sending the projection, view and model matricies to the shader program. 
	 * @brief				Can send material properties if needed
	 * @param mesh			The mesh from which we take the material properties
	 * @param shader		The shader used
	 * @param modelMatrix	The model matrix of the mesh object
	 * @param with_material State variable that tells if the object comes with or without a material
	*/
	void SendToShader(Mesh* mesh, Shader* shader, glm::mat4 modelMatrix, bool with_material = 0);
};
