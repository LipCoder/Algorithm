#include <iostream>
using namespace std;

int main()
{
	bool check = false;
	int num = 5;
	int count = num - 1;
	for (int i = 1; i <= 25; ++i)
	{
		if (!check)
		{
			cout << i << "\t";
		}
		else
		{
			cout << i + count << "\t";
			count -= 2;
		}

		if (i % num == 0)
		{
			if (check) check = false;
			else check = true;
			count = num - 1;
			cout << endl;
		}
	}
}