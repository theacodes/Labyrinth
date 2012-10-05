#pragma once
#include "Bea.h"

namespace labyrinth{

class MoveableBlock :
	public bea::GameObject
{
public:
	MoveableBlock( phoenix::Vector2d _pos = phoenix::Vector2d(0.0f,0.0f) );
	virtual ~MoveableBlock();

	virtual void draw( const double dtime = 0.0 );
	virtual void onCollision( bea::CollisionResult r );
};

} //namespace;
