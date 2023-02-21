#pragma once
#include "Mover.h"

class Train : public Mover
{
public:
	Train(int dx, Vector2 pos);
	Train(const Train&) = default;
	Train& operator=(const Train&) = default;
	~Train() = default;
};