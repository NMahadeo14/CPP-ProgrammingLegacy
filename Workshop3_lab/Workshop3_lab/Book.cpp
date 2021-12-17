#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;
namespace sict
{
	void Book::set(const char *famname, const char *realname, const char *btitle, long long _ISBN)
	{

		if (_ISBN > min_isbn_value && _ISBN < max_isbn_value)
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

	bool Book::isEmpty() const
	{
		bool reply;

		if (ISBN == 0)
		{
			reply = true;
		}
		else
		{
			reply = false;
		}

		return reply;
	}

	void Book::display() const
	{
		if (Book::isEmpty() == false)
		{
			cout << "Author: " << Book::name << ", " << Book::familyname << endl;
			cout << "Title: " << Book::title << endl;
			cout << "ISBN-13: " << Book::ISBN << endl;
		}
		else
		{
			cout << "The book object is empty!" << endl;
		}
	}


}



