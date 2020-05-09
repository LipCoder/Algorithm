#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	for (auto& i : scoville) q.push(i);
	while (true)
	{
		int min_1 = q.top(); q.pop();
		if (min_1 >= K) break;
		else if (q.empty()) 
		{
			answer = -1;
			break;
		}
		int min_2 = q.top(); q.pop();
		q.push(min_1 + 2 * min_2);
		++answer;
	}
	return answer;
}