#ifndef ANGRY_BIRD_CAMERA_ORBITCAMERA_H
#define ANGRY_BIRD_CAMERA_ORBITCAMERA_H

#include "ICameraController.h"

class OrbitCamera : public ICameraController
{
public:
    OrbitCamera(
        Vector3 _target,
        float _distance,
        float _rotation_speed);

    void Update(
        float _delta_time,
        const InputController::InputSnapshot& _snapshot) override;
    Camera3D GetCamera() const override;
    void UpdateZoom(float _wheel);

private:
    Vector3 m_target;
    float m_distance;
    float m_yaw;
    float m_pitch;
    Camera3D m_camera;

    float m_min_pitch;
    float m_max_pitch;

    float m_min_distance;
    float m_max_distance;

    float m_mouse_sensitivity;
    float m_rotation_speed;

    void UpdateCameraPosition();
};

#endif