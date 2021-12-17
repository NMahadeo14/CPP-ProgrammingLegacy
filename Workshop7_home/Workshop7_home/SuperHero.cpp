/*
NAME: Devin Mahadeo
STUDENT No: 160611174
CLASS: SSB
*/
#include <iostream>
#include "Hero.h"
#include "SuperHero.h"

using namespace std;

namespace sict
{
	SuperHero::SuperHero():Hero()
	{
		s_bonus = 0;
		s_defend = 0;
	}

	SuperHero::SuperHero(const char* name, int health, int attack, int bonus, int defend) : Hero(name, health, attack)
	{
		
		if (bonus <= 0 || defend <= 0)
		{
			*this = SuperHero();
		}
		else
		{
			
			this->s_bonus = bonus;
			this->s_defend = defend;
		}
		
	}

	bool SuperHero::isEmpty() const
	{
		if (Hero::isEmpty() && (s_bonus == 0) && (s_defend == 0))
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	int SuperHero::attackStrength() const
	{
		if (this->Hero::attackStrength() > 0)
		{ 
			return Hero::attackStrength() + this->s_bonus;
		}
		else
		{
			return 0;
		}
			
	}

	int SuperHero::defend() const 
	{
		return s_defend;

		if (s_defend == '\0')
		{
			return 0;
		}
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
	{
		SuperHero winner;
		SuperHero First;
		SuperHero Second;

		First = first;
		Second = second;
		int totalRounds = 0;

		for (int i = 0; i < max_rounds && (First.isAlive() && Second.isAlive()); i++)
		{
			First -= Second.attackStrength() - First.defend();
			Second -= First.attackStrength() - Second.defend();
			totalRounds++;
		}
		if (First.isAlive() && Second.isAlive() == false)
		{
			winner = First;
			cout << "Super Fight! " << First << " vs " << Second << " : Winner is " << winner << " in " << totalRounds << " rounds." << endl;
			return first;
		}
		else
		{
			winner = Second;
			cout << "Super Fight! " << First << " vs " << Second << " : Winner is " << winner << " in " << totalRounds << " rounds." << endl;
			return second;
		}




	}
}