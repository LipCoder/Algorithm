#include <iostream>
#include <algorithm>
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

	sort(personTime, personTime + personCount);

	int tempSum = 0;

	for (int i = 0; i < personCount; ++i)
	{
		tempSum += personTime[i];
		sum += tempSum;
	}

	cout << sum << endl;
}