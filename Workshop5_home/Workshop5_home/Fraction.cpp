/*
Name: Devin Mahadeo
Student #: 160611174
Workshop 5
*/

#include <iostream>
#include <algorithm>
#include "Fraction.h"

using namespace std;
namespace sict
{

	Fraction::Fraction()
	{
		num = -1;
		deno = 0;
	}

	Fraction::Fraction(int numerator, int denominator)
	{
		if (numerator < 0 || denominator <= 0)
		{
			*this = Fraction();
		}
		else
		{
			num = numerator;
			deno = denominator;
			reduce();
		}
	}


	int Fraction::max() const
	{
		return std::max(this->num, this->deno);

	}

	int Fraction::min() const
	{
		return std::min(this->num, this->deno);
	}

	void Fraction::reduce()
	{
		int g_c_d = gcd();
		this->num = this->num / g_c_d;
		this->deno = this->deno / g_c_d;
	}

	int Fraction::gcd() const
	{
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	bool Fraction::isEmpty() const
	{
		bool valid;

		if (num == -1 && deno == 0)
		{
			valid = true;
		}
		else
		{
			valid = false;
		}

		return valid;
	}

	void Fraction::display() const
	{
		if (isEmpty() == true)
		{
			cout << "no fraction stored";
		}
		else if (deno == 1)
		{
			cout << num;
		}
		else
		{
			cout << num << "/" << deno;
		}
	}

	Fraction Fraction::operator+(const Fraction& rhs) const
	{
		Fraction copy;
		if (!isEmpty() && !rhs.isEmpty())
		{
			copy.num = ((this->num * rhs.deno) + (this->deno * rhs.num));
			copy.deno = (this->deno * rhs.deno);
			copy.reduce();
		}

		return copy;
	}

	Fraction Fraction::operator*(const Fraction& rhs) const
	{
		Fraction copy;
		if (!isEmpty() && !rhs.isEmpty())
		{
			copy.num = (this->num * rhs.num);
			copy.deno = (this->deno * rhs.deno);
			copy.reduce();
		}

		return copy;
	}

	bool Fraction::operator==(const Fraction& rhs) const
	{
		Fraction copy;
		if (!isEmpty() && !rhs.isEmpty())
		{
			copy.num = (this->num * rhs.deno);
			copy.deno = (this->deno * rhs.num);
			if (this->num == rhs.num && this->deno == rhs.deno)
			{
				return true;
			}	
		}
		return false;		
	}

	bool Fraction::operator!=(const Fraction& rhs) const
	{
		Fraction copy;
		if (!isEmpty() && !rhs.isEmpty())
		{
			copy.num = (this->num * rhs.deno);
			copy.deno = (this->deno * rhs.num);
			if (this->num != rhs.num && this->deno != rhs.deno)
			{
				return true;
			}
		}
		return false;
	}

	Fraction Fraction::operator+=(const Fraction& rhs)
	{
		if (!isEmpty() && !rhs.isEmpty())
		{
			return *this = (*this + rhs);
			
		}
		else
		{
			return *this = Fraction();
		}
	}





}

