#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include "Schijf.h"
#include <iostream>
#include <sstream>

class Scoreboard
{
public:
	int getScore1();
	void setScore1(int score1);
	int getScore2();
	void setScore2(int score2);
	int getMinuten() const;
	void setMinuten(const int minuten);
	int getSeconden() const;
	void setSeconden(const int seconden);
	std::string getKlok() const;
	void setKlok(const std::string& klok);
	Scoreboard(int score1,int score2, int seconden, const int minuten, const std::string& klok);
	void updateKlok();
	void updateScore(int partij);

private:
	int score1;
	int score2;
	int minuten;
	int seconden;
	std::string klok;
};
