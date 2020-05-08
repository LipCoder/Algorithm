#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int EMPTY = 0;
const int MAX = 100 + 1;

int main()
{
	int multitabCount;
	int multitab[101] = { EMPTY, };
	int schedule[101] = { EMPTY, };
	int scheduleCount;
	vector<int> order;

	cin >> multitabCount;
	cin >> scheduleCount;
	for (int i = 0; i < scheduleCount; ++i)
	{
		cin >> schedule[i];
	}

	int result = 0;
	for (int i = 0; i < scheduleCount; ++i)
	{
		bool pluggedCheck = false;
		for (int j = 0; j < multitabCount; ++j)
		{
			if (schedule[i] == multitab[j])
			{
				pluggedCheck = true;
				break;
			}
		}
		if (pluggedCheck)
			continue;

		for (int j = 0; j < multitabCount; ++j)
		{
			if (EMPTY == multitab[j])
			{
				multitab[j] = schedule[i];
				pluggedCheck = true;
				break;
			}
		}
		if (pluggedCheck)
			continue;

		int far = -1;
		int index = 0;
		for (int j = 0; j < multitabCount; ++j)
		{
			int lastIndex = 0;
			for (int k = i + 1; k < scheduleCount; ++k)
			{
				if (schedule[k] == multitab[j])
					break;
				++lastIndex;
			}
			if (far < lastIndex)
			{
				index = j;
				far = lastIndex;
			}
		}
		++result;
		multitab[index] = schedule[i];
		
	}
	
	cout << result << endl;
}