/*NAME: Devin Mahadeo
STUDENT NUMBER: 160611174
EMAIL: Dmahadeo2@myseneca.ca
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;
namespace sict
{ 
	int Book::sums(long long number)
	{
		long long temp = number / 10;
		int totaldigits = 12;
		int totodd = 0;
		int toteven = 0;

		for (int i = 0; i < totaldigits; i++)
		{
			if (i % 2 == 0)
			{
				toteven = (toteven + (int)(temp % 10));
				temp = temp / 10;
			}
			else
			{
				totodd = (totodd + (int)(temp % 10));
				temp = temp / 10;
			}
		}

		toteven = toteven * 3;
		return totodd + toteven;
	}
	void Book::set(const char *famname, const char *realname, const char *btitle, long long _ISBN)
	{
		int total = 0;
		int multiple = 0;
		int diff = 0;
		int checkdigit = 0;
		checkdigit = _ISBN % 10;

		if (_ISBN > min_isbn_value && _ISBN < max_isbn_value)
		{
			total = sums(_ISBN);

			multiple = ((total - 1) / 10 + 1) * 10;

			diff = multiple - total;

			if (diff == checkdigit)
			{
				strncpy(Book::familyname, famname, max_name_size);
				strncpy(Book::name, realname, max_name_size);
				strncpy(Book::title, btitle, max_title_size);
				Book::ISBN = _ISBN;
			}
			else
			{
				Book::ISBN = 0;
			}
		}
		else
		{
			Book::ISBN = 0;
		}
	}

	void Book::set(int year, double price)
	{
		if (year > 0 && price > 0)
		{	
			b_year = year;
			b_price = price;
		}
	}

	bool Book::isEmpty() const
	{
		bool reply;

		if (Book::ISBN == 0)
		{
			reply = true;
		}
		else
		{
			reply = false;
		}

		return reply;
	}

	void Book::display(bool valid) const
	{
		if (Book::isEmpty() == true && valid == false)
		{
			cout << "The book object is empty!" << endl;
		}
		else if (Book::isEmpty() == false && valid == false)
		{
			cout << "Author: " << Book::name << ", " << Book::familyname << endl;
			cout << "Title: " << Book::title << endl;
			cout << "ISBN-13: " << Book::ISBN << endl;
			cout << "Publication Year: " << Book::b_year << endl;
			cout << "Price: " << Book::b_price << endl;
		}
		else if (Book::isEmpty() == true && valid == true)
		{
			cout.setf(ios::left);
			cout.width(93);
			cout << "|The book object is empty!" << "|" << endl;

		}
		else if (Book::isEmpty() == false && valid == true)
		{
			cout << "|";
			cout.setf(ios::right);
			cout.width(max_name_size);
			cout << Book::name;
			cout << "|";

			cout.width(max_name_size);
			cout << Book::familyname;
			cout << "|";

			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(max_title_size);
			cout << Book::title;
			cout << "|";

			cout.setf(ios::right);
			cout.width(13);
			cout << Book::ISBN;
			cout << "|";

			cout.width(4);
			cout << Book::b_year;
			cout << "|";

			cout.width(6);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << Book::b_price;
			cout << "|" << endl;

		}
	}


}



