#include <iostream>
using namespace std;

int main()
{
	int maxMoney = 1000;
	int coinArr[6] = { 500, 100, 50, 10, 5, 1 };
	int change = 0;
	int changeCoinCount = 0;

	int price = 0;

	cin >> price;

	change = maxMoney - price;

	for (int i = 0; i < 6; ++i)
	{
		if (change <= 0)
			break;

		if (change >= coinArr[i])
		{
			changeCoinCount += change / coinArr[i];
			change = change % coinArr[i];
		}
	}

	cout << changeCoinCount << endl;
}