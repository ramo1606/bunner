#pragma once
#include "SmartActor.h"
#include "Common.h"

using namespace Common;
/*
* Row is the base class for Pavement, Grass, Dirt, Railand ActiveRow
* Each row corresponds to one of the 40 pixel high images which make up sections of grass, road, etc.
* The last row of each section is 60 pixels high and overlaps with the row above
*/
class Row : public SmartActor 
{
public:
	Row(std::string baseImage, int index, float y);
	Row(const Row&) = default;
	Row& operator=(const Row&) = default;
	~Row() = default;

	virtual void next();
	SmartActor* collide(float x, int margin = 0);
	int push();
	std::pair<PlayerState, int> checkCollision(float x);
	bool allowMovment(float x);

private:
	int m_Index{ 0 };
	int m_Dx{ 0 };			// X direction of moving elements on this row, Zero by default - only ActiveRows and Rail have moving elements
};