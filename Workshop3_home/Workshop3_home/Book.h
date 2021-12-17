#ifndef SICT_BOOK_H
#define SICT_BOOK_H

namespace sict
{
	const int max_title_size = 32;
	const int max_name_size = 16;
	const long long min_isbn_value = 1000000000000;
	const long long max_isbn_value = 9999999999999;

	class Book
	{
		char familyname[max_name_size + 1];
		char name[max_name_size + 1];
		long long ISBN;
		char title[max_title_size];
		int b_year;
		double b_price;
	public:
		void set(const char *famname, const char *realname, const char *btitle, long long _ISBN);
		int sums(long long number);
		bool isEmpty() const;
		void display(bool valid = false) const;
		void set(int year, double price);
	};
}



#endif

