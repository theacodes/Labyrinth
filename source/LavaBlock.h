#pragma once
#include "Bea.h"

namespace labyrinth{

class LavaBlock :
	public bea::GameObject
{
public:
	LavaBlock( phoenix::Vector2d _pos = phoenix::Vector2d(0.0f,0.0f) );
	virtual ~LavaBlock();

	virtual void draw( const double dtime = 0.0 );
};

} //namespace;
