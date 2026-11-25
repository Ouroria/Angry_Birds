#ifndef ANGRY_BIRD_CAMERA_CAMERAMANAGER_H
#define ANGRY_BIRD_CAMERA_CAMERAMANAGER_H

#include "ICameraController.h"
#include "InputController.h"

class CameraManager
{
public:
    CameraManager();

    void SetController(ICameraController& _controller);

    void Update(
        float _delta_time,
        const InputController::InputSnapshot& _snapshot);

    Camera3D GetCamera() const;

private:
    ICameraController* m_camera_controller;
};

#endif