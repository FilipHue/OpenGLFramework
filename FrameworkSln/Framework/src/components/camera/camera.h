#pragma once

#include "glm.hpp"
#include <gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera();

	void MoveForward(double delta_time);
	void MoveBackwards(double delta_time);
	void MoveLeft(double delta_time);
	void MoveRight(double delta_time);
	void MoveUp(double delta_time);
	void MoveDown(double delta_time);

	void RotateOX(double angle);
	void RotateOY(double angle);
	void RotateOZ(double angle);

	void SetPerspective(float fov, float aspect, float zNear, float zFar);
	void SetOrtho(float left, float right, float bottom, float up);
	void SetOrtho(float left, float right, float bottom, float up, float zNear, float zFar);

	void SetProjectionMatrix(glm::mat4 projection_matrix);
	void SetViewMatrix(glm::mat4 view_matrix);

	void SetPosition(glm::vec3 position);
	void SetMovementSpeed(float movement_speed);
	void SetMouseSensitivity(float mouse_sensitivity);
	void SetZoom(float zoom);

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

	float movement_speed;
	float mouse_sensitivity;
	float zoom;

	glm::vec3 globalUp;

	glm::mat4 projection_matrix;
	glm::mat4 view_matrix;

private:
	const float YAW = -90.0f;
	const float PITCH = 0.0f;
	const float SPEED = 2.5f;
	const float SENSITIVITY = 0.001f;
	const float ZOOM = 60.0f;
};
