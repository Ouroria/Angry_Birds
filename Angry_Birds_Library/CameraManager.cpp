#include "pch.h"
#include <cassert>
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


void CameraManager::Update(
    float _delta_time,
    const InputController::InputSnapshot& _snapshot)
{
    if (m_camera_controller != nullptr)
    {
        m_camera_controller->Update(_delta_time, _snapshot);
    }
}

Camera3D CameraManager::GetCamera() const
{
    assert(m_camera_controller != nullptr);
    return m_camera_controller->GetCamera();
}