#include <iostream>
using namespace std;
const int mod = 1000000000;

int main()
{
	long long DP[101][10] = { 0, };
	
	int input;
	cin >> input;

	for (int i = 1; i <= 9; ++i)
	{
		DP[1][i] = 1;
	}
	
	for (int i = 2; i <= input; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			if (0 == j)
				DP[i][j] = DP[i - 1][j + 1] % mod;
			else if (9 == j)
				DP[i][j] = DP[i - 1][j - 1] % mod;
			else
				DP[i][j] = DP[i - 1][j + 1] + DP[i - 1][j - 1] % mod;
		}
	}

	long long sum = 0;
	for (int i = 0; i <= 9; ++i)
	{
		sum += DP[input][i];
	}

	cout << sum % mod << endl;
}