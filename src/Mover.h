#pragma once
#include "SmartActor.h"

/*
* Mover is the base class for Car, Log and Train
* The thing they all have in common, besides inheriting from SmartActor, is that they need to store whether they're
* moving left or right and update their X position each frame
*/
class Mover : public SmartActor
{
public:
	Mover(int dx, Vector2 pos, Texture2D* image = nullptr);
	Mover(const Mover&) = default;
	Mover& operator=(const Mover&) = default;
	~Mover() = default;

	virtual void update();

protected:
	int m_Dx{ 0 };			// X direction of moving elements on this row, Zero by default - only ActiveRows and Rail have moving elements
};