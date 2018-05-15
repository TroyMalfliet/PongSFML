#pragma once
#include <string>
#include "Schijf.h"
#include "Speelveld.h"
#include <SFML/Graphics.hpp>

class Goal
{
public:
	void Goal::setPosistionGoal(Speelveld speelveld, int SpelerHelft);
	Goal(sf::RectangleShape doel, int x, int y, int lengte, int breedte);

private:
	sf::RectangleShape doel;
	int x;
	int y;
	int lengte;
	int breedte;
};