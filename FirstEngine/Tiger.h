#pragma once

#include "Pawn.h"

class Camera;

class Tiger : public Pawn
{
public:
	Tiger();
	~Tiger();

protected:
	virtual void OnStartUp() override;
	virtual void OnShutDown() override;

	virtual void OnUpdate( float deltaTime ) override;

private:
	void UpdateRotation();
	void UpdateMovement();
	float GetRotationInput() const;
	D3DXVECTOR2 GetMovementInput() const;

	const float W_forward = (-1.5f);
	const float S_backward = 1.5f;
	const float A_left = 3.0f;
	const float D_right = 0.1f;
	

	Camera* m_camera;
};
