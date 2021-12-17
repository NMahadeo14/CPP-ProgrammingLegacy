#ifndef AMA_UTILITIES_H
#define AMA_ULTILITIES_H
#include "Product.h"

namespace ama
{
	double& operator+=(double& total, const Product& prod);
	std::ostream& operator<<(std::ostream& out, const Product& prod);
	std::istream& operator>>(std::istream& in, Product& prod);
}
#endif // !AMA_UTILITIES_H
