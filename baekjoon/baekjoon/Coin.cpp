#include <iostream>
using namespace std;

int main()
{
	int input_count = 0; 
	int price = 0;
	cin >> input_count >> price;

	int* coins = new int[input_count];
	for (int i = 0; i < input_count; ++i)
		cin >> coins[i];

	int index = input_count - 1;
	int coin_count = 0;

	while (0 < price)
	{
		if (price < coins[index])
		{
			--index;
			continue;
		}

		int times = price / coins[index];
		int rest = price % coins[index];

		coin_count += times;
		price = rest;	

		--index;
	}

	cout << coin_count << endl;
}