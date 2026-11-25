#ifndef ANGRY_BIRDS_GAME_CONTROLLER_H
#define ANGRY_BIRDS_GAME_CONTROLLER_H

#include "CameraManager.h"
#include "InputController.h"
#include "OrbitCamera.h"
#include "cyclone.h"

class Game_Controller
{
public:
    Game_Controller();

    void processInput();
    void fixedTick(cyclone::real _dt);
    void restart();
    Camera3D GetCamera() const;

private:
    InputController m_input_controller;
    OrbitCamera m_orbit_camera;
    CameraManager m_camera_manager;
};

#endif