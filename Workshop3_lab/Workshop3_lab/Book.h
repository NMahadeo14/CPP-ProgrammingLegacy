#ifndef SICT_BOOK_H
#define SICT_BOOK_H

 namespace sict
{
	const int max_title_size = 33;
	const int max_name_size = 17;
	const long long min_isbn_value = 1000000000000;
	const long long max_isbn_value = 9999999999999;

	class Book
	{
		char familyname[max_name_size];
		char name[max_name_size];
		long long ISBN;
		char title[max_title_size];
	public:
		void set(const char *famname, const char *realname, const char *btitle, long long _ISBN);
		bool isEmpty() const;
		void display() const;
	};
}



#endif
