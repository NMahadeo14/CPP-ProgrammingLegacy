#ifndef AMA_UTILITIES_H
#define AMA_ULTILITIES_H
#include "Product.h"

namespace ama
{
	double& operator+=(double& total, const iProduct& prod);
	std::ostream& operator<<(std::ostream& out, const iProduct& prod);
	std::istream& operator>>(std::istream& in, iProduct& prod);
	iProduct* createInstance(char tag);
}
#endif // !AMA_UTILITIES_H

