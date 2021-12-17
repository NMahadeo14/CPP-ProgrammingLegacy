#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "AmaApp.h"
#include "Sort.h"
#include "Utilities.h"


using namespace std;

namespace ama
{
	AmaApp::AmaApp(const char* name)
	{
		strcpy(m_filename, name);
		for (int i = 0; i < 100; i++)
		{
			m_product[i] = nullptr;
		}
		m_noOfProducts = 0;
		loadProductRecords();
	}

	void AmaApp::dealloc()
	{
		for (int i = 0; i < m_noOfProducts; i++)
		{
			delete m_product[i];
			m_product[i] = nullptr;
		}
	}

	AmaApp::~AmaApp()
	{
		dealloc();
	}

	int AmaApp::run()
	{
		int choice;
		iProduct* temp;
		char sku[ama::max_length_sku];
		bool done = false;

		do
		{
			choice = menu();

			switch (choice)
			{
			case 0:

				cout << "Goodbye!" << endl;
				done = true;
				break;
			case 1:
				AmaApp::listProducts();
				break;
			case 2:
				cout << "Please enter the product SKU: ";
				cin >> sku;
				clearKeyboard();
				temp = find(sku);
				if (temp != nullptr)
				{
					cout << endl;
					temp->write(cout, write_human);
					cout << endl;
				}
				else
				{
					cout << endl << "No such product!" << endl;
				}
				pause();
				break;
			case 3:
				addProduct('N');
				loadProductRecords();
				break;
			case 4:
				addProduct('P');
				loadProductRecords();
				break;
			case 5:
				cout << "Please enter the product SKU: ";
				cin >> sku;
				clearKeyboard();
				temp = find(sku);

				if (temp != nullptr)
				{
					cout << endl;
					addQty(temp);
					loadProductRecords();
				}
				else
				{
					cout << endl << "No such product!" << endl;
				}
				cout << endl;
				break;
			case 6:
				cout << "Please enter the product SKU: ";
				cin >> sku;
				clearKeyboard();
				temp = find(sku);

				if (temp != nullptr)
				{
					deleteProductRecord(temp);
					loadProductRecords();
					cout << endl << "Deleted!" << endl;
				}
				else
				{
					cout << endl << "No such product!" << endl;
				}
				break;
			case 7:
				sort();
				loadProductRecords();
				cout << "Sorted!" << endl << endl;
				break;
			default:
				cout << "~~~Invalid selection, try again!~~~" << endl;
				pause();
				break;
			}

		} while (done == false);
		
		return 0;
	}

	void AmaApp::clearKeyboard() const
	{
		while (getchar() != '\n');
	}

	void AmaApp::pause() const
	{
		cout << "Press Enter to continue...";
		clearKeyboard();
		cout << endl;
	}

	int AmaApp::menu() const
	{
		int input = 0;

		cout << "Disaster Aid Supply Management Program" << endl;
		cout << "--------------------------------------" << endl;
		cout << "1- List products" << endl;
		cout << "2- Search product" << endl;
		cout << "3- Add non-perishable product" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to product quantity" << endl;
		cout << "6- Delete product" << endl;
		cout << "7- Sort products" << endl;
		cout << "0- Exit program" << endl;
		cout << "> ";

		cin >> input;

		if (input >= 0 || input <= 7)
		{
			clearKeyboard();
			return input;
			
		}
		else
		{
			clearKeyboard();
			return -1;
			
		}
	}

	void AmaApp::loadProductRecords()
	{
		int i = 0;
		char type;
		std::ifstream fin;
		fin.open(m_filename, ios::in);
		
		if (fin.is_open())
		{
			while (fin)
			{
				fin >> type;
				m_product[i] = createInstance(type);

				if (m_product[i] != nullptr)
				{
					fin.ignore();
					m_product[i]->read(fin, false);
					i++;
				
				}
			}
		}
		m_noOfProducts = i - 1;
		fin.close();
	}

	void AmaApp::saveProductRecords() const
	{
		std::fstream fout;
		fout.open(m_filename, ios::out);
		fout.seekp(ios::beg);

		for (int i = 0; i < m_noOfProducts; i++)
		{
			m_product[i]->write(fout, write_condensed);
			fout << endl;
		}
		fout.close();
	}

	void AmaApp::listProducts() const
	{
		double totalCost = 0;

		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "| Row |     SKU | Product Name     | Unit       |   Price | Tax |   QtyA |   QtyN | Expiry     |" << endl;
		cout << "|-----|---------|------------------|------------|---------|-----|--------|--------|------------|" << endl;

		for (int i = 0; i < m_noOfProducts; i++) 
		{

			cout << "|";
			cout << setw(4) << right << i + 1 << " |";
			m_product[i]->write(cout, write_table);
			totalCost += *m_product[i];
			cout << endl;
		}

		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "|";
		cout << setw(83) << right << "Total cost of support ($): | ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << setw(10);
		cout << totalCost << " |" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl << endl;

		AmaApp::pause();

	}

	void AmaApp::deleteProductRecord(iProduct* product)
	{
		std::fstream fout;
		fout.open(m_filename, ios::out);
	
		if (fout.is_open())
		{
			for (int i = 0; i < m_noOfProducts; i++)
			{
				if (m_product[i] != product)
				{
					m_product[i]->write(fout, write_condensed);
					fout << endl;
				}
			}
		}

		
	}

	void AmaApp::sort()
	{
		sict::sort(m_product, m_noOfProducts);
		saveProductRecords();
	}

	iProduct* AmaApp::find(const char* sku) const
	{
		iProduct* temp = nullptr;

		for (int i = 0; i < m_noOfProducts; i++)
		{
			if (*m_product[i] == sku)
			{
				temp = m_product[i];
				return temp;
			}
		}

		return temp;
	}

	void AmaApp::addQty(iProduct* product)
	{
		int numItems = 0;

		product->write(cout, write_human);
		cout << endl << endl;

		cout << "Please enter the number of purchased items: ";
		cin >> numItems;
		clearKeyboard();

		if (cin.fail())
		{
			cout << "Invalid quantity value!" << endl;
			cin.clear();	
		}
		else
		{

			if (numItems <= (product->qtyAvailable() - product->qtyNeeded()))
			{
				*product += numItems;
			}
			else 
			{
				
				cout << "Too many items; only " << product->qtyAvailable() - product->qtyNeeded() << " is needed. Please return the extra " << numItems - (product->qtyAvailable() - product->qtyNeeded()) << " items." << endl;
			
				*product += (product->qtyAvailable() - product->qtyNeeded());
			
			}
			saveProductRecords();	
			loadProductRecords();
			cout << endl << "Updated!" << endl;
		}	
		
	}

	void AmaApp::addProduct(char tag)
	{
		iProduct* temp = nullptr;
		temp = ama::createInstance(tag);

		if (temp != nullptr)
		{
			cin >> *temp;

			if (cin.fail())
			{
				clearKeyboard();
				cout << endl << temp->errorMsg() << endl << endl;
				cin.clear();
			}
			else
			{
				m_product[m_noOfProducts] = temp;
				m_noOfProducts++;
				saveProductRecords();
				cout << endl << "Success!" << endl << endl;
			}
		}
		
	}






		
}