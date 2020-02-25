#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	cin >> input;
	string temp = "";
	bool checkMinus = false;
	int result = 0;

	for (int i = 0; i <= input.size(); ++i)
	{
		if ('+' == input[i] || '-' == input[i] || '\0' == input[i])
		{
			if (true == checkMinus)
				result -= stoi(temp);
			else
				result += stoi(temp);
			temp = "";
			if ('-' == input[i])
				checkMinus = true;
			continue;
		}
		temp += input[i];
	}
	cout << result << endl;
}