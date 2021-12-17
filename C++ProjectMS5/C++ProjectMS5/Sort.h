#ifndef SICT_SORT_H
#define SICT_SORT_H
#include <iostream>
#include "AmaApp.h"

namespace sict
{

	template<typename T>
	void sort(T Arry[], int size)
	{
		int i, j;
		T temp;

		for (i = 0; i < size - 1; i++)
		{
			for (j = 0; j < size - i - 1; j++)
			{
				if (*Arry[j] > *Arry[j + 1])
				{
					temp = Arry[j];
					Arry[j] = Arry[j + 1];
					Arry[j + 1] = temp;
				}
			}
		}
	}

}

#endif 

