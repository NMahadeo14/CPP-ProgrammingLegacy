#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Product.h"
#include "Utilities.h"
#include "ErrorState.h"


using namespace std;

namespace ama
{
	Product::Product(char Producttype) : m_productType(Producttype)
	{
		m_sku[0] = '\0';
		m_ProductUnit[0] = '\0';
		m_ProductName = nullptr;
		m_QuantityAvailable = 0;
		m_ProductNeeded = 0;
		m_price = 0.00;
		m_StatusTax = false;

	}

	Product::Product(const char* sku, const char* name, const char* unit, double price, int quantityavailable, int quantityonhand, bool status) : m_productType('N')
	{
		if (name == nullptr)
		{
			*this = Product();
		}
		else
		{
			this->m_ProductName = nullptr;
			strcpy(this->m_sku, sku);
			this->m_ProductName = new char[strlen(name) + 1];
			strcpy(this->m_ProductName, name);
			strcpy(this->m_ProductUnit, unit);
			this->m_price = price;
			this->m_QuantityAvailable = quantityavailable;
			this->m_ProductNeeded = quantityonhand;
			this->m_StatusTax = status;
		}
	}

	Product::~Product()
	{
		delete[] m_ProductName;
		m_ProductName = nullptr;
	}

	Product::Product(const Product& other) : m_productType(other.m_productType)
	{
		delete[] m_ProductName;
		m_ProductName = nullptr;

		*this = other;
	}

	Product& Product::operator=(const Product& other)
	{
		delete[] m_ProductName;
		m_ProductName = nullptr;

		if (this != &other)
		{
			//shallow copy
			strcpy(this->m_sku, other.m_sku);
			strcpy(this->m_ProductUnit, other.m_ProductUnit);
			this->m_price = other.m_price;
			this->m_QuantityAvailable = other.m_QuantityAvailable;
			this->m_ProductNeeded = other.m_ProductNeeded;
			this->m_StatusTax = other.m_StatusTax;

			//deep copy
			if (other.m_ProductName != nullptr)
			{
				this->m_ProductName = new char[strlen(other.m_ProductName) + 1];
				strcpy(this->m_ProductName, other.m_ProductName);
			}
			else
			{
				this->m_ProductName = nullptr;
			}
		}
		return *this;

	}

	int Product::operator+=(int cnt)
	{
		if (cnt > 0)
		{
			this->m_ProductNeeded += cnt;
		}

		return this->m_ProductNeeded;
	}

