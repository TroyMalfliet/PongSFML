#include "Schijf.h"
#include <ostream>
#include <iostream>
#include "Scoreboard.h"

double Schijf::getX() const
{
	return x;
}

void Schijf::setX(const double x)
{
	this->x = x;
	collider2D.setPosition(x, this->y);
}

double Schijf::getY() const
{
	return y;
}

void Schijf::setY(const double y)
{
	this->y = y;
	collider2D.setPosition(this->x, y);
}

double Schijf::getDeltaX() const
{
	return deltaX;
}

void Schijf::setDeltaX(const double deltaX)
{
	this->deltaX = deltaX;
}

double Schijf::getDeltaY() const
{
	return deltaY;
}

void Schijf::setDeltaY(const double deltaY)
{
	this->deltaY = deltaY;
}

int Schijf::getMass() const
{
	return mass;
}

void Schijf::setMass(const int mass)
{
	this->mass = mass;
}

int Schijf::getRadius() const
{
	return radius;
}

void Schijf::setRadius(const int radius)
{
	this->radius = radius;
}

sf::Sprite Schijf::getSprite() const
{
	return sprite;
}

void Schijf::setSprite(const sf::Sprite& sprite)
{
	this->sprite = sprite;
}

sf::CircleShape Schijf::getCollider2D() const
{
	return collider2D;
}

void Schijf::setCollider2D(const sf::CircleShape& collidor2D)
{
	this->collider2D = collidor2D;
}

bool Schijf::isCollidePosible() const
{
	return collisionPossible;
}

void Schijf::setCollidePosible(const bool collidePosible)
{
	this->collisionPossible = collidePosible;
}

Schijf::Schijf(const double x, const double y, const double deltaX, const double deltaY, const int mass,
               const int radius, const sf::Sprite sprite, const sf::CircleShape collider2D, const bool collisionPossible):
								  x(x),
                                  y(y),
                                  deltaX(deltaX),
                                  deltaY(deltaY),
                                  mass(mass),
                                  radius(radius),
								  sprite(sprite),
								  collider2D(collider2D),
								  collisionPossible(collisionPossible)
{
}

void Schijf::setPosition(const double x, const double y)
{
	this->x = (this->x + x);
	this->y = (this->y + y);
	if (this->x > 1480) {
		this->x = 1480;
		this->deltaX = this->deltaX*-1;
	}
	if (this->x < 50) {
		this->x = 50;
		this->deltaX = this->deltaX*-1;
	}
	if (this->y > 850) {
		this->y = 850;
		this->deltaY = this->deltaY*-1;
	}
	if (this->y < 0) {
		this->y = 0;
		this->deltaY = this->deltaY*-1;
	}
	this->collider2D.move(x,y);
	this->sprite.move(x,y);
}

void Schijf::spelerPos(int newX,int newY)
{
	const int oudeX = this->x;
	const int oudeY = this->y; 
	this->collider2D.move(newX-oudeX,newY-oudeY);
	this->x = newX;
	this->y = newY;
	this->deltaX = this->x - oudeX;
	this->deltaY = this->y - oudeY;
}



void Schijf::collisionBorder(Schijf schijf, Speelveld speelveld)
{
	if ((schijf.getX()+60 >= speelveld.getLengteSpeelveld()- schijf.getRadius() || schijf.getX()-60 <= 0 + schijf.getRadius()/2))
	{
		this->deltaX = this->deltaX*-1;
	}
	if (schijf.getY() >= speelveld.getBreedteSpeelveld() - schijf.getRadius() || schijf.getY() <= 0 + schijf.getRadius() / 2)
	{
		this->deltaY = this->deltaY*-1;;
	}
}

void Schijf::collisionSpeler(Schijf& puk)
{
	if (this->collider2D.getGlobalBounds().intersects(puk.getCollider2D().getGlobalBounds()))
	{
		if (this->collisionPossible && puk.isCollidePosible())
		{
			const double oudeDeltaX = this->deltaX;
			const double oudeDeltaY = this->deltaY;
			puk.setDeltaX((puk.getDeltaX()*(puk.getMass() - this->mass) + 2 * (this->mass * oudeDeltaX))
				/ (this->mass + puk.getMass()));

			puk.setDeltaY((puk.getDeltaY()*(puk.getMass() - this->mass) + 2 * (this->mass * oudeDeltaY))
				/ (this->mass + puk.getMass()));
			this->collisionPossible = false;
			puk.setCollidePosible(false);
		}
	}
	else {
		if (!this->collisionPossible) this->collisionPossible = true;
		if (!puk.isCollidePosible()) puk.setCollidePosible(true);
	}
}

void Schijf::collisionSchijven(Schijf& collidor)
{
	if(this->collider2D.getGlobalBounds().intersects(collidor.getCollider2D().getGlobalBounds()))	
	{
		if(this->collisionPossible && collidor.isCollidePosible())
		{
			const double oudeDeltaX = this->deltaX;
			const double oudeDeltaY = this->deltaY;

			this->deltaX = (this->deltaX *(this->mass-collidor.getMass()) + 2*(collidor.getMass()*collidor.getDeltaX()))
			/(this->mass +collidor.getMass());

			this->deltaY = (this->deltaY *(this->mass - collidor.getMass()) + 2 * (collidor.getMass()*collidor.getDeltaY()))
				/ (this->mass + collidor.getMass());

			collidor.setDeltaX((collidor.getDeltaX()*(collidor.getMass() - this->mass) + 2 * (this->mass * oudeDeltaX))
				/ (this->mass + collidor.getMass()));
			
			collidor.setDeltaY((collidor.getDeltaY()*(collidor.getMass()-this->mass) +2*(this->mass * oudeDeltaY))
			/(this->mass + collidor.getMass()));

			this->collisionPossible = false;
			collidor.setCollidePosible(false);
		}	
	}
	else {
		if (!this->collisionPossible) this->collisionPossible = true;
		if(!collidor.isCollidePosible()) collidor.setCollidePosible(true); 
	}
	
}

void Schijf::colorswitch(int R,int G, int B, int T)
{
	this->collider2D.setFillColor(sf::Color(R,G,B,T));
}

void Schijf::setStartPosition()
{
	this->collider2D.setPosition(this->x, this->y);
}
