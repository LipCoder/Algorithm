#include <iostream>
using namespace std;

int main()
{
	int num;
	char input;
	cout << "10진수->16진수 변환 프로그램이다." << endl;
	cout << "10진수를 16진수로 바꾸려면 [A] 키를 누르고, " << endl
		<< "16진수를 10진수로 바꾸려면 [B] 키를 누르세요." << endl;
	cout << "a나 b를 누르세요  : ";
	cin >> input;

	cout << "변환할 숫자를 입력하세요  : ";

	switch (input)
	{
	case 'a':
		cin >> hex >> num;
		cout << "16진수 값  : " << hex << num
			 << " --> " << "10진수 값  : " << dec << num << endl;
		break;
	case 'b':
		cin >> dec >> num;
		cout << "10진수 값  : " << dec << num
			 << " --> " << "10진수 값  : " << hex << num << endl;
		break;
	}
}