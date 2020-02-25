#include <iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int input;
	cin >> input;

	int** tri = new int* [input];
	int** dp = new int* [input];

	for (int i = 0; i < input; ++i)
	{
		tri[i] = new int[i + 1];
		dp[i] = new int[i + 1];
		for (int j = 0; j <= i; ++j)
		{
			cin >> tri[i][j];
		}
	}

	int result = 0;
	dp[0][0] = tri[0][0];
	for (int i = 1; i < input; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + tri[i][j];
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + tri[i][j];

			// 마지막 줄의 값들 중 최대값
			if (i == (input - 1))
			{
				if (result < dp[i][j])
					result = dp[i][j];
			}
		}
	}

	cout << result << endl;

	for (int i = 0; i < input; ++i)
	{
		delete[] tri[i];
		delete[] dp[i];
	}
	delete[] tri;
	delete[] dp;
}