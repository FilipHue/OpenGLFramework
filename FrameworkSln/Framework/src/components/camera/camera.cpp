#include "camera.h"

Camera::Camera()
{
	position = glm::vec3(0.0f, 0.0f, 5.0f);
	forward = glm::vec3(0.0f, 0.0f, -1.0f);
	right = glm::vec3(1.0f, 0.0f, 0.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);

	yaw = YAW;
	pitch = PITCH;

	movement_speed = SPEED;
	mouse_sensitivity = SENSITIVITY;
	zoom = ZOOM;

	globalUp = glm::vec3(0.0f, 1.0f, 0.0f);

	projection_matrix = glm::mat4(0);
	view_matrix = glm::mat4(0);
}

void Camera::MoveForward(double delta_time)
{
	position += glm::normalize(forward) * (float)delta_time * movement_speed;
}

void Camera::MoveBackwards(double delta_time)
{
	position -= glm::normalize(forward) * (float)delta_time * movement_speed;
}

void Camera::MoveLeft(double delta_time)
{
	position -= glm::normalize(right) * (float)delta_time * movement_speed;
}

void Camera::MoveRight(double delta_time)
{
	position += glm::normalize(right) * (float)delta_time * movement_speed;
}

void Camera::MoveUp(double delta_time)
{
	position += glm::normalize(globalUp) * (float)delta_time * movement_speed;
}

void Camera::MoveDown(double delta_time)
{
	position -= glm::normalize(globalUp) * (float)delta_time * movement_speed;
}

void Camera::RotateOX(double angle)
{
	glm::vec4 aux = glm::rotate(glm::mat4(1.f), (float)angle, right) * glm::vec4(forward, 0);
	forward = glm::normalize(glm::vec3(aux));
	up = glm::cross(right, forward);
}

void Camera::RotateOY(double angle)
{
	glm::vec4 aux = glm::rotate(glm::mat4(1.f), (float)angle, glm::vec3(0, 1, 0)) * glm::vec4(forward, 0);
	forward = glm::normalize(glm::vec3(aux));

	aux = glm::rotate(glm::mat4(1.f), (float)angle, glm::vec3(0, 1, 0)) * glm::vec4(right, 0);
	right = glm::normalize(glm::vec3(aux));

	up = glm::cross(right, forward);
}

void Camera::RotateOZ(double angle)
{
	glm::vec4 aux = glm::rotate(glm::mat4(1.f), (float)angle, glm::vec3(0, 1, 0)) * glm::vec4(right, 1);
	right = glm::normalize(glm::vec3(aux));

	aux = glm::rotate(glm::mat4(1.f), (float)angle, forward) * glm::vec4(up, 0);
	forward = glm::normalize(glm::vec3(aux));

	up = glm::cross(right, forward);
}

void Camera::SetPerspective(float fov, float aspect, float zNear, float zFar)
{
	projection_matrix = glm::perspective(glm::radians(fov), aspect, zNear, zFar);
}

void Camera::SetOrtho(float left, float right, float bottom, float up)
{
	projection_matrix = glm::ortho(left, right, bottom, up);
}

void Camera::SetOrtho(float left, float right, float bottom, float up, float zNear, float zFar)
{
	projection_matrix = glm::ortho(left, right, bottom, up, zNear, zFar);

}

void Camera::SetProjectionMatrix(glm::mat4 projection_matrix)
{
	this->projection_matrix = projection_matrix;
}

void Camera::SetViewMatrix(glm::mat4 view_matrix)
{
	this->view_matrix = view_matrix;
}

void Camera::SetPosition(glm::vec3 position)
{
	this->position = position;
}

void Camera::SetMovementSpeed(float movement_speed)
{
	this->movement_speed = movement_speed;
}

void Camera::SetMouseSensitivity(float mouse_sensitivity)
{
	this->mouse_sensitivity = mouse_sensitivity;
}

void Camera::SetZoom(float zoom)
{
	this->zoom = zoom;
}

glm::mat4 Camera::GetProjection()
{
	return projection_matrix;
}

glm::mat4 Camera::GetView()
{
	return view_matrix;
}

glm::vec3 Camera::GetCameraPosition()
{
	return this->position;
}

glm::vec3 Camera::GetCameraForward()
{
	return forward;
}

glm::vec3 Camera::GetCameraRight()
{
	return right;
}

glm::vec3 Camera::GetCameraUp()
{
	return up;
}

float Camera::GetCameraSpeed()
{
	return this->movement_speed;
}

float Camera::GetCameraSensitivity()
{
	return mouse_sensitivity;
}

float Camera::GetCameraZoom()
{
	return this->zoom;
}
