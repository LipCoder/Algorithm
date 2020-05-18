#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(char* num, char* symbol, int size)
{
	for (int i = 0; i < size; ++i)
	{
		switch (symbol[i])
		{
		case '>':
			if (num[i] < num[i + 1])
				return false;
			break;
		case '<':
			if (num[i] > num[i + 1])
				return false;
			break;
		}
	}

	return true;
}

int main()
{
	int input = 0;
	cin >> input;
	
	char* arr = new char[input];
	for (int i = 0; i < input; ++i)
	{
		cin >> arr[i];
	}

	char* minArr = new char[input + 1 + 1];
	char* maxArr = new char[input + 1 + 1];

	char min = '0';
	char max = '9';
	for (int i = 0; i <= input; ++i)
	{
		minArr[i] = min + i;
		maxArr[i] = max - i;
	}
	minArr[input + 1] = '\0';
	maxArr[input + 1] = '\0';

	// 최소값
	while (false == check(minArr, arr, input))
	{
		next_permutation(minArr, minArr + (input + 1));
	}

	// 최대값
	while (false == check(maxArr, arr, input))
	{
		prev_permutation(maxArr, maxArr + (input + 1));
	}

	printf("%s\n%s", maxArr, minArr);

	delete[] minArr;
	delete[] maxArr;
	delete[] arr;
}