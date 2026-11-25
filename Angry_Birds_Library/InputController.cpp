#include "pch.h"
#include "InputController.h"

InputController::InputSnapshot InputController::Capture()
{
    InputSnapshot snapshot{};

    snapshot.right_mouse_button_down =
        IsMouseButtonDown(MOUSE_BUTTON_RIGHT);

    snapshot.mouse_delta = GetMouseDelta();

    snapshot.mouse_wheel = GetMouseWheelMove();

    snapshot.horizontal_axis =
        static_cast<float>(IsKeyDown(KEY_D)) -
        static_cast<float>(IsKeyDown(KEY_A));

    return snapshot;
}