	bool Product::operator==(const char* sku) const
	{
		if (strcmp(this->m_sku, sku) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Product::operator> (const char* sku) const
	{
		if (strcmp(this->m_sku, sku) > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Product::operator>(const iProduct& rhsProduct) const
	{
		if (strcmp(this->m_ProductName, rhsProduct.name()) > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int Product::qtyAvailable() const
	{
		return this->m_QuantityAvailable;
	}

	int Product::qtyNeeded() const
	{
		return this->m_ProductNeeded;
	}

	double Product::total_cost() const
	{
		double tax = 0.0;
		double totalCost = 0.00;

		if (m_StatusTax == true)
		{
			tax = m_price * tax_rate;
		}

		totalCost = m_price + tax;

		return (this->m_ProductNeeded * totalCost);

	}

	void Product::message(const char* pText)
	{
		m_messageDisplay.message(pText);
	}

	bool Product::isClear() const
	{
		if (m_messageDisplay.operator bool() == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Product::isEmpty() const
	{
		if (m_ProductName == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	std::istream& Product::read(std::istream& in, bool interractive)
	{
		char sku[max_length_sku + 1];
		char* name = nullptr;
		name = new char[max_length_name + 1];
		char unit[max_length_unit + 1];
		char taxed;
		double price;
		int quantityavailable = 0;
		int quantityNeeded = 0;
		bool StatusTax = false;

		if (interractive == true)
		{
			cout.width(max_length_label);
			cout.setf(ios::right);
			cout << "Sku: ";
			in >> sku;

			cout.width(max_length_label);
			cout.setf(ios::right);
			cout << "Name (no spaces): ";
			in >> name;

			cout.width(max_length_label);
			cout.setf(ios::right);
			cout << "Unit: ";
			in >> unit;

			cout.width(max_length_label);
			cout.setf(ios::right);
			cout << "Taxed? (y/n): ";
			in >> taxed;

			if (taxed == 'Y' || taxed == 'y')
			{
				StatusTax = true;
			}
			else if (taxed == 'N' || taxed == 'n')
			{
				StatusTax = false;
			}
			else
			{
				m_messageDisplay.message("Only (Y)es or (N)o are acceptable!");
				in.setstate(ios::failbit);
			}

			if (!in.fail())
			{
				cout.width(max_length_label);
				cout.setf(ios::right);
				cout.precision(2);
				cout.setf(ios::fixed);
				cout << "Price: ";
				in >> price;
				if (in.fail())
				{
					m_messageDisplay.message("Invalid Price Entry!");
					in.setstate(ios::failbit);
				}
			}

			if (!in.fail())
			{
				cout.width(max_length_label);
				cout << "Quantity on hand: ";
				in >> quantityNeeded;
				if (in.fail())
				{
					m_messageDisplay.message("Invalid Quantity Available Entry!");
					in.setstate(ios::failbit);
				}
			}

			if (!in.fail())
			{
				cout.width(max_length_label);
				cout.setf(ios::right);
				cout << "Quantity needed: ";
				in >> quantityavailable;

				if (in.fail())
				{
					m_messageDisplay.message("Invalid Quantity Needed Entry!");
					in.setstate(ios::failbit);
				}
			}

			if (!in.fail())
			{
				Product temp = Product(sku, name, unit, price, quantityavailable, quantityNeeded, StatusTax);
				*this = temp;
			}
		}
		else
		{
			in.getline(sku, max_length_label, ',');
			in.getline(name, max_length_label, ',');
			in.getline(unit, max_length_label, ',');

			in >> price;
			in.ignore();

			in >> StatusTax;
			in.ignore();

			in >> quantityavailable;
			in.ignore();

			in >> quantityNeeded;
			in.ignore();

			Product tmp = Product(sku, name, unit, price, quantityNeeded, quantityavailable, StatusTax);
			*this = tmp;
		}

		delete[] name;
		name = nullptr;
		return in;
	}

	std::ostream& Product::write(std::ostream& out, int writeMode) const
	{
		if (m_messageDisplay.message() != nullptr)
		{
			out << m_messageDisplay.message();
			return out;
		}

		if (isEmpty() == true)
		{
			return out;
		}
		else
		{
			if (writeMode == write_condensed)
			{
				out.precision(2);
				out.setf(ios::fixed);
				out << m_productType << ',' << m_sku << ',' << m_ProductName << ',' << m_ProductUnit << ',' << m_price << ',' << m_StatusTax << ',' << m_ProductNeeded << ',' << m_QuantityAvailable;
			}
			else if (writeMode == write_table)
			{
				out << ' ' << setw(max_length_sku) << right << m_sku << " | ";
				out << left;
				if (strlen(m_ProductName) > 16)
				{
					for (int i = 0; i < 13; i++)
					{
						out << setw(1) << left;
						out << m_ProductName[i];
					}
					out << "...";
				}
				else
				{
					out << setw(16) << left;
					out << m_ProductName;
				}
				out << " |";

				out << ' ' << setw(10) << left << m_ProductUnit << " |";

				out << ' ' << right << setw(7);
				out.precision(2);
				out.setf(ios::fixed);
				out << m_price << " |";

				out << ' ' << right << setw(3);
				if (m_StatusTax)
				{
					out << "yes";
				}
				else
				{
					out << "no";
				}
				out << " |";

				out << ' ' << right << setw(6) << qtyNeeded() << " |";
				out << ' ' << right << setw(6) << qtyAvailable() << " |";
			}
			else if (writeMode == write_human)
			{

				cout.width(max_length_label);
				out.setf(ios::right);
				out << "Sku: " << m_sku << endl;

				cout.width(max_length_label);
				out.setf(ios::right);
				out << "Name: " << m_ProductName << endl;

				cout.width(max_length_label);
				out.setf(ios::right);
				out.precision(2);
				out.setf(ios::fixed);
				out << "Price: " << m_price << endl;

				if (m_StatusTax == true)
				{

					cout.width(max_length_label);
					out.setf(ios::right);

					out << "Price after Tax: " << m_price * 1.13 << endl;
				}
				else
				{

					cout.width(max_length_label);
					out.setf(ios::right);
					out << "Price after Tax: " << m_price << endl;
				}
				//out.unsetf(ios::fixed);

				if (m_ProductUnit[0] != '\0') {

					cout.width(max_length_label);
					out.setf(ios::right);
					out << "Quantity Available: " << m_ProductNeeded << " " << m_ProductUnit << endl;

					cout.width(max_length_label);
					out.setf(ios::right);
					out << "Quantity Needed: " << m_QuantityAvailable << " " << m_ProductUnit << endl;
				}
				else
				{

					cout.width(max_length_label);
					out.setf(ios::right);
					out << "Quantity Available: " << m_ProductNeeded << " package" << endl;

					cout.width(max_length_label);
					out.setf(ios::right);
					out << "Quantity Needed: " << m_QuantityAvailable << "  package" << endl;
				}
			}

		}
		return out;
	}

	const char* Product::name() const
	{
		return this->m_ProductName;
	}

	const char* Product::sku() const
	{
		return this->m_sku;
	}

	const char* Product::errorMsg() const
	{
		return m_messageDisplay.message();
	}

};
