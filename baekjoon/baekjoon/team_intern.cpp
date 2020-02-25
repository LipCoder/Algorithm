// 2명의 여학생과 1명의 남학생 <-- 팀 결성
// N명 여학생 M명의 남학생 <-- 팀 찾는중

// K명을 반드시 인턴쉽 프로그램에 참여하라는 학교의 방침 <-- 이 인원은 대회 참여 불가

// N, M, K

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int girl, boy;
	int intern;

	cin >> girl >> boy >> intern;

	int maxTeam = 0;

	int tGirl = girl;
	int tBoy = boy;

	while (true)
	{
		tGirl -= 2;
		tBoy -= 1;

		if (0 > tGirl || 0 > tBoy)
			break;
		
		++maxTeam;
	}

	intern -= (girl + boy) - (3 * maxTeam);
	
	int notTeam = 0;
	if (0 < intern)
	{
		notTeam = intern / 3;
		if (0 != intern % 3)
			++notTeam;
	}

	maxTeam -= notTeam;

	cout << maxTeam << endl;
}