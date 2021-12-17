#ifndef SICT_DATA_H
#define SICT_DATA_H
#include <iostream>
#include <cstring>

using namespace std;

namespace sict
{
	const int COLUMN_WIDTH = 15;

	template <typename T>
	T max(const T* data, int n)
	{
		T maxElement = data[0];

		for (int i = 0; i < n; i++)
		{
			if (data[i] > maxElement)
			{
				maxElement = data[i];
			}
		}
		return maxElement;
	}

	template <typename T>
	T min(const T* data, int n)
	{
		T minElement = data[0];

		for (int i = 0; i < n; i++)
		{
			if (data[i] < minElement)
			{
				minElement = data[i];
			}
		}
		return minElement;
	}

	template <typename T>
	T sum(const T* data, int n)
	{
		T TotalSum = 0;

		for (int i = 0; i < n; i++)
		{
			TotalSum += data[i];
		}
		return TotalSum;
	}

	template <typename T>
	double average(const T* data, int n)
	{
		T avg = sum(data, n) / n;

		return avg;
	}

	template <typename T>
	bool read(std::istream& input, T* data, int n)
	{
		for (int i = 0; i < n; i++)
		{
			input.ignore();
			input >> data[i];
			if (input.fail())
			{
				return false;
			}
		}
		return true;
	}

	template <typename T>
	void display(const char* name, const T* data, int n)
	{
		std::cout.width(20);
		std::cout.setf(ios::right);
		std::cout << name;

		for (int i = 0; i < n; i++)
		{
			std::cout.width(COLUMN_WIDTH);
			std::cout << data[i];
		}
		std::cout << std::endl;
	}

	template <typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n)
	{
		char rowname[2000];
		bool ok = !input.bad();

		if (ok)
		{
			input.get(rowname, 2000, ',');

			if (std::strcmp(rowname, name) != 0)
			{
				std::cout << "Cannot parse for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)

			ok = read(input, data, n);
		input.ignore(2000, '\n');
		return ok;
	}

	
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);


};

#endif // !SICT_DATA_H
