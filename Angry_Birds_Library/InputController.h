#ifndef ANGRY_BIRD_INPUT_INPUTCONTROLLER_H
#define ANGRY_BIRD_INPUT_INPUTCONTROLLER_H

#include "raylib.h"

class InputController
{
public:
    struct InputSnapshot
    {
        bool right_mouse_button_down;
        Vector2 mouse_delta;
        float mouse_wheel;
        float horizontal_axis;
    };

    InputSnapshot Capture();
};

#endif