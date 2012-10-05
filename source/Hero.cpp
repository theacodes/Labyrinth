#include "Hero.h"

using namespace phoenix;
using namespace bea;
using namespace labyrinth;


/* Creation */
Hero::Hero()
		: bea::GameObject(101), key_keeper(0), direction(0), velocity(Vector2d(0,0))
{
	listen("phoenix:key");
	// Make the sprite and such.
	/*
	makeSprite();
	sprite->setTexture( getRenderSystem().findTexture("fairy.png") );
	sprite->setFrameSize( phoenix::Vector2d(32,32) );
	sprite->setScale( phoenix::Vector2d( 1.5f, 1.5f ) );
	sprite->update();
	

	bea::SpriteAnimatorFrameRangePtr frame_animator( new bea::SpriteAnimatorFrameRange( sprite, 0, 3 ) );
	frame_animator->setSpeed( 5.0f/30.0f );
	*/

	// Make the collision object
	phoenix::Polygon poly;
	for( int i = 0; i < 8; i++ ){
		poly.addVertex( Vector2d( 15.0f, 0.0f ).rotate( (float(i)/8.0f) * (3.145967f*2.0f) ) );
	}
	makeCollisionObject(poly);
	setPosition( Vector2d(400,300) );
}


Hero::~Hero()
{
}

/* Main Update Function */
void Hero::update( const double dtime ){
	const float SPEED = 240.0f;

	switch( direction ){
	case 0:
		velocity = Vector2d(SPEED,0.0f);
		break;
	case 1:
		velocity = Vector2d(0.0f,-SPEED);
		break;
	case 2:
		velocity = Vector2d(-SPEED,0.0f);
		break;
	case 3:
		velocity = Vector2d(0.0f,SPEED);
		break;
	}

	if( key_keeper == 0 ){
		velocity = Vector2d(0,0);
	}

	setPosition( getPosition() + (velocity * dtime) );
}


/* Draw Update */
void Hero::draw( const double dtime ){
	getRenderSystem().drawPolygon( collision->getPolygon() );
}

/* Event Handler */
void Hero::onEvent( const bea::Event& e ){
	GameObject::onEvent(e);

	if( e.name == "phoenix:key" ){
		
		int key = e.properties.get<int>("key");
		bool state = e.properties.get<bool>("state");

		switch( key ){
		case PHK_UP:
			if( state ){
				key_keeper |= 0x02;
				direction = 1;
			} else {
				key_keeper &= ~0x02;
			}
			break;
		case PHK_DOWN:
			if( state ){
				key_keeper |= 0x08;
				direction = 3;
			} else {
				key_keeper &= ~0x08;
			}
			break;
		case PHK_LEFT:
			if( state ){
				key_keeper |= 0x04;
				direction = 2;
			} else {
				key_keeper &= ~0x04;
			}
			break;
		case PHK_RIGHT:
			if( state ){
				key_keeper |= 0x01;
				direction = 0;
			} else {
				key_keeper &= ~0x01;
			}
			break;
		}

	}
}

/* Collision Handler */
void Hero::onCollision( bea::CollisionResult r ){
	if( r.b->getType() == 201 || r.b->getType() == 203 ){ //solid block or door
		setPosition( position  + r.separation );
	}
	if( r.b->getType() == 202 ){ // Moveable block
		setPosition( position  + r.separation * 0.5f );
	}
	if( r.b->getType() == 801 ){ // Lava
		setPosition( Vector2d(400,300) );
	}
}