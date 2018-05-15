#pragma once
#include <SFML/Graphics/Texture.hpp>
#include "Schijf.h"
#include "Scoreboard.h"

class Speelveld
{
public:
	int getLengteSpeelveld() const;
	void setLengteSpeelveld(const int lengteSpeelveld);
	int getBreedteSpeelveld() const;
	void setBreedteSpeelveld(const int breedteSpeelveld);

	bool collisionGoal(Scoreboard& scoreboard, Schijf& puk);
	Speelveld(const int lengteSpeelveld, const int breedteSpeelveld);
private:
	int lengteSpeelveld;
	int breedteSpeelveld;
};
