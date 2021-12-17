/*
NAME: Devin Mahadeo
STUDENT No: 160611174
CLASS: SSB
*/
#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"



namespace sict
{
	class SuperHero : public Hero
	{
		char s_name[max_name + 1];
		int s_bonus;
		int s_health;
		int s_attk;
		int s_defend;
	public:
		SuperHero();
		SuperHero(const char* name, int health, int attack, int bonus, int defend);
		int attackStrength() const;
		int defend() const;
		bool isEmpty() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}






#endif

