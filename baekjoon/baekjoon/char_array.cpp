#include <iostream>
#include <string>
using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;

	int min = 50;

	int diffSize = B.size() - A.size();

	for (int i = 0; i <= diffSize; ++i)
	{
		int count = 0;

		for (int j = 0; j < A.size(); ++j)
		{
			if (A[j] != B[i + j])
				++count;
		}

		if (count < min)
			min = count;
	}

	cout << min << endl;
}