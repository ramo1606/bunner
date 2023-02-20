#pragma once
#include "SmartActor.h"
#include "Common.h"

using namespace Common;

class Bunny : public SmartActor 
{
public:
	Bunny(Vector2 pos = { 0, 0 }, Texture2D* image = nullptr);
	Bunny(const Bunny&) = default;
	Bunny& operator=(const Bunny&) = default;
	~Bunny() = default;

	void update() override;

	void handleInput(int direction);
	PlayerState getState() const { return m_State; };

private:
	PlayerState m_State{ PlayerState::ALIVE };
	int m_Direction{ 2 };
	int m_Timer{ 0 };
	float m_Min_Y{ 0.f };				//Keeps track of the furthest distance we've reached so far in the level, for scoring (Level Y coordinates decrease as the screen scrolls)
	std::vector<int> m_InputQueue;		//If a control input is pressed while the rabbit is in the middle of jumping, it's added to the input queue

	KeyboardKey m_Direction_Keys[4] = { KEY_UP, KEY_RIGHT, KEY_DOWN, KEY_LEFT };
};