#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> leakPos;

	int leakCount;
	int tapeLength;
	cin >> leakCount >> tapeLength;
	leakPos.resize(leakCount);

	for (int i = 0; i < leakCount; ++i)
	{
		cin >> leakPos[i];
	}

	sort(leakPos.begin(), leakPos.end());

	int tapeCount = 1;
	int start = leakPos[0];
	for (int i = 1; i < leakCount; ++i)
	{
		if (tapeLength - 1 < leakPos[i] - start)
		{
			++tapeCount;
			start = leakPos[i];
		}
	}

	cout << tapeCount << endl;
}