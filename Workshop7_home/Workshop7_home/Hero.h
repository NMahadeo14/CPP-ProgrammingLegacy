/*
NAME: Devin Mahadeo
STUDENT No: 160611174
CLASS: SSB
*/
#ifndef SICT_HERO_H
#define SICT_HERO_H


namespace sict
{
	const int max_rounds = 100;
	const int max_name = 40;
	const int dead = 0;

	class Hero
	{
		char m_name[max_name + 1];
		int m_health;
		int m_attk;
	public:
		Hero();
		Hero(const char* name, int health, int attack);
		void operator-=(int attack);
		bool isAlive() const;
		bool isEmpty() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);

	};

	const Hero& operator*(const Hero& first, const Hero& second);





}
#endif // !HERO_H


