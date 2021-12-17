/*
Name: Devin Mahadeo
Student #: 160611174
Workshop 5
*/

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H


namespace sict
{

	class Fraction
	{
		int num;
		int deno;
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:

		Fraction();
		Fraction(int num, int deno);
		bool isEmpty() const;
		void display() const;
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction operator+=(const Fraction& rhs);

	};
}
#endif
