#include "LabyrinthApplication.h"

#include "Hero.h"
#include "LavaBlock.h"
#include "MoveableBlock.h"
#include "Key.h"
#include "Door.h"
#include "Hud.h"

using namespace phoenix;
using namespace bea;
using namespace labyrinth;

/*
	Initialization Routine
*/
void LabyrinthApplication::onInit(){

	srand( (unsigned int) time(0) );

	system.setResizeBehavior( phoenix::RZB_EXPAND );
	phoenix::WindowManager::Instance()->setWindowSize(phoenix::Vector2d(800,600));
	getCollisionManager().setFilter( boost::bind( &LabyrinthApplication::collisionFilter, this, _1, _2 ) );
	getCollisionManager().setIterations(4);

	new bea::DebugObject();

	// Global Variables
	globals.set("health", 3);
	globals.set("keys", 0);

	// Background
	phoenix::BatchGeometryPtr bg = new phoenix::BatchGeometry( system.getBatchRenderer(), phoenix::Rectangle(0,0,1024,1024) );
	bg->setDepth( -100.0f );
	bg->colorize( phoenix::Color( 189, 32, 32 ) );
	bg->update();

	// Level
	bea::MapLoader::load("default.tmx", boost::bind( &LabyrinthApplication::onTileAdded, this, _1 ), boost::bind( &LabyrinthApplication::onObjectAdded, this, _1 ) );

	// Hud
	new Hud();

	// Hero
	new Hero();

	system.getDebugConsole()<<"\n"<<"Collision Objects: "<< getCollisionManager().count();
}

/*
	Game Update Event Handler
*/
void LabyrinthApplication::onGameUpdate(){
};

/* 
	Main Event Handler
*/
void LabyrinthApplication::onEvent( const bea::Event& e ){
	Application::onEvent(e);
}

/*
	Collision filter
*/
bool LabyrinthApplication::collisionFilter( CollisionObjectPtr a, CollisionObjectPtr b ){
	if( a->getType() == 201 && b->getType() == 201 ) return false; //solid against solid
	if( a->getType() == 201 && b->getType() == 301 ) return false; //solid against key
	if( a->getType() == 201 && b->getType() == 203 ) return false; //solid against door
	return true;
}


/*
	Level loading helping
*/
void LabyrinthApplication::onTileAdded( const bea::PropertyContainer& data ){
	int x = data.get<int>("x");
	int y = data.get<int>("y");
	int w = data.get<int>("tile_width");
	int h = data.get<int>("tile_height");

	if( data.contains("solid") && data.get<std::string>("solid") == "true" ){
		new bea::CollisionObject( collisions, phoenix::Polygon(phoenix::Rectangle( x*w,y*h,w,h )), 201 );
	}
	if( data.contains("lava") && data.get<std::string>("lava") == "true" ){
		new LavaBlock( Vector2d(x*w,y*h) );
	}
}

void LabyrinthApplication::onObjectAdded( const bea::PropertyContainer& data ){
	int x = data.get<int>("x");
	int y = data.get<int>("y");
	int w = data.get<int>("width");
	int h = data.get<int>("height"); 
	std::string type = data.get<std::string>("type");

	if( type == "Moveable Block"){
		new MoveableBlock( Vector2d(x,y) );
	}
	if( type == "Key" ){
		new labyrinth::Key( Vector2d(x,y) );
	}
	if( type == "Door" ){
		new Door( Vector2d(x,y) );
	}
}
