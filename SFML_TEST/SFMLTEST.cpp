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
	sf::Texture Tpuk;
	Tpuk.loadFromFile("puk.png");
	Speelveld veld(1600, 900);
	sf::RenderWindow window(sf::VideoMode(veld.getLengteSpeelveld(), veld.getBreedteSpeelveld()), "AIRHOCKEY!");
	Scoreboard scoreboard(0, 0, 0, 10, "");
	Schijf puk(1000, 800, -1, 1, 2, 30, sf::Sprite(Tpuk), sf::CircleShape(30, 30),true);
	Schijf speler(0, 0, 0, 0, 1, 20, sf::Sprite(), sf::CircleShape(20, 30), true);

	//Achtergrond opmaken

	
	sf::Sprite LinksBoven, LinksOnder, RechtsBoven, RechtsOnder;	
	sf::Texture veldDeel1, veldDeel2;
	veldDeel1.loadFromFile("LinksB.png"); veldDeel2.loadFromFile("LinksO.png");
	LinksBoven.setTexture(veldDeel1); LinksOnder.setTexture(veldDeel2); RechtsBoven.setTexture(veldDeel1); RechtsOnder.setTexture(veldDeel2);
	RechtsBoven.setScale(-1, 1); RechtsOnder.setScale(-1, 1);
	LinksBoven.setPosition(0, 0); LinksOnder.setPosition(0, veld.getBreedteSpeelveld() / 2); RechtsBoven.setPosition(veld.getLengteSpeelveld() , 0); RechtsOnder.setPosition(veld.getLengteSpeelveld() , veld.getBreedteSpeelveld() / 2);
	

	puk.colorswitch(220, 20, 60 ,255); //colorswitch aanpassen om object mee te geven
	speler.colorswitch(124, 205, 31, 255);
	puk.getCollider2D().setTexture(&Tpuk);
	puk.setStartPosition();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		puk.setPosition( puk.getDeltaX(), puk.getDeltaY(),window.getSize().x,window.getSize().y);
		speler.spelerPos(sf::Mouse::getPosition(window).x-15,sf::Mouse::getPosition(window).y-15);//puk.collisionBorder(puk, veld);		//puk2.collisionBorder(puk2, veld);
		speler.collisionSpeler(puk);
		//scoreboard.goal(puk, veld);
		window.clear();
		window.draw(LinksBoven); window.draw(LinksOnder); window.draw(RechtsBoven); window.draw(RechtsOnder);
		window.draw(puk.getCollider2D());
		window.draw(puk.getSprite());
		window.draw(speler.getCollider2D());
		window.display();
	}

	return 0;
}
