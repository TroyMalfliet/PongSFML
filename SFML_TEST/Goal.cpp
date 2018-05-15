#include "Goal.h"
#include <string.h>
#include "Speelveld.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void Goal::setPosistionGoal(Speelveld speelveld, int SpelerHelft) {
	
}

Goal::Goal(const sf::RectangleShape doel, const int x, const int y, const int lengte, const int breedte) :
	doel(doel),
	x(x),
	y(y),
	lengte(lengte),
	breedte(breedte)
{}

