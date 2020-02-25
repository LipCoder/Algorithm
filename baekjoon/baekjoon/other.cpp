#include <iostream>
using namespace std;

int main()
{
	cout << "10진수->16진수 변환 프로그램이다." << endl;
	cout << "10진수를 16진수로 바꾸려면 [A] 키를 누르고, " << endl
		<< "16진수를 10진수로 바꾸려면 [B] 키를 누르세요." << endl;
	cout << "a나 b를 누르세요 : ";

	char input;
	cin >> input;

	cout << "변환할 숫자를 입력하세요 : ";
	
	int num;
	switch (input)
	{
	case 'a':
		cin >> num;
		cout << "10진수 값 : " << std::dec << num << " --> ";
		cout << "16진수 값 : " << std::hex << num << endl;
		break;
	case 'b':
		cin >> std::hex >> num;
		cout << "16진수 값 : " << std::hex << num << " --> ";
		cout << "10진수 값 : " << std::dec << num << endl;
		break;
	}
}