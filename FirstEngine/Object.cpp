#include "Object.h"



Object::Object()
{
}


Object::~Object()
{
}

Level* Object::GetLevel()
{
	return m_level;
}

bool Object::StartUp(Level &m_level)
{
	this->m_level = &m_level;
}

void Object::ShutDown()
{
	this->m_level->ShutDown;
}

void Object::OnStartUp()
{
}

void Object::OnShutDown()
{
}

void Object::Update()
{
}

void Object::Render()
{
}
