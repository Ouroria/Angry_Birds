
#include "pch.h"
#include "OrbitCamera.h"

OrbitCamera::OrbitCamera(
    Vector3 _target,
    float _distance,
    float _rotation_speed)
    : m_target(_target),
    m_distance(_distance),
    m_yaw(0.0f),
    m_pitch(0.0f),
    m_min_pitch(10.0f),
    m_max_pitch(80.0f),
    m_min_distance(4.0f),
    m_max_distance(25.0f),
    m_mouse_sensitivity(0.25f),
    m_rotation_speed(_rotation_speed)
{
}
