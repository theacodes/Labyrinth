#pragma once
#include "Bea.h"

namespace labyrinth{

class Door :
	public bea::GameObject
{
public:
	Door(phoenix::Vector2d _pos = phoenix::Vector2d());
	virtual ~Door();

	virtual void draw( const double dtime = 0.0 );
	virtual void onCollision( bea::CollisionResult r );
};

} //namespace;