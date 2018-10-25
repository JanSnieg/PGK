#pragma once
#include "Object.h"
#include <vector>
#include <d3dx9math.h>

class Actor :
	public Object
{
public:
	Actor();
	~Actor();
protected:
	D3DXVECTOR3 m_ActorPosition;
	D3DXVECTOR3 m_ActorOrientation;
	D3DXVECTOR3 m_ActorScale;
	
};

