#include "Speelveld.h"
#include "Schijf.h"

int Speelveld::getLengteSpeelveld() const
{
	return lengteSpeelveld;
}

void Speelveld::setLengteSpeelveld(const int lengteSpeelveld)
{
	this->lengteSpeelveld = lengteSpeelveld;
}

int Speelveld::getBreedteSpeelveld() const
{
	return breedteSpeelveld;
}

void Speelveld::setBreedteSpeelveld(const int breedteSpeelveld)
{
	this->breedteSpeelveld = breedteSpeelveld;
}

Speelveld::Speelveld(const int lengteSpeelveld, const int breedteSpeelveld)
	: lengteSpeelveld(lengteSpeelveld),
	breedteSpeelveld(breedteSpeelveld)
{
}

