#include "Actor.h"



void Actor::OnStartUp()
{
	Actor();
}

void Actor::OnShutDown()
{
	Actor::~Actor();
}

//void Actor::Update()
//{
//	this->Update();
//}
//
//void Actor::Render()
//{
//	this->Render();
}

Actor::Actor()
{
}


Actor::~Actor()
{
}
