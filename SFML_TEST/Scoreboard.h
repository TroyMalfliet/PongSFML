#pragma once
#include <string>
#include "Schijf.h"
#include "Speelveld.h"

class Scoreboard
{
public:
	int getScore1() const;
	void setScore1(const int score1);
	int getScore2() const;
	void setScore2(const int score2);
	int getMinuten() const;
	void setMinuten(const int minuten);
	int getSeconden() const;
	void setSeconden(const int seconden);
	std::string getKlok() const;
	void setKlok(const std::string& klok);
	Scoreboard(const int score1, const int score2,  int seconden, const int minuten, const std::string& klok);
	void updateKlok();
	void goal(Schijf schijf, Speelveld speelveld);

private:
	int score1;
	int score2;
	int minuten;
	int seconden;
	std::string klok;
};
