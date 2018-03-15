// SFMLTEST.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
#include "Schijf.h"
#include <iostream>
#include "Speelveld.h"
#include <SFML/Graphics/Image.hpp>
#include "Scoreboard.h"

int main()
{	
	//objecten definiëren
	Speelveld veld(1600, 900);
	Scoreboard scoreboard(0, 0, 0, 10, "");
	Schijf puk(1000, 800, -1, 1, 2, 10, sf::Sprite(), sf::CircleShape(20, 30),true);	
	Schijf puk2(100,800,  5, 2, 1, 10, sf::Sprite(), sf::CircleShape(20, 30),true);
	Schijf speler(0, 0, 0, 0, 1, 20, sf::Sprite(), sf::CircleShape(20, 30), true);

	//Achtergrond opmaken

	sf::RenderWindow window(sf::VideoMode(veld.getLengteSpeelveld(), veld.getBreedteSpeelveld()), "AIRHOCKEY!");
	sf::Sprite LinksBoven, LinksOnder, RechtsBoven, RechtsOnder;	
	sf::Texture veldDeel1, veldDeel2,Tpuk;
	veldDeel1.loadFromFile("LinksB.png"); veldDeel2.loadFromFile("LinksO.png"); Tpuk.loadFromFile("puk.png");
	LinksBoven.setTexture(veldDeel1); LinksOnder.setTexture(veldDeel2); RechtsBoven.setTexture(veldDeel1); RechtsOnder.setTexture(veldDeel2);
	RechtsBoven.setScale(-1, 1); RechtsOnder.setScale(-1, 1);
	LinksBoven.setPosition(0, 0); LinksOnder.setPosition(0, veld.getBreedteSpeelveld() / 2); RechtsBoven.setPosition(veld.getLengteSpeelveld() , 0); RechtsOnder.setPosition(veld.getLengteSpeelveld() , veld.getBreedteSpeelveld() / 2);
	

	puk.colorswitch(220, 20, 60 ,255); //colorswitch aanpassen om object mee te geven
	puk2.colorswitch(20, 60, 220, 255);
	speler.colorswitch(124, 205, 31, 255);
	puk.getCollider2D().setTexture(&Tpuk);
	puk.setStartPosition();
	puk2.setStartPosition();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		puk.setPosition( puk.getDeltaX(), puk.getDeltaY());
		puk2.setPosition(puk2.getDeltaX(), puk2.getDeltaY());
		speler.spelerPos(sf::Mouse::getPosition(window).x-15,sf::Mouse::getPosition(window).y-15);
		//puk.collisionBorder(puk, veld);
		//puk2.collisionBorder(puk2, veld);
		std::cout << speler.isCollidePosible() << std::endl;
		puk.collisionSchijven(puk2);
		speler.collisionSpeler(puk);
		speler.collisionSpeler(puk2);
		scoreboard.goal(puk, veld);
		window.clear();
		window.draw(LinksBoven); window.draw(LinksOnder); window.draw(RechtsBoven); window.draw(RechtsOnder);
		window.draw(puk.getCollider2D());
		window.draw(puk2.getCollider2D());
		window.draw(puk2.getSprite());
		window.draw(speler.getCollider2D());
		window.display();
	}

	return 0;
}
