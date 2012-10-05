#include <sstream>
#include "Hud.h"

using namespace phoenix;
using namespace bea;
using namespace labyrinth;


Hud::Hud()
	: bea::GameObject(1001)
{
}


Hud::~Hud()
{
}


void Hud::draw( const double dtime ){
	RenderSystem& r = getRenderSystem();
	std::ostringstream stream;

	int health = Application::globals.get<int>("health");
	int keys = Application::globals.get<int>("keys");

	stream<<"Health: "<<health<<"\n"<<"Keys: "<<keys;

	auto g = r.drawText( stream.str(), Vector2d( 16,16 ) );
	g->setDepth( -10.0f );
	g->update();
}