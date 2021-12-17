/*
Name: Devin Mahadeo
Student number: 160611174
Email: Dmahadeo2@myseneca.ca
Workshop: 6
Section: B
Date: March 6, 2019
*/
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict
{
	const int  max_name_size = 15;
	
	class Contact
	{
		char m_name[max_name_size + 1];
		long long* m_phone;
		int m_numofPhone;
		void numDisplay(const Contact& temp);
	public:
		Contact();
		Contact(const char* name, const long long* phone, const int numberofPhone);
		~Contact();
		bool isValid(const long long phone);
		bool isEmpty() const;
		void display() const;
	};

}
#endif
