#include <iostream>
#include "Utilities.h"
using namespace std;

namespace ama
{
	double& operator+=(double& total, const iProduct& prod)
	{
		return total += prod.total_cost();
	}

	std::ostream& operator<<(std::ostream& out, const iProduct& prod)
	{
		return prod.write(out, write_human);
	}

	std::istream& operator>>(std::istream& in, iProduct& prod)
	{
		return prod.read(in, true);
		return in;
	}

	iProduct* createInstance(char tag) {

		iProduct *theProduct = nullptr;

		if ((tag == 'N') || (tag == 'n')) {

			theProduct = new Product;
			return theProduct;
		}
		else {

			return nullptr;
		}
	}

}