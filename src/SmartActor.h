#pragma once
#include "Actor.h"

/*
* The SmartActor class extends Actor class by allowing an object to have a list of child objects,
* which are drawn relative to the parent object.
*/
class SmartActor : public Actor 
{
public:
	SmartActor(Vector2 pos = { 0, 0 }, Texture2D* image = nullptr);
	SmartActor(const SmartActor&) = default;
	SmartActor& operator=(const SmartActor&) = default;
	~SmartActor() = default;

	virtual void update() override;
	virtual void draw(float offset_x, float offset_y);

protected:
	std::vector<SmartActor*> m_Children;
};