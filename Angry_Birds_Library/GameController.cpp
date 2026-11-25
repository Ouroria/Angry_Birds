#include "pch.h"
#include "GameController.h"

Game_Controller::Game_Controller()
    : m_orbit_camera(
        Vector3{ 0.0f, 0.0f, 0.0f },
        12.0f,
        90.0f)
{
    m_camera_manager.SetController(m_orbit_camera);
}

void Game_Controller::processInput()
{
    InputController::InputSnapshot snapshot =
        m_input_controller.Capture();

    m_camera_manager.Update(GetFrameTime(), snapshot);
}

void Game_Controller::fixedTick(cyclone::real _dt)
{
}

void Game_Controller::restart()
{
}

Camera3D Game_Controller::GetCamera() const
{
    return m_camera_manager.GetCamera();
}