#include <iostream>
using namespace std;

enum INFO
{
	A,C,G,T, INFO_END
};

int main()
{
	char dna[1000][50] = { 0, };
	int info[50][INFO_END] = { 0, };
	char resultDna[50] = { 0, };
	int resultCount = 0;

	int dnaCount, materialCount;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> dnaCount >> materialCount;

	for (int i = 0; i < dnaCount; ++i)
	{
		cin >> dna[i];
	}

	for (int i = 0; i < dnaCount; ++i)
	{
		for (int j = 0; j < materialCount; ++j)
		{
			switch (dna[i][j])
			{
			case 'A': ++info[j][A]; break;
			case 'C': ++info[j][C]; break;
			case 'G': ++info[j][G]; break;
			case 'T': ++info[j][T]; break;
			}
		}
	}

	for (int i = 0; i < materialCount; ++i)
	{
		char infoDNA = 0;
		int max = 0;
		for (int j = 0; j < INFO_END; ++j)
		{
			if (max < info[i][j])
			{
				switch (j)
				{
				case A: infoDNA = 'A'; break;
				case C: infoDNA = 'C'; break;
				case G: infoDNA = 'G'; break;
				case T: infoDNA = 'T'; break;
				}
				max = info[i][j];
			}
		}
		resultDna[i] = infoDNA;
	}

	for (int i = 0; i < dnaCount; ++i)
	{
		for (int j = 0; j < materialCount; ++j)
		{
			if (resultDna[j] != dna[i][j])
				++resultCount;
		}
	}

	cout << resultDna << "\n" << resultCount << "\n";
}