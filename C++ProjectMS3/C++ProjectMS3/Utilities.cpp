#include <iostream>
#include "Utilities.h"
using namespace std;

namespace ama
{
	double& operator+=(double& total, const Product& prod)
	{
		return total += prod.total_cost();
	}

	std::ostream& operator<<(std::ostream& out, const Product& prod)
	{
		return prod.write(out, write_human);
	}

	std::istream& operator>>(std::istream& in, Product& prod)
	{
		return prod.read(in, true);
		return in;
	}
}