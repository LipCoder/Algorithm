#include <iostream>
using namespace std;

#define MAX 50000 * 10000

struct AppData
{
	int runTime;
	int memory;
};

struct TestCase
{
	int osMemory;
	int totalMemory;
	int* resultArray;
	int appCount;
	AppData* appData;
};

int main()
{
	int input;
	cin >> input;

	TestCase* testCases = new TestCase[input];
	for (int i = 0; i < input; ++i)
	{
		TestCase& t = testCases[i];
		cin >> t.osMemory; cin >> t.totalMemory;
		int memorySize = (t.totalMemory - t.osMemory);
		t.resultArray = new int[memorySize + 1];
		for (int j = 0; j <= memorySize; ++j)
		{
			t.resultArray[j] = MAX;
		}
		t.resultArray[0] = 0;
		cin >> t.appCount;
		t.appData = new AppData[t.appCount];
		for (int j = 0; j < t.appCount; ++j)
		{
			cin >> t.appData[j].runTime;
			cin >> t.appData[j].memory;
		}
	}

	for (int i = 0; i < input; ++i)
	{
		TestCase& t = testCases[i];
		int memorySize = (t.totalMemory - t.osMemory);
		int* result = t.resultArray;
		for (int j = 0; j < t.appCount; ++j)
		{
			AppData& app = t.appData[j];
			for (int y = 0; y <= (memorySize - app.memory); ++y)
			{
				if (result[y] + app.runTime < result[y + app.memory])
					result[y + app.memory] = result[y] + app.runTime;
			}
		}

		if (t.resultArray[memorySize] != MAX)
		{
			cout << "스마트폰의 최소 실행 시간 : ";
			cout << t.resultArray[memorySize] << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}

	for (int i = 0; i < input; ++i)
	{
		delete[] testCases[i].resultArray;
		delete[] testCases[i].appData;
	}
	delete[] testCases;
}