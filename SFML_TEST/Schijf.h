﻿#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace sf {
	class RenderWindow;
}

class Schijf
{
public:
	double getX() const;
	void setX(const double x);
	double getY() const;
	void setY(const double y);
	double getDeltaX() const;
	void setDeltaX(const double deltaX);
	double getDeltaY() const;
	void setDeltaY(const double deltaY);
	int getMass() const;
	void setMass(const int mass);
	int getRadius() const;
	void setRadius(const int radius);

	sf::Sprite getSprite() const;
	void setSprite(const sf::Sprite& sprite);
	sf::CircleShape getCollider2D() const;
	void setCollider2D(const sf::CircleShape& collidor2D);
	bool isCollidePosible() const;
	void setCollidePosible(const bool collidePosible);
	
	Schijf(const double x, const double y, const double deltaX, const double deltaY, const int mass, const int radius, const sf::Sprite sprite,const sf::CircleShape collider2D ,const bool collisionPossible);
#pragma region Functions
	void setPosition(const double x, const double y,const double maxX , const double maxY);
	void spelerPos(int newX, int newY);
	void collisionSpeler(Schijf& puk);
	void colorswitch(int R, int G, int B, int T);
	void collisionSchijven(Schijf& collidor);
	void setStartPosition();
	void Schijf::setResetPosition(const int lengteVeld,const int breedteVeld,const int spelerLaatstePunt);
#pragma endregion

	
	
private:
	double x;
	double y; 
	double deltaX;
	double deltaY;
	int mass;
	int radius;
	sf::Sprite sprite;
	sf::CircleShape collider2D;
	bool collisionPossible;
};
