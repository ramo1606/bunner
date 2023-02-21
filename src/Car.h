#pragma once
#include "Mover.h"

#include <array>

/*
* These correspond to the indicies of the lists m_Sounds and m_Played. Used in Car.update to trigger
* playing of the corresponding sound effects.
*/
enum class CarSoundType : std::uint8_t
{
	SOUND_ZOOM,
	SOUND_HONK
};

class Car : public Mover
{
public:
	Car(int dx, Vector2 pos);
	Car(const Car&) = default;
	Car& operator=(const Car&) = default;
	~Car() = default;

	void playSound(CarSoundType type);

protected:
	// Cars have two sound effects.Each can only play once.We use this
	// list to keep track of which has already played.
	std::array<bool, 2> m_Played{ false, false };
	std::array<std::pair<std::string, int>, 2> m_Sounds{ std::make_pair(std::string("zoom"), 6), std::make_pair(std::string("honk"), 4) };
};