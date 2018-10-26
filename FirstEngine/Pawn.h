#pragma once
#include "Actor.h"
#include "Mesh.h"
#include "Texture.h"
#include "Renderer.h"
#include <memory>

class Pawn :
	public Actor
{
	void OnStartUp();
	void OnShutDown();
	void Render();

public:
	Pawn();
	~Pawn();

protected:
	Mesh m_PawnMesh;
	Texture m_PawnTexture;

	std::unique_ptr<Renderer> m_Renderer;

	D3DXVECTOR3 m_PawnPosition;
	D3DXVECTOR3 m_PawnOrientation;
	D3DXVECTOR3 m_PawnScale;
};

