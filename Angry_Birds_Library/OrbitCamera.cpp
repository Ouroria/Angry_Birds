#include "pch.h"
#include "OrbitCamera.h"
#include <cmath>
#include "raymath.h"

OrbitCamera::OrbitCamera(
    Vector3 _target,
    float _distance,
    float _rotation_speed)
    : m_target(_target),
    m_distance(_distance),
    m_yaw(0.0f),
    m_pitch(0.0f),
    m_camera{},
    m_min_pitch(10.0f),
    m_max_pitch(80.0f),
    m_min_distance(4.0f),
    m_max_distance(25.0f),
    m_mouse_sensitivity(0.25f),
    m_rotation_speed(_rotation_speed)
{
    m_camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
    m_camera.fovy = 45.0f;
    m_camera.projection = CAMERA_PERSPECTIVE;

    UpdateCameraPosition();
}


void OrbitCamera::UpdateCameraPosition()
{
    float yaw_radians = m_yaw * (PI / 180.0f);
    float pitch_radians = m_pitch * (PI / 180.0f);

    m_camera.position.x = m_target.x +
        m_distance * cosf(pitch_radians) *
        sinf(yaw_radians);

    m_camera.position.z = m_target.z +
        m_distance * cosf(pitch_radians) *
        cosf(yaw_radians);

    m_camera.position.y = m_target.y +
        m_distance * sinf(pitch_radians);

    m_camera.target = m_target;
}


Camera3D OrbitCamera::GetCamera() const
{
    return m_camera;
}

void OrbitCamera::Update(
    float _delta_time,
    const InputController::InputSnapshot& _snapshot)
{
    if (_snapshot.right_mouse_button_down)
    {
        m_yaw -= _snapshot.mouse_delta.x *
            m_mouse_sensitivity;

        m_pitch += _snapshot.mouse_delta.y *
            m_mouse_sensitivity;
    }

    UpdateZoom(_snapshot.mouse_wheel);

    UpdateCameraPosition();
}


void OrbitCamera::UpdateZoom(float _wheel)
{
    m_distance -= _wheel;

    if (m_distance < m_min_distance)
    {
        m_distance = m_min_distance;
    }

    if (m_distance > m_max_distance)
    {
        m_distance = m_max_distance;
    }
}