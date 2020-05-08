#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> sinkers;
	int max = 0;

	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;
		sinkers.push_back(input);
		max += input;
	}

	sort(sinkers.begin(), sinkers.end());
	
	if (sinkers[0] != 1)
		cout << 1 << endl;
	else
	{
		int sum = 1;
		for (int i = 1; i < N; ++i)
		{
			if (sinkers[i] > sum + 1)
				break;
			sum += sinkers[i];
		}

		cout << sum + 1 << endl;
	}
}