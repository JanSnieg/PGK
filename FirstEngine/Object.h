#pragma once
#include "Level.h"

class Object
{
public:
	Object();
	~Object();
	Level* GetLevel();
	bool StartUp(Level & m_level);
	void ShutDown();
	void Destroy();

	virtual void OnStartUp();
	virtual void OnShutDown();

private:
	Level* m_level;

	virtual void Update();
	virtual void Render();
};

