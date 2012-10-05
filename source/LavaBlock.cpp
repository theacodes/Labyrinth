#include "LavaBlock.h"

using namespace phoenix;
using namespace bea;
using namespace labyrinth;


LavaBlock::LavaBlock( phoenix::Vector2d _pos )
	: bea::GameObject(801)
{
	// Make the collision object
	phoenix::Polygon poly(phoenix::Rectangle( Vector2d(0,0), Vector2d(32,32) ));
	makeCollisionObject(poly);
	setPosition( _pos + Vector2d(16,16) );
}


LavaBlock::~LavaBlock(void)
{
}

/* Draw Update */
void LavaBlock::draw( const double dtime ){
}