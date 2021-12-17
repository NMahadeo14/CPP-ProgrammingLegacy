#include "Data.h"
#include <iostream>

namespace sict
{
	void answers(const int* year, const int* population, const int* violentCrime, const double* violentCrimeRate, const int* grandTheftAuto, const int n)
	{
		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividin    g by 1000000 would yield "6"
		int pop = population[n - 1] - population[0];

		cout << "Population change from " << year[0] << " to " << year[n - 1] << " is ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << static_cast<double>(pop) / 1000000 << " million" << endl;



		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005

		if (violentCrime[0] < violentCrime[n - 1])
		{
			cout << "Violent Crime trend is up" << endl;
		}
		else
		{
			cout << "Violent Crime trend is down" << endl;
		}


		// Q3 print the GTA number accurate to 0 decimal places
		double avg = 0.00;

		avg = average(grandTheftAuto, n);

		cout << "There are " << avg / 1000000 << " million Grand Theft Auto incidents on average a year" << endl;



		// Q4. Print the min and max violentCrime rates

		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;

	}
}