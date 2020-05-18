#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void XOR(char** mat, int N, int M)
{
	for (int i = N; i < N + 3; ++i)
	{
		for (int j = M; j < M + 3; ++j)
		{
			char temp = mat[i][j];
			if ('1' == temp)
				--mat[i][j];
			else
				++mat[i][j];
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	char** A = new char*[n];
	for (int i = 0; i < n; ++i)
	{
		A[i] = new char[m + 1];
		cin >> A[i];
	}

	char** B = new char*[n];
	for (int i = 0; i < n; ++i)
	{
		B[i] = new char[m + 1];
		cin >> B[i];
	}

	int count = 0;
	bool check = true;
	if (m >= 3 && n >= 3)
	{
		for (int i = 0; i <= n - 3; ++i)
		{
			for (int j = 0; j <= m - 3; ++j)
			{
				if (A[i][j] != B[i][j])
				{
					XOR(A, i, j);
					++count;
				}
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (A[i][j] != B[i][j])
					check = false;
			}
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (A[i][j] != B[i][j])
					check = false;
			}
		}
	}

	if (false == check)
		count = -1;

	cout << count << endl;

	for (int i = 0; i < n; ++i)
	{
		delete[] A[i];
		delete[] B[i];
	}
	delete[] A;
	delete[] B;
}