#include <iostream>
#include <string.h>
using namespace std;

int tri[501][501];
int dp[501][501];
int input;

int max(int a, int b)
{
	return a > b ? a : b;
}

int Sum(int stage, int index)
{
	int& result = dp[stage][index];
	if (result != -1)
		return result;
	if (stage == (input - 1))
		return result = tri[stage][index];
	return result = max(Sum(stage + 1, index), Sum(stage + 1, index + 1)) + tri[stage][index];
}

int main()
{
	memset(dp, -1, sizeof(int) * 501 * 501);

	cin >> input;

	for (int i = 0; i < input; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cin >> tri[i][j];
		}
	}

	cout << Sum(0, 0) << endl;
}