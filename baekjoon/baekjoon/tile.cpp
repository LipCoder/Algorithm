#include <iostream>
using namespace std;

int main()
{
	int dp[1000 + 1];
	int input;
	cin >> input;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= input; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]);
	}
	cout << dp[input] << endl;
}