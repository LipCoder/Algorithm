#include <iostream>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int N, M;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	
	if (N == 1)
		cout << 1 << endl;
	else if (N == 2)
		cout << min(4, (M + 1) / 2) << endl;
	else if (M < 7)
		cout << min(4, M) << endl;
	else
		cout << M - 6 + 4 << endl;

}