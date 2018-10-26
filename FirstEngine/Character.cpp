#include "Character.h"



void Character::OnStarUp()
{
	Character();
}

void Character::OnShutDown()
{
	Character::~Character();
}

Character::Character()
{
}


Character::~Character()
{
}

void Character::Update()
{
	this->Update();
	//D3DXVECTOR3 newPosition = m_ActorPosition * m_ActorOrientation * m_Velocity;
}
