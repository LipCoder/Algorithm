#include <iostream>
using namespace std;

class DATA
{
public:
	int call_zero = 0;
	int call_one = 0;

	DATA operator+(DATA& other)
	{
		DATA temp;
		temp.call_zero = call_zero + other.call_zero;
		temp.call_one = call_one + other.call_one;
		return temp;
	}
	void operator=(DATA other)
	{
		call_zero = other.call_zero;
		call_one = other.call_one;
	}
};

int main()
{
	DATA dp[40 + 1];
	dp[0].call_zero = 1;
	dp[1].call_one = 1;

	for (int i = 2; i <= 40; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int input;
	cin >> input;

	int* list = new int[input];
	for (int i = 0; i < input; ++i)
	{
		cin >> list[i];
	}

	for (int i = 0; i < input; ++i)
	{
		DATA& d = dp[list[i]];
		cout << d.call_zero << " " << d.call_one << endl;
	}
	delete[] list;
}