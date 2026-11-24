#ifndef ANGRY_BIRD_CAMERA_ICAMERACONTROLLER_H
#define ANGRY_BIRD_CAMERA_ICAMERACONTROLLER_H

#include "raylib.h"


class ICameraController
{
public:
	virtual ~ICameraController();

	virtual void Update(float _delta_time);
	virtual Camera3D GetCamera() const;
};

#endif