#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;

	//// 规过 1
	//vector<int> u(n + 2, 1);
	//for (int i = 0; i < reserve.size(); ++i)
	//	u[reserve[i]]++;
	//for (int i = 0; i < lost.size(); ++i)
	//	u[lost[i]]--;
	//for (int i = 1; i <= n; ++i)
	//{
	//	if (u[i - 1] == 0 && u[i] == 2)
	//		u[i - 1] = u[i] = 1;
	//	else if (u[i] == 2 && u[i + 1] == 0)
	//		u[i] = u[i + 1] = 1;
	//}
	//for (int i = 1; i <= n; ++i)
	//	if (u[i] > 0) answer++;
	// return answer;


	// 规过 2
	unordered_set<int> l(lost.begin(), lost.end());
	set<int> r;
	unordered_set<int> inter;
	for (auto& x : reserve)
	{
		if (l.find(x) == l.end()) r.insert(x);
		else inter.insert(x);
	}
	for (auto& x : inter) l.erase(x);
	for (auto& x : r)
	{
		if (l.find(x - 1) != l.end()) l.erase(x - 1);
		else if (l.find(x + 1) != l.end()) l.erase(x + 1);
	}
	return n - l.size();


	/**/

}

int main()
{
}