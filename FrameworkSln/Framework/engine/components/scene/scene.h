#pragma once

#include <core.h>

#include <map>
#include <set>

#include "../../world.h"
#include "../mesh/mesh.h"
#include "../camera/camera.h"
#include "../camera/camera_input.h"
#include "../../shaders/shader.h"
#include "../texture/texture_manger.h"
#include "scene_input.h"

#include <vertex_utils.h>
#include <material.h>

class Scene : public World
{
	friend class SceneInput;

public:
	/**
	  * Constructor for the Scene class
	  * Here method InitScene is called in order to initialize the scene
	  */
	Scene();
	~Scene();

	/**
	  * Creates a rectangle on the XOZ plane
	  * @param name The name of the rectangle object
	  * @param width The width of the rectangle
	  * @param height The height of the ractangle
	  */
	void CreateRectangleZ(const char* name, int width, int height);
	/**
	  * Creates a rectangle on the XOY plane
	  * @param name The name of the rectangle object
	  * @param width The width of the rectangle
	  * @param height The height of the ractangle
	  */
	void CreateRectangleY(const char* name, int width, int height);

public:
	Camera* sceneCamera;
	CameraInput* cameraInput;
	SceneInput* sceneInput;
	TextureManger* textureManager;

protected:
	/**
	  * Method is used to create a mesh object
	  * @param name The name/id of the mesh object
	  * @param vertices The vertices of the mesh object
	  * @param indices The indices of the mesh object
	  */
	void CreateMesh(const char* name, std::vector<VertexFormat> &vertices, std::vector<unsigned int> &indices);
	/**
	  * Renders the mesh object on the screen using its position
	  * @param mesh The mesh object which is going to be rendered
	  * @param shader The shader used to render the mesh object
	  * @param position The position of the mesh object
	  */
	void RenderMesh(Mesh* mesh, Shader* shader, glm::vec3 position);
	/**
	  * Renders the mesh object on the screen using its position and a given texture
	  * @param mesh The mesh object which is going to be rendered
	  * @param shader The shader used to render the mesh object
	  * @param position The position of the mesh object
	  * @param textureName The texture of the object
	  */
	void RenderMesh(Mesh* mesh, Shader* shader, glm::vec3 position, const char* textureName);
	/**
	  * Renders the mesh object on the screen using its model matrix
	  * @param mesh The mesh object which is going to be rendered
	  * @param shader The shader used to render the mesh object
	  * @param modelMatrix The model matrix of the mesh object
	  */
	void RenderMesh(Mesh* mesh, Shader* shader, glm::mat4 modelMatrix);
	/**
	  * Renders the mesh object on the screen using its model matrix and a given texture
	  * @param mesh The mesh object which is going to be rendered
	  * @param shader The shader used to render the mesh object
	  * @param modelMatrix The model matrix of the mesh object
	  * @param textureName The texture of the object
	  */
	void RenderMesh(Mesh* mesh, Shader* shader, glm::mat4 modelMatrix, const char* textureName);

protected:
	std::map<std::string, Mesh*> meshes;
	std::set<Material> materials;
	std::map<std::string, Shader*> shaders;

private:
	/**
	  * Method is called once in the scene constructor
	  * Sets the camera and camera input controller
	  * Sets the scene input controller
	  * Loads the shaders used
	  */
	void InitScene();
	/**
	  * Initalizes the VAO, VBO, IBO from the vertices and indices given
	  * @param vertices The vertices of the object
	  * @param indices The indices of the object
	  * @return the VAO that the object is binded to
	  */
	unsigned int InitFromData(std::vector<VertexFormat>& vertices, std::vector<unsigned int>& indices);
	/**
	  * Sends to the shader used the projection, view and model matrix
	  * @param shader The shader program used
	  * @param modelMatrix The model matrix of the mesh object
	  */
	void SendToShader(Shader* shader, glm::mat4 modelMatrix);

private:
	std::vector<Mesh*> axes;
};
