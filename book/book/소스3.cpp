#include <iostream>
using namespace std;

int foo(int A, int B, int count, int result)
{
	bool check = false;
	int min = (A < B) ? A : B;
	int resultA, resultB;
	for (int i = 2; i <= min; ++i)
	{
		if (A % i == 0 && B % i == 0)
		{
			result *= i;
			resultA = A / i;
			resultB = B / i;
			check = true;
			break;
		}
	}

	if (check)
	{
		cout << count << "회 실행한다." << endl;
		cout << "x = " << resultA << ", y = " << resultB << endl;
		return foo(resultA, resultB, ++count, result);
	}
	else
		return result;
}

int main()
{
	int A = 0, B = 0;
	cout << "2개의 수 입력" << endl;
	cout << "입력 => "; cin >> A >> B;

	cout << "최대공약수 : " << foo(A, B, 1, 1);
}