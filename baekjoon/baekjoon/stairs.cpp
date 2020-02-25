#include <iostream>
using namespace std;

int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	int input;
	cin >> input;

	int* stairs = new int[input];
	int* dp = new int[input];
	for (int i = 0; i < input; ++i)
	{
		cin >> stairs[i];
	}

	// 한가지 경우
	dp[0] = stairs[0];
	// 한번씩 올라간 경우, 두번 올라간 경우
	dp[1] = max((stairs[0] + stairs[1]), stairs[1]);
	// 한번 올라가고 두번 올라간 경우, 두번 올라가고 한번 올라간 경우
	dp[2] = max((stairs[0] + stairs[2]), (stairs[1] + stairs[2]));

	for (int i = 3; i < input; ++i)
	{
		dp[i] = max(dp[i - 2] + stairs[i], stairs[i - 1] + stairs[i] + dp[i - 3]);
	}

	cout << dp[input - 1] << endl;
	delete[] stairs;
	delete[] dp;
}