#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define VISITED 1
#define UNVISITED 0
#define CONNECTED 1

using namespace std;

// 인접행렬로 간선을 표현한것
vector<vector<int>> edge =
{
	{0, 1, 1, 0, 0, 0, 0},
	{1, 0, 0, 1, 1, 0, 0},
	{1, 0, 0, 0, 0, 0, 1},
	{0, 1, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 1, 0},
	{0, 0, 0, 1, 1, 0, 1},
	{0, 0, 1, 0, 0, 1, 0}
};

vector<int> vertices;

// 너비 우선 탐색
void BFS(int index)
{
	// 정점에 대해 방문처리를 한다.
	vertices[index] = VISITED;

	// 정점 정보를 큐에 넣는다.
	queue<int> q;
	q.push(index);
	cout << index + 1 << " ";

	// 큐가 빌때까지 반복한다.
	while (false == q.empty())
	{
		// 큐에 들어간 정점 정보 순서대로 방문이 가능한지 반복한다.
		int sub_index = q.front();
		q.pop();

		for (size_t i = 0; i < edge.size(); ++i)
		{
			// 연결되어 있고 방문한 적이 없는 정점이 있는 경우
			if (CONNECTED == edge[i][sub_index] &&
				UNVISITED == vertices[i])
			{
				cout << i + 1 << " ";
				q.push(i);

				vertices[i] = VISITED;
			}
		}
	}
}

int main()
{
	vertices = vector<int>(edge.size(), UNVISITED);
	
	// 모든 정점을 방문할 때까지 너비 우선탐색을 반복한다.
	for (size_t i = 0; i < edge.size(); ++i)
	{
		if (UNVISITED == vertices[i])
			BFS(i);
	}

	cout << endl;
}