#ifndef AMA_AMAAPP_H
#define AMA_AMAAPP_H
#include <iostream>
#include "iProduct.h"

namespace ama
{
	class AmaApp
	{
		char m_filename[256];
		iProduct* m_product[100];
		int m_noOfProducts;
	public:
		AmaApp(const char* name);
		~AmaApp();
		int run();
	private:
		void dealloc();
		void clearKeyboard() const;
		void pause() const;
		int menu() const;
		void loadProductRecords();
		void saveProductRecords() const;
		void listProducts() const;
		void deleteProductRecord(iProduct* product);
		void sort();
		iProduct * find(const char* sku) const;
		void addQty(iProduct* product);
		void addProduct(char tag);

	};
}





#endif

