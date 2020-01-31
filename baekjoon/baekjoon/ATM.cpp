#include <iostream>
using namespace std;

int main()
{
	int personCount = 0;
	int* personTime = nullptr;
	int sum = 0;
	cin >> personCount;

	personTime = new int[personCount];

	for (int i = 0; i < personCount; ++i)
	{
		int input = 0;
		cin >> input;
		personTime[i] = input;
	}

	for (int i = 0; i < personCount; ++i)
	{
		for (int j = 0; j < personCount - 1; ++j)
		{
			if (personTime[j] > personTime[j + 1])
			{
				int temp = 0;
				temp = personTime[j];
				personTime[j] = personTime[j + 1];
				personTime[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < personCount; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			sum += personTime[j];
		}
	}

	cout << sum << endl;
}