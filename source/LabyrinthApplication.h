#pragma once

#include "Bea.h"

namespace labyrinth{

class LabyrinthApplication :
	public bea::Application
{

public:

	virtual void onEvent( const bea::Event& e );
	virtual void onInit();
	virtual void onGameUpdate();
	void onTileAdded( const bea::PropertyContainer& data );
	void onObjectAdded( const bea::PropertyContainer& data );

	bool collisionFilter( bea::CollisionObjectPtr a, bea::CollisionObjectPtr b );
};

}// namespace