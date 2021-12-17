/*
Name: Devin Mahadeo
Student Number: 160611174
Workshop 4
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Traveler.h"

using namespace std;
namespace sict
{


	Traveler::Traveler()
	{
		t_Name[0] = '\0';
		t_Last[0] = '\0';
		t_Dest[0] = '\0';
		t_year = 0;
		t_day = 0;
		t_month = 0;
	}

	Traveler::Traveler(const char *name, const char *last, const char *dest, int year, int month, int day)
	{
		bool checkmonth = month >= 1 && month <= 12;
		bool checkday = day >= 1 && day <= 31;
		bool checkyear = year >= 2019 && year <= 2022;
		if (name == nullptr || name[0] == '\0' || last == nullptr || last[0] == '\0' || dest == nullptr || dest[0] == '\0' || !checkmonth || !checkday || !checkyear)
		{
			*this = Traveler();
		}
		else
		{
			*this = Traveler(name, last, dest);
			this->t_year = year;
			this->t_month = month;
			this->t_day = day;
		}
	}
	

	Traveler::Traveler(const char *name, const char *last, const char *dest)
	{
		if (name == nullptr || name[0] == '\0' || last == nullptr || last[0] == '\0' || dest == nullptr || dest[0] == '\0')
		{


			t_Name[0] = '\0';
			t_Last[0] = '\0';
			t_Dest[0] = '\0';

		}
		else
		{
			strcpy(t_Name, name);
			strcpy(t_Last, last);
			strcpy(t_Dest, dest);
			t_year = 2019;
			t_day = 1;
			t_month = 7;
		}
	}

	bool Traveler::isEmpty() const
	{
		bool valid;

		if (Traveler::t_Name[0] == '\0' || Traveler::t_Last[0] == '\0' || Traveler::t_Dest[0] == '\0' || Traveler::t_year == '\0' || Traveler::t_month == '\0' || Traveler::t_day == '\0')
		{
			valid = true;
		}
		else
		{
			valid = false;
		}

		return valid;
	}

	const char* Traveler::name() const
	{
		return t_Name;
	}

	bool Traveler::canTravelWith(const Traveler&match) const
	{
		if (this->t_day == match.t_day && this->t_month == match.t_month && this->t_year == match.t_year && strcmp(this->t_Dest, match.t_Dest) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Traveler::display() const
	{
		if (isEmpty())
		{
			cout << "--> Not a valid traveler! <--" << endl;
		}
		else
		{
			cout << t_Last << ", " << t_Name << " goes to " << t_Dest << " on " << t_year << "/";

			cout.fill('0');
			cout.width(2);

			cout << t_month << "/";

			cout.fill('0');
			cout.width(2);

			cout << t_day << endl;
		}

	}
}