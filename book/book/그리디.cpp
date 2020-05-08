#include <iostream>
using namespace std;

struct Data
{
	int runTime;
	int memory;
};

struct TestCase
{
	int osMemory;
	int totalMemory;
	int* resultArray;
	int dataCount;
	Data* data;
};

int main()
{
	int input;
	cin >> input;

	TestCase* testCases = new TestCase[input];
	for (int i = 0; i < input; ++i)
	{
		
	}
}