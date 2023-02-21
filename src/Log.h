#pragma once
#include "Mover.h"

class Log : public Mover
{
public:
	Log(int dx, Vector2 pos);
	Log(const Log&) = default;
	Log& operator=(const Log&) = default;
	~Log() = default;
};