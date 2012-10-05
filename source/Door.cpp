#include "Door.h"

using namespace phoenix;
using namespace bea;
using namespace labyrinth;

Door::Door( phoenix::Vector2d _pos )
	: bea::GameObject(203)
{
	phoenix::Polygon poly(phoenix::Rectangle( Vector2d(0,0), Vector2d(32,32) ));
	makeCollisionObject(poly);

	makeSprite();
	sprite->setTexture( getRenderSystem().findTexture("tiles-colors.png") );
	sprite->setFrameSize( Vector2d(32,32) );
	sprite->setFrame( 19 );
	sprite->update();

	setPosition( _pos + Vector2d(16,16) );
}

Door::~Door()
{
}

/* Draw Update */
void Door::draw( const double dtime ){
}

/* Collision Handler */
void Door::onCollision( bea::CollisionResult r ){
	if( r.b->getType() == 101 && r.separation.getMagnitudeSquared() > 16.0f ){ // Hero
		int keys = Application::globals.get<int>("keys");
		if( keys > 0 ){
			Application::globals.set("keys", keys-1);
			drop();
		}
	} 
}