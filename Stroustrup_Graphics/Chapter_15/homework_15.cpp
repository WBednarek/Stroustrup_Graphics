#include "homework_15.h"

namespace H15
{
	long long fac(int n)
	{
		return n > 1 ? n * fac(n-1) : 1;
	}

	long long fac_iter(int n)
	{
		if (n == 1) return 1;
		long long fac = n;
		while (n > 1)
		{
			fac = fac * (n - long long(1));
			--n;
		}

		return fac;
	}

	void compare_factorials(int n)
	{
		
		cout << "Factorials from 1 to 19" << endl;
		cout <<"Base\t" << setw(6) << "Recurency method" << setw(30) << "Iteration method" << endl;
		for (int i = 0; i < n; ++i)
		{
			cout << i << ":\t" <<setw(10)<< fac(i) << setw(30) << fac_iter(i) << endl;
		}
	}

	int homework()
	{
		const int MAX_FCT = 21;
		compare_factorials(MAX_FCT);
		

		return 0;
	}
}