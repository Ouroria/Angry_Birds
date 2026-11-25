#ifndef ANGRY_BIRD_CAMERA_ICAMERACONTROLLER_H
#define ANGRY_BIRD_CAMERA_ICAMERACONTROLLER_H

#include "raylib.h"
#include "InputController.h"

class ICameraController
{
public:
    virtual ~ICameraController();

    virtual void Update(
        float _delta_time,
        const InputController::InputSnapshot& _snapshot) = 0;

    virtual Camera3D GetCamera() const = 0;
};

#endif