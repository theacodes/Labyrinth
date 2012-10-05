#pragma once

#include "Bea.h"

namespace labyrinth{

class Hero :
	public bea::GameObject
{
public:

	Hero();
	virtual ~Hero();

	virtual void onEvent( const bea::Event& e );

	virtual void update( const double dtime = 0.0 );

	virtual void draw( const double dtime = 0.0 );

	virtual void onCollision( bea::CollisionResult r );

protected:

	unsigned int key_keeper;
	unsigned int direction;
	phoenix::Vector2d velocity;
};

} //namespace
