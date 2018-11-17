#include "Camera.h"
#include "Actor.h"
#include "CameraManager.h"
#include "Game.h"
#include "InputManager.h"
#include "Level.h"
#include "Math.h"

Camera::Camera()
	: m_target( nullptr )
	, m_distance( 5.0f )
{
}

Camera::~Camera() = default;

D3DXVECTOR3 Camera::GetTargetPosition() const
{
	if (m_target)
	{
		return m_target->GetActorPosition();
	}
	else
	{
		return D3DXVECTOR3( 0.0f, 0.0f, 0.0f );
	}
}

void Camera::OnUpdate( float deltaTime )
{
	UpdateCamera( deltaTime );

	Object::OnUpdate( deltaTime );
}

void Camera::UpdateCamera( float deltaTime )
{
	float distanceInput = GetCameraInput();
	D3DXVECTOR2 moveInput = GetCameraMove();

	static const float distanceChangeSpeed = 5.0f;
	static const float distanceMin = 1.0f;
	static const float distanceMax = 10.0f;

	m_distance += distanceInput * distanceChangeSpeed * deltaTime;
	m_distance = Math::Clamp( m_distance, distanceMin, distanceMax );

	CameraManager* cameraManger = GetLevel()->GetCameraManager();

	D3DXVECTOR3 direction = cameraManger->GetDirection();
	D3DXVECTOR3 position = GetTargetPosition() - direction * m_distance;
	position.y += 0.75f;
	//position.x += moveInput.x;
	//position.z += moveInput.y;
	cameraManger->SetPositionDirection( position, direction );
}

float Camera::GetCameraInput() const
{
	const InputManager* inputs = GetLevel()->GetGame()->GetInputManager();

	float camerInput = 0.0f;
	if( inputs->IsKeyPressed( VK_UP ) )
	{
		camerInput -= 1.0f;
	}
	if( inputs->IsKeyPressed( VK_DOWN ) )
	{
		camerInput += 1.0f;
	}
	camerInput += inputs->GetMouseWheel();
	return camerInput;
}

D3DXVECTOR2 Camera::GetCameraMove()
{
	const InputManager* inputs = GetLevel()->GetGame()->GetInputManager();
	D3DXVECTOR2 mouseMove = D3DXVECTOR2(0.0f,0.0f);
	if((GetKeyState(VK_RBUTTON) & 0x100) != 0 )
	{
		mouseMove.x = inputs->GetMouseMoveX();
		mouseMove.y = inputs->GetMouseMoveY();
	}
	return D3DXVECTOR2();
}
