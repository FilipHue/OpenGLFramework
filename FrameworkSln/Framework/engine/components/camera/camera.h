#pragma once

#include <core.h>

class Camera
{
public:
	/**
	  * Constructor for the Camera class
	  * Sets the position, forward, right and up vectors
	  * Sets the yaw and pitch, camera speed and sensitivity, zoom and globalUp vector
	  */
	Camera();
	~Camera();

	/**
	  * Translates the camera forward
	  * @param deltaTime The time between the current frame and the last frame, used for frame independent movement
	  */
	void MoveForward(double deltaTime);
	/**
	  * Translates the camera backwards
	  * @param deltaTime The time between the current frame and the last frame, used for frame independent movement
	  */
	void MoveBackwards(double deltaTime);
	/**
	  * Translates the camera left
	  * @param deltaTime The time between the current frame and the last frame, used for frame independent movement
	  */
	void MoveLeft(double deltaTime);
	/**
	  * Translates the camera right
	  * @param deltaTime The time between the current frame and the last frame, used for frame independent movement
	  */
	void MoveRight(double deltaTime);
	/**
	  * Translates the camera up
	  * @param deltaTime The time between the current frame and the last frame, used for frame independent movement
	  */
	void MoveUp(double deltaTime);
	/**
	  * Translates the camera down
	  * @param deltaTime The time between the current frame and the last frame, used for frame independent movement
	  */
	void MoveDown(double deltaTime);

	/**
	  * Rotates the camera around the OX axis
	  * @param angle The angle of the rotation (this is very small since the movement with the mouse is very fast,
												usually it is equal to the mouse sensitivity * deltaTime)
	  */
	void RotateOX(double angle);
	/**
	  * Rotates the camera around the OY axis
	  * @param angle The angle of the rotation (this is very small since the movement with the mouse is very fast,
												usually it is equal to the mouse sensitivity * deltaTime)
	  */
	void RotateOY(double angle);
	/**
	  * Rotates the camera around the OZ axis
	  * @param angle The angle of the rotation (this is very small since the movement with the mouse is very fast,
												usually it is equal to the mouse sensitivity * deltaTime)
	  */
	void RotateOZ(double angle);

	/**
	  * Sets the camera perspectives 
	  */

	void SetPerspective(float fov, float aspect, float zNear, float zFar);
	void SetOrtho(float left, float right, float bottom, float up);
	void SetOrtho(float left, float right, float bottom, float up, float zNear, float zFar);

	/**
	  * Sets camera attributes 
	  */

	void SetProjectionMatrix(glm::mat4 projectionMatrix);
	void SetViewMatrix(glm::mat4 viewMatrix);

	void SetPosition(glm::vec3 position);
	void SetMovementSpeed(float movementSpeed);
	void SetMouseSensitivity(float mouseSensitivity);
	void SetZoom(float zoom);

	/**
	  * Gets camera attributes 
	  */

	glm::mat4 GetProjection();
	glm::mat4 GetView();

	glm::vec3 GetCameraPosition();
	glm::vec3 GetCameraForward();
	glm::vec3 GetCameraRight();
	glm::vec3 GetCameraUp();
	float GetCameraSpeed();
	float GetCameraSensitivity();
	float GetCameraZoom();

private:
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 right;
	glm::vec3 up;

	float yaw;
	float pitch;

	float movementSpeed;
	float mouseSensitivity;
	float zoom;

	glm::vec3 globalUp;
	
	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix;

private:
	const float YAW = -90.0f;
	const float PITCH = 0.0f;
	const float SPEED = 2.5f;
	const float SENSITIVITY = 0.001f;
	const float ZOOM = 60.0f;
};

