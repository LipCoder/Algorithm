#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int input;
	cin >> input;

	int* dp = new int[input + 1];
	int* num = new int[input + 1];
	memset(dp, 0, sizeof(int) * (input + 1));
	memset(num, 0, sizeof(int) * (input + 1));
	for (int i = 1; i <= input; ++i)
	{
		cin >> num[i];
	}

	int result = 0;
	for (int i = 1; i <= input; ++i)
	{
		int max = 0;
		for (int j = 0; j < i; ++j)
		{
			if (num[i] > num[j])
			{
				if (max < dp[j])
					max = dp[j];	
			}
		}
		dp[i] = max + 1;
		if (dp[i] > result)
			result = dp[i];
	}
	cout << result << endl;

	delete[] dp;
	delete[] num;
}
