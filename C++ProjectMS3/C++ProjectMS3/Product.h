#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include <iostream>
#include "ErrorState.h"

namespace ama
{
	const int max_length_label = 30;
	const int max_length_sku = 7;
	const int max_length_name = 75;
	const int max_length_unit = 10;
	const int write_condensed = 0;
	const int write_table = 1;
	const int write_human = 2;
	const double tax_rate = 0.13;

	class Product
	{
		char m_productType;
		char m_sku[max_length_sku + 1];
		char m_ProductUnit[max_length_unit + 1];
		char *m_ProductName;

		int m_QuantityAvailable;
		int m_ProductNeeded;
		double m_price;
		bool m_StatusTax;


		ErrorState m_messageDisplay;

	protected:

		void message(const char* pText);
		bool isClear() const;

	public:

		Product(char Producttype = 'N');
		Product(const char* sku, const char* name, const char* unit, double price = 0.00, int quantityavailable = 0, int quantityonhand = 0, bool status = false);
		~Product();
		Product(const Product& other);
		Product& operator=(const Product& other);
		int operator+=(int cnt);
		bool operator==(const char* sku) const;
		bool operator> (const char* sku) const;
		bool operator> (const Product&) const;
		int qtyAvailable() const;
		int qtyNeeded() const;
		double total_cost() const;
		bool isEmpty() const;
		std::istream& read(std::istream& in, bool interractive);
		std::ostream& write(std::ostream& out, int writeMode) const;

	};
}



#endif // !AMA_PRODUCT_H

