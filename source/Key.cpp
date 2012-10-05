#include "Key.h"

using namespace phoenix;
using namespace bea;
using namespace labyrinth;

labyrinth::Key::Key( phoenix::Vector2d _pos )
	: bea::GameObject(301)
{
	phoenix::Polygon poly(phoenix::Rectangle( Vector2d(0,0), Vector2d(32,32) ));
	makeCollisionObject(poly);

	makeSprite();
	sprite->setTexture( getRenderSystem().findTexture("tiles-colors.png") );
	sprite->setFrameSize( Vector2d(32,32) );
	sprite->setFrame( 18 );
	sprite->update();

	setPosition( _pos + Vector2d(16,16) );
}

labyrinth::Key::~Key()
{
}

/* Draw Update */
void labyrinth::Key::draw( const double dtime ){
}

/* Collision Handler */
void labyrinth::Key::onCollision( bea::CollisionResult r ){
	if( r.b->getType() == 101 && r.separation.getMagnitudeSquared() > 64.0f ){ // Hero
		Application::globals.set("keys", Application::globals.get<int>("keys")+1);
		drop();
	} 
}