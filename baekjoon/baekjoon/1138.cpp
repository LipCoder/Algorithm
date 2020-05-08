#include <iostream>
using namespace std;

const int EMPTY = 11;

int main()
{
	int person[10];
	int result[10];

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> person[i];
		result[i] = EMPTY;
	}

	for (int i = 0; i < N; ++i)
	{
		int leftCount = person[i];
		int personHeight = i + 1;

		for (int j = 0; j < N; ++j)
		{
			if (leftCount == 0 &&
				result[j] == EMPTY)
			{
				result[j] = personHeight;
				break;
			}
			else if (result[j] > personHeight)
				--leftCount;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;
}