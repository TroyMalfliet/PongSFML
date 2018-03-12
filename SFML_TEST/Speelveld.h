#pragma once
#include <SFML/Graphics/Texture.hpp>

class Speelveld
{
public:
	int getLengteSpeelveld() const;
	void setLengteSpeelveld(const int lengteSpeelveld);
	int getBreedteSpeelveld() const;
	void setBreedteSpeelveld(const int breedteSpeelveld);
	Speelveld(const int lengteSpeelveld, const int breedteSpeelveld);
private:
	int lengteSpeelveld;
	int breedteSpeelveld;
};
