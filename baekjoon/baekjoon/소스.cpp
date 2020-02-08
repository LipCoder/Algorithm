#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a < b;
}

int main()
{
	int input;
	cin >> input;

	int* arr = new int[input];

	int maxLength = 0;
	int maxWeight = 0;

	for (int i = 0; i < input; ++i)
	{
		cin >> arr[i];
	}

	// 크기 순으로 오름차순 정렬한다.
	sort(arr, arr + input, cmp);

	for (int i = 0; i < input; ++i)
	{
		maxLength = arr[i];

		// 최대 중량을 구한다.
		if(maxWeight < (input - i) * maxLength)
			maxWeight = (input - i) * maxLength;
	}

	cout << maxWeight << endl;
	delete[] arr;
}