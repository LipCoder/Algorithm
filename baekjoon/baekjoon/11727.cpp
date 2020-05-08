#include <iostream>
using namespace std;

int main()
{
	int input;
	cin >> input;

	int* dp = new int[input + 1];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= input; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	cout << dp[input] << endl;
}