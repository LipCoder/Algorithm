#include <iostream>
using namespace std;

int main()
{
	int dp[12];

	dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 11; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	int input;
	cin >> input;

	int* test_case = new int[input];
	for (int i = 0; i < input; ++i)
	{
		cin >> test_case[i];
	}

	for (int i = 0; i < input; ++i)
	{
		cout << dp[test_case[i]] << endl;
	}

	delete[] test_case;
}