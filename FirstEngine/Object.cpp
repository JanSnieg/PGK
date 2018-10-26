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
	if (&m_level == nullptr)
		return false;

	this->m_level = &m_level;

	return true;
}

void Object::ShutDown()
{
	m_level->ShutDown();
}

void Object::Destroy()
{
	ShutDown();
	Object::~Object();
}


//void Object::OnStartUp()
//{
//}
//
//void Object::OnShutDown()
//{
//}

void Object::Update()
{
}

void Object::Render()
{
}
