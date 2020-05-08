#include <iostream>
using namespace std;

int main()
{
	int count = 0;
	bool check = true;
	for (int i = 1; i <= 1000; ++i)
	{
		check = true;
		for (int j = 2; j < i; ++j)
		{
			if ((i % j) == 0)
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			cout << i << "\t";
			++count;
			if (count % 8 == 0)
				cout << endl;
		}
		

	}
	
	cout << "\n\ntotal : " << count << endl;
}