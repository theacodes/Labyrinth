#pragma once
#include "Bea.h"

namespace labyrinth{

class Hud :
	public bea::GameObject
{
public:
	Hud(void);
	virtual ~Hud(void);

	virtual void draw( const double dtime = 0.0 );
};

} //namespace;