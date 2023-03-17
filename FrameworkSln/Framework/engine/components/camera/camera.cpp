#include "camera.h"

Camera::Camera()
{
	position = glm::vec3(0.0f, 2.0f, 15.0f);
	forward = glm::vec3(0.0f, 0.0f, -1.0f);
	right = glm::vec3(1.0f, 0.0f, 0.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);

	yaw = YAW;
	pitch = PITCH;
	
	movementSpeed = SPEED;
	mouseSensitivity = SENSITIVITY;
	zoom = ZOOM;

	globalUp = glm::vec3(0.0f, 1.0f, 0.0f);

	projectionMatrix = glm::mat4(0);
	viewMatrix = glm::mat4(0);
}

Camera::~Camera()
{
}

void Camera::MoveForward(double deltaTime)
{
	position += glm::normalize(forward) * (float)deltaTime * movementSpeed;
}

void Camera::MoveBackwards(double deltaTime)
{
	position -= glm::normalize(forward) * (float)deltaTime * movementSpeed;
}

void Camera::MoveLeft(double deltaTime)
{
	position -= glm::normalize(right) * (float)deltaTime * movementSpeed;
}

void Camera::MoveRight(double deltaTime)
{
	position += glm::normalize(right) * (float)deltaTime * movementSpeed;
}

void Camera::MoveUp(double deltaTime)
{
	position += glm::normalize(globalUp) * (float)deltaTime * movementSpeed;
}

void Camera::MoveDown(double deltaTime)
{
	position -= glm::normalize(globalUp) * (float)deltaTime * movementSpeed;
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
