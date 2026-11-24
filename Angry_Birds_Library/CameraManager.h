#ifndef ANGRY_BIRD_CAMERA_CameraManager_H
#define ANGRY_BIRD_CAMERA_CameraManager_H

#include "ICameraController.h"

class CameraManager
{
public :
	CameraManager();

	void SetController(ICameraController& controller);
	void Update(float _delta_time);
	Camera3D GetCamera() const;

private:
	ICameraController* m_camera_controller;

};

#endif