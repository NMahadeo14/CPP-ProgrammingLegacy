/*
Name: Devin Mahadeo
Student number: 160611174
Email: Dmaahdeo2@myseneca.ca
Workshop: 6
Section: B
Date: March 6, 2019
*/
#include <iostream>
#include <string>
#include "Contact.h"

using namespace std;
namespace sict
{
	Contact::Contact()
	{
		m_name[0] = '\0';
		m_phone = '\0';
		m_numofPhone = 0;
	}

	bool Contact::isValid(const long long phone)
	{
		{
			long long temp = phone, temp1 = 0;
			temp1 = temp % 10000000;

			if (temp1 > 999999 && temp1 < 10000000)
			{
				temp /= 10000000;
				temp1 = temp % 1000;

				if (temp1 > 99 && temp1 < 1000)
				{
					temp /= 1000;

					if (temp > 0 && temp < 100)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}

	}

	Contact::Contact(const char* name, const long long* phone, const int numberofPhones)
	{
		

		if (name != nullptr && name[0] != '\0')
		{
			for (int i = 0; i < max_name_size; i++)
			{
				m_name[i] = name[i];
			}
		}
		else
		{
			m_name[0] = '\0';
		}
		if (phone != nullptr && numberofPhones > 0)
		{
			m_numofPhone = 0;
			m_phone = new long long[numberofPhones];
			for (int i = 0; i < numberofPhones; i++)
			{
				if (isValid(phone[i]))
				{
					m_phone[m_numofPhone] = phone[i];
					m_numofPhone++;
				}
			}
		}
		else
		{
			m_phone = nullptr;
			m_numofPhone = 0;
		}
		
	}

	Contact::~Contact()
	{
		delete[] m_phone;
		m_phone = nullptr;
	}


	bool Contact::isEmpty() const
	{
		bool valid;

		if (Contact::m_name[0] == '\0' && Contact::m_phone == nullptr && Contact::m_numofPhone == 0)
		{
			valid = false;
		}
		else
		{
			valid = true;
		}

		return valid;
		
	}

	void Contact::display() const
	{
		
		Contact temp(this->m_name, this->m_phone, this->m_numofPhone);

		if (!isEmpty())
		{
			cout << "Empty contact!" << endl;
		}
		else
		{
			cout << m_name << endl;
			temp.numDisplay(temp);

		}
	}



	void Contact::numDisplay(const Contact& temp)
	{
		int i = 0;
		int countryCode = 0;
		int areaCode = 0;
		int firstSet = 0;
		int lastSet = 0;
		
		for (i = 0; i < temp.m_numofPhone; ++i)
		{
			countryCode = temp.m_phone[i] / 10000000000;
			temp.m_phone[i] %= 10000000000;
			cout << "(+" << countryCode << ")";

			areaCode = temp.m_phone[i] / 10000000;
			temp.m_phone[i] %= 10000000;
			cout << " " << areaCode << " ";

			firstSet = temp.m_phone[i] / 10000;
			temp.m_phone[i] %= 10000;
			cout << firstSet << "-";

			lastSet = temp.m_phone[i] / 1;
			temp.m_phone[i] %= 1;
			if (lastSet > 1000)
			{
				cout << lastSet << endl;
			}
			else
			{
				cout.fill('0');
				cout.width(4);
				cout << lastSet << endl;
			}
		}





	}
}


