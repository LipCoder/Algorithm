#include <iostream>
using namespace std;

int max(const int& a, const int& b, const int& c)
{
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int main()
{
	int input = 0;
	cin >> input;

	int* wines = new int[input + 1];
	int* dp = new int[input + 1];
	for (int i = 1; i <= input; ++i)
	{
		cin >> wines[i];
		dp[i] = 0;
	}

	dp[0] = 0;
	dp[1] = wines[1];
	if (input > 1)
	{
		dp[2] = wines[1] + wines[2];
	}
	if (input > 2)
	{
		for (int i = 3; i <= input; ++i)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + wines[i], dp[i - 3] + wines[i - 1] + wines[i]);
		}
	}

	cout << dp[input] << endl;
	delete[] wines;
	delete[] dp;
}