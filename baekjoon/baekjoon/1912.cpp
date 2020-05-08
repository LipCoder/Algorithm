#include <iostream>
using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	int input = 0;
	cin >> input;

	int* dp = new int[input + 1];
	int* num = new int[input + 1];

	dp[0] = 0;
	num[0] = 0;
	for (int i = 1; i <= input; ++i)
	{
		cin >> num[i];
		dp[i] = 0;
	}

	int result = -1000;
	for (int i = 1; i <= input; ++i)
	{
		dp[i] = max(num[i], num[i] + dp[i - 1]);
		if (result < dp[i])
			result = dp[i];
	}

	cout << result << endl;
	delete[] dp;
	delete[] num;
}