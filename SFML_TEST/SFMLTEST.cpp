// SFMLTEST.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
#include "Schijf.h"
#include <iostream>
#include "Speelveld.h"
#include <SFML/Graphics/Image.hpp>
#include "Scoreboard.h"
#include "Goal.h"

int main()
{
	sf::Color zwart = sf::Color(255, 255, 255, 126);
	sf::Font letterTypeScoreboard;
	letterTypeScoreboard.loadFromFile("letterScore.otf");
	sf::Text text;
	text.setFillColor(zwart);
	text.setFont(letterTypeScoreboard);
	text.setCharacterSize(64);
	text.setPosition(700, 50);
	text.setString("0");


	//objecten definiëren		
	sf::Texture Tpuk;
	Tpuk.loadFromFile("puk.png");
	Speelveld veld(1600, 900);
	sf::RenderWindow window(sf::VideoMode(veld.getLengteSpeelveld(), veld.getBreedteSpeelveld()), "AIRHOCKEY!");
	Scoreboard scoreboard(0, 0, 0, 10, "");
	Schijf puk((veld.getLengteSpeelveld() / 2) - 30, (veld.getBreedteSpeelveld() / 2) - 30, 0, 0, 25, 30, sf::Sprite(Tpuk), sf::CircleShape(30, 30), true);
	Schijf speler(0, 0, 0, 0, 15, 20, sf::Sprite(), sf::CircleShape(20, 30), true);
	puk.setMass(8);

	//Achtergrond opmaken

	sf::Sprite LinksBoven, LinksOnder, RechtsBoven, RechtsOnder, tempSprite;
	sf::Texture veldDeel1, veldDeel2;
	sf::Texture tempVeld;
	veldDeel1.loadFromFile("LinksB.png"); veldDeel2.loadFromFile("LinksO.png"); tempVeld.loadFromFile("TRASH.jpg");
	LinksBoven.setTexture(veldDeel1); LinksOnder.setTexture(veldDeel2); RechtsBoven.setTexture(veldDeel1); RechtsOnder.setTexture(veldDeel2); tempSprite.setTexture(tempVeld);
	RechtsBoven.setScale(-1, 1); RechtsOnder.setScale(-1, 1);
	LinksBoven.setPosition(0, 0); LinksOnder.setPosition(0, veld.getBreedteSpeelveld() / 2); RechtsBoven.setPosition(veld.getLengteSpeelveld(), 0); RechtsOnder.setPosition(veld.getLengteSpeelveld(), veld.getBreedteSpeelveld() / 2);


	puk.colorswitch(220, 20, 60, 255); //colorswitch aanpassen om object mee te geven
	speler.colorswitch(124, 205, 31, 255);
	puk.getSprite().setScale(puk.getCollider2D().getScale());
	puk.getCollider2D().setTexture(&Tpuk);
	puk.setStartPosition();

	sf::RectangleShape goal(sf::Vector2f(80, 120));
	goal.setFillColor(sf::Color(122, 16, 248, 126));
	goal.setPosition(30, 390);
	sf::RectangleShape goal2(sf::Vector2f(80,120));
	goal2.setFillColor(sf::Color(122, 16, 248, 126));
	goal2.setPosition(1490, 390);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}	
		if (!veld.collisionGoal(scoreboard, puk)) {
			puk.setPosition(puk.getDeltaX(), puk.getDeltaY(), window.getSize().x, window.getSize().y);
		}	
		speler.spelerPos(sf::Mouse::getPosition(window).x - 15, sf::Mouse::getPosition(window).y - 15);//puk.collisionBorder(puk, veld);		//puk2.collisionBorder(puk2, veld);
		speler.collisionSpeler(puk);
		
		//scoreboard.goal(puk, veld);
		text.setString(std::to_string(scoreboard.getScore1()) + " - " + std::to_string(scoreboard.getScore2()));
		window.clear();
		//window.draw(LinksBoven); window.draw(LinksOnder); window.draw(RechtsBoven); window.draw(RechtsOnder);
		window.draw(tempSprite);
		window.draw(puk.getCollider2D());
		window.draw(puk.getSprite());
		window.draw(speler.getCollider2D());
		window.draw(goal);
		window.draw(goal2);
		window.draw(text);
		window.display();
	}

	return 0;
}
