﻿#include "Scoreboard.h"
#include <string.h>
#include "Speelveld.h"
#include "Schijf.h"

int Scoreboard::getScore1() const
{
	return score1;
}

void Scoreboard::setScore1(const int score1)
{
	this->score1 = score1;
}

int Scoreboard::getScore2() const
{
	return score2;
}

void Scoreboard::setScore2(const int score2)
{
	this->score2 = score2;
}

int Scoreboard::getMinuten() const
{
	return minuten;
}

void Scoreboard::setMinuten(const int minuten)
{
	this->minuten = minuten;
}

int Scoreboard::getSeconden() const
{
	return seconden;
}

void Scoreboard::setSeconden(const int seconden)
{
	this->seconden = seconden;
}

std::string Scoreboard::getKlok() const
{
	return klok;
}

void Scoreboard::setKlok(const std::string& klok)
{
	this->klok = klok;
}
void Scoreboard::updateKlok()
{
	this->seconden = seconden--;
	if(this->seconden == -1)
	{
		minuten--;
	}
	this->klok = std::to_string(minuten) + ":" + std::to_string(seconden);
}
void Scoreboard::goal(Schijf schijf,Speelveld speelveld)
{
	if (schijf.getDeltaY() >= speelveld.getBreedteSpeelveld() / 3 && schijf.getDeltaY() <= ((2 * speelveld.getBreedteSpeelveld()) / 3))
	{
		if (schijf.getX() <= 0) this->score1 += 1;
		if (schijf.getX() >= 0) this->score2 += 1;
	}
}


Scoreboard::Scoreboard(const int score1, const int score2, const int minuten, const int seconden, const std::string& klok)
	: score1(score1),
	score2(score2),
	minuten(minuten),
	seconden(seconden),
	klok(klok)
{
}