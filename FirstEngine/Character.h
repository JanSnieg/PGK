#pragma once
#include "Pawn.h"
class Character :
	public Pawn
{
	void OnStarUp();
	void OnShutDown();
public:
	Character();
	~Character();

	void Update();

protected:

	D3DXVECTOR3 m_Velocity;

};

