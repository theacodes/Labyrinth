#pragma once
#include "Bea.h"

namespace labyrinth{

class Key :
	public bea::GameObject
{
public:
	Key( phoenix::Vector2d _pos = phoenix::Vector2d() );
	virtual ~Key();

	virtual void draw( const double dtime = 0.0 );
	virtual void onCollision( bea::CollisionResult r );
};

} //namespace;