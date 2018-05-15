#include <SFML/Graphics.hpp>
#include "Speelveld.h"

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

Speelveld::Speelveld(const int lengteSpeelveld, const int breedteSpeelveld):
	lengteSpeelveld(lengteSpeelveld),
	breedteSpeelveld(breedteSpeelveld)
{}


bool Speelveld::collisionGoal(Scoreboard &scoreboard,Schijf &puk) {
	bool goalGescoord = false;
	sf::RectangleShape goal(sf::Vector2f(80, 120));
	int lengte = breedteSpeelveld;
	goal.setPosition(sf::Vector2f(30, (breedteSpeelveld / 2) - 60));

	if (puk.getCollider2D().getGlobalBounds().intersects(goal.getGlobalBounds())) {
		scoreboard.updateScore(1);
		puk.setResetPosition(lengteSpeelveld, breedteSpeelveld, 1);
		goalGescoord = true;
	}

	goal.setPosition(lengteSpeelveld - 80, breedteSpeelveld / 2 - 60);

	if (puk.getCollider2D().getGlobalBounds().intersects(goal.getGlobalBounds())) {
		scoreboard.updateScore(2);
		puk.setResetPosition(lengteSpeelveld, breedteSpeelveld, 2);
		goalGescoord = true;
	}
	return goalGescoord;
}