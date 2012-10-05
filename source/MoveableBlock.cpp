#include "MoveableBlock.h"

using namespace phoenix;
using namespace bea;
using namespace labyrinth;


MoveableBlock::MoveableBlock( phoenix::Vector2d _pos )
	: bea::GameObject(202)
{
	// Make the collision object
	phoenix::Polygon poly(phoenix::Rectangle( Vector2d(0,0), Vector2d(32,32) ));
	makeCollisionObject(poly);
	setPosition( _pos + Vector2d(16,16) );
}


MoveableBlock::~MoveableBlock(void)
{
}

/* Draw Update */
void MoveableBlock::draw( const double dtime ){
	getRenderSystem().drawPolygon( collision->getPolygon() );
}

/* Collision Handler */
void MoveableBlock::onCollision( bea::CollisionResult r ){
	if( r.b->getType() == 101 ){ // Hero
		setPosition( position  + r.separation * 0.5f );
	} 
	else { // Solids & Self
		setPosition( position  + r.separation );
	}
}