/*
Name: Devin Mahadeo
Student Number: 160611174
Workshop 4
*/

#ifndef SICT_TRAVELER_H
#define SICT_TRAVELER_H

namespace sict
{

	const int max_destination_size = 32;
	const int max_name_size = 16;

	class Traveler
	{
		char t_Name[max_name_size + 1];
		char t_Last[max_name_size + 1];
		char t_Dest[max_destination_size + 1];
		int t_year;
		int t_month;
		int t_day;
	public:
		Traveler();
		Traveler(const char *name, const char *last, const char *dest);
		Traveler(const char *name, const char *last, const char *dest, int year, int month, int day);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Traveler&) const;

	};
}



#endif
