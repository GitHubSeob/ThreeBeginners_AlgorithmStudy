//문제풀이: https://githubseob.tistory.com/90

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>value;
int answer = 1e9;
int N;

void Move(int start, int node, int cost, vector<bool>visit) {
	if (cost != 0)	visit[node] = true;
	int idx = 0;
	int visit_count = 0;

	for (idx = 0; idx < N; ++idx) {
		int next_cost = cost + value[node][idx];
		if (visit[idx]) visit_count++;
		else if (!visit[idx] && next_cost < answer && value[node][idx] != 0)
			Move(start, idx, next_cost, visit);
	}
	if (visit_count == N && node == start)
		answer = min(answer, cost);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int y = 0, x = 0;
	cin >> N;
	value = vector<vector<int>>(N, vector<int>(N, 0));
	for (y = 0; y < N; ++y)
		for (x = 0; x < N; ++x)
			cin >> value[y][x];

	vector<bool>visit(N, false);

	for (y = 0; y < N; ++y)
		Move(y, y, 0, visit);
	cout << answer;
}