#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int input = 0;
	cin >> input;

	vector<int> vt;
	vt.push_back(0);
	int* list = new int[input + 1];
	list[0] = 0;
	for (int i = 1; i <= input; ++i)
	{
		cin >> list[i];
	}

	int max = 0;
	for (int i = 1; i <= input; ++i)
	{
		int length = 0;
		if (vt.back() < list[i])
		{
			length = (vt.size() - 1) + 1;
			vt.push_back(list[i]);
		}
		else
		{
			auto iter = lower_bound(vt.begin(), vt.end(), list[i]);
			int dist = distance(vt.begin(), iter);
			length = (dist - 1) + 1;
			vt[dist] = list[i];
		}
		if (max < length)
			max = length;
	}

	cout << max << endl;
	delete[] list;
}