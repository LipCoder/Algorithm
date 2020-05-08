/*
#include <iostream>
using namespace std;

struct TestCase
{
	int count;
	int* DNA;
};

int main()
{
	int input;
	cin >> input;

	TestCase* tc = new TestCase[input];
	
	for (int i = 0; i < input; ++i)
	{
		TestCase& t = tc[i];
		cin >> t.count;
		t.DNA = new int[t.count];
		for (int j = 0; j < t.count; ++j)
		{
			cin >> t.DNA[j];
		}
	}

	for (int i = 0; i < input; ++i)
	{

	}

	for (int i = 0; i < input; ++i)
	{
		delete[] tc[i].DNA;
	}
	delete[] tc;
}
*/

#include <iostream>
using namespace std;
#define MAX 100

int T, N;
int DNA[2][MAX];
int split_n;

void input_data()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> DNA[0][i];
	}
}

void solve()
{
	int flag = 0;
	int i, j;
	bool NotComplete = true;
	split_n = 0;

	while (NotComplete)
	{
		DNA[1 - flag][N - 2] = DNA[flag][N - 1];

		for (i = N - 4; i >= 0; i -= 2)
		{
			DNA[1 - flag][i] = DNA[flag][i + 1] - DNA[1 - flag][i + 2];
		}

		j = i + 2;
		j = 1 - j;

		DNA[1 - flag][j] = DNA[flag][0] - DNA[1 - flag][1 - j];

		for (i = j + 2; i < N; i += 2)
		{
			DNA[1 - flag][i] = DNA[flag][i - 1] - DNA[1 - flag][i - 2];
		}

		++split_n;
		flag = 1 - flag;

		for (i = 0; i < N; ++i)
		{
			cout << DNA[flag][i] << " ";

			if (DNA[flag][i] < 0)
				NotComplete = false;
		}
		cout << endl;
	}

	if (split_n == 0)
		split_n = -1;
}

void output_result()
{
	cout << "=============================================" << endl;
	cout << split_n - 1 << "È¸ ºÐÇÒ" << endl << endl;
}

int main()
{
	int i;
	cin >> T;
	for (i = 0; i < T; ++i)
	{
		input_data();
		solve();
		output_result();
	}
}