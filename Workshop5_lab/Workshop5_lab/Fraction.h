/*
Name: Devin Mahadeo
Student #: 160611174
Workshop 5
*/

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

	};
}
