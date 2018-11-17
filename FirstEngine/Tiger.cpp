#include "Tiger.h"
#include "Camera.h"
#include "Game.h"
#include "InputManager.h"
#include "Level.h"
#include "Math.h"
#include <cassert>

Tiger::Tiger()
	: m_camera( nullptr )
{
	// Setup mesh.
	SetMesh( "Content\\tiger.x" );
	SetTexture( "Content\\tiger.bmp" );
	SetMeshPosition( D3DXVECTOR3( 0.0f, 0.75f, 0.0f ) );
}

Tiger::~Tiger() = default;

void Tiger::OnStartUp()
{
	Pawn::OnStartUp();

	m_camera = GetLevel()->CreateObject< Camera >( [this]( auto camera ) {
		camera->SetTarget( this );
	} );
}

void Tiger::OnShutDown()
{
	assert( m_camera );
	m_camera->Destroy();
	m_camera = nullptr;

	Pawn::OnShutDown();
}

void Tiger::OnUpdate( float deltaTime )
{
	UpdateMovement();
	Sleep( 100 );
	UpdateRotation();

	Pawn::OnUpdate( deltaTime );
}

void Tiger::UpdateRotation()
{
	float rotationInput = GetRotationInput();
	if( rotationInput )
	{
		D3DXVECTOR3 rotation = GetActorRotation();
		rotation.y = rotationInput;
		SetActorRotation( rotation );
	}
	else
		return;
	
}

void Tiger::UpdateMovement()
{
	D3DXVECTOR2 movementInput = GetMovementInput();
	if( movementInput )
	{
		D3DXVECTOR3 movement = GetActorPosition();
		movement.x += movementInput.x;
		movement.z += movementInput.y;
		SetActorPosition( movement );
	}
	else
		return;
}

float Tiger::GetRotationInput() const
{
	const InputManager* inputs = GetLevel()->GetGame()->GetInputManager();

	float rotation = 0.0f;

	if( inputs->IsKeyPressed( 'A' ) )
	{
		rotation = A_left;
	}
	else if( inputs->IsKeyPressed( 'D' ) )
	{
		rotation = D_right;
	}
	else if( inputs->IsKeyPressed( 'W' ) )
	{
		rotation = W_forward;
	}
	else if( inputs->IsKeyPressed( 'S' ) )
	{
		rotation = S_backward;
	}
	return rotation;
}

D3DXVECTOR2 Tiger::GetMovementInput() const
{
	const InputManager* inputs = GetLevel()->GetGame()->GetInputManager();
	float step = 0.2f;
	D3DXVECTOR2 movement = D3DXVECTOR2(0.0f, 0.0f);
	float rotation = GetActorRotation().y;

	if( inputs->IsKeyPressed( 'A' ) && rotation == A_left)
	{
		movement.y = step;
	}
	else if( inputs->IsKeyPressed( 'D' ) && rotation == D_right )
	{
		movement.y = -step;
	}
	else if( inputs->IsKeyPressed( 'W' ) && rotation == W_forward )
	{
		movement.x = step;
	}
	else if( inputs->IsKeyPressed( 'S' ) && rotation == S_backward )
	{
		movement.x = -step;
	}
	return movement;
}
