#pragma once
#include "Pawn.h"
class Character :
	public Pawn
{
public:
	Character();
	~Character();

	virtual void Update();

protected:

	D3DXVECTOR3 m_Velocity;

};

