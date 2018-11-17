#pragma once

#include "Object.h"
#include <d3dx9math.h>
//#include <iostream>

class Actor;
struct D3DXVECTOR3;

class Camera : public Object
{
public:
	Camera();
	~Camera();

	const Actor* GetTarget() const { return m_target; }

	void SetTarget( const Actor* target ) { m_target = target; }

	D3DXVECTOR3 GetTargetPosition() const;

protected:
	virtual void OnUpdate( float deltaTime ) override;

private:
	void UpdateCamera( float deltaTime );
	float GetCameraInput() const;
	D3DXVECTOR2 GetCameraMove();

	const Actor* m_target;
	float m_distance;
};