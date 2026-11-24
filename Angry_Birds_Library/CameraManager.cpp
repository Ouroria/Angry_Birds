#include "pch.h"
#include "CameraManager.h"

CameraManager::CameraManager()
	:m_camera_controller(nullptr)
{

}

void CameraManager::SetController(
	ICameraController& _controller)
{
	m_camera_controller = &_controller;
}


void CameraManager::Update(float _delta_time)
{
	if (m_camera_controller != nullptr)
	{
		m_camera_controller->Update(_delta_time);
	}
}

Camera3D CameraManager::GetCamera() const
{
	return m_camera_controller->GetCamera();
}