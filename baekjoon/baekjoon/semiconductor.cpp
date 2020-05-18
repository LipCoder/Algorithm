#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 40000;

int N;
int connect[MAX + 1];
int cache[MAX + 1];

int portLIS(void)
{
	// �ʱⰪ
	cache[1] = connect[1];
	int length = 1;
	for (int i = 2; i <= N; ++i)
	{
		if (cache[length] < connect[i])
		{
			cache[++length] = connect[i];
			continue;
		}
		int idx = lower_bound(cache + 1, cache + length + 1, connect[i]) - cache;
		cache[idx] = connect[i];
	}
	return length;
}

int main()
{
	cin >> N;

	for (int i = 0; i <= N; ++i)
		cin >> connect[i];

	cout << portLIS() << endl;
	
}