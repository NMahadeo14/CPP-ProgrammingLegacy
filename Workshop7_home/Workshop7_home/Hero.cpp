/*
NAME: Devin Mahadeo
STUDENT No: 160611174
CLASS: SSB
*/

#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;
namespace sict
{
	Hero::Hero()
	{
		m_name[0] = '\0';
		m_health = 0;
		m_attk = 0;
	}

	Hero::Hero(const char* name, int health, int attack)
	{
		if (name[0] == '\0' || health <= 0 || attack <= 0)
		{
			*this = Hero();
		}
		else
		{
			strcpy(this->m_name, name);
			this->m_health = health;
			this->m_attk = attack;
		}
	}

	void Hero::operator-=(int attack)
	{

		if (attack > 0)
		{
			this->m_health -= attack;
		}

		if (isAlive() == false)
		{
			this->m_health = dead;
		}
	}

	bool Hero::isAlive() const
	{
		if (this->m_health > dead)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	bool Hero::isEmpty() const
	{
		if (m_name[0] == '\0' && m_health == 0 && m_attk == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int Hero::attackStrength() const
	{
		if (m_attk > 0)
		{
			return this->m_attk;
		}
		else
		{
			return 0;
		}
	}

	const Hero& operator*(const Hero& first, const Hero& second)
	{
		Hero winner;
		Hero First;
		Hero Second;

		First = first;
		Second = second;
		int i = 0;
		int totalRounds = 0;

		for (i = 0; (i < max_rounds) && (First.isAlive()) && (Second.isAlive()); i++)
		{
			if (First.isAlive())
			{
				Second -= First.attackStrength();

			}

			if (First.isAlive())
			{
				First -= Second.attackStrength();
			}
			totalRounds++;
		}
		if (First.isAlive() && Second.isAlive() == false)
		{
			winner = First;
			cout << "Ancient Battle! " << First << " vs " << Second << " : Winner is " << winner << " in " << totalRounds << " rounds." << endl;
			return first;
		}
		else
		{
			winner = Second;
			cout << "Ancient Battle! " << First << " vs " << Second << " : Winner is " << winner << " in " << totalRounds << " rounds." << endl;
			return second;
		}




	}

	std::ostream& operator<<(ostream& os, const Hero& hero)
	{
		if (hero.isEmpty())
		{
			os << "No hero";
		}
		else
		{
			os << hero.m_name;
		}
		return os;
	}


}
