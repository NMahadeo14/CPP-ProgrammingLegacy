#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H
#include "Product.h"
#include "Date.h"

namespace ama
{
	class Perishable : public Product
	{

		Date m_expirydate;

	public:

		Perishable();
		std::ostream& write(std::ostream& out, int writeMode) const;
		std::istream& read(std::istream& in, bool interractive);


	};
}


#endif
