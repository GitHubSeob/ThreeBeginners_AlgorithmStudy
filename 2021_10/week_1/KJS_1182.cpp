//문제풀이: https://githubseob.tistory.com/126

#include <iostream>
#include <vector>
using namespace std;
int N, S;
vector<int>seq;
vector<int>visit;
int answer;

void DFS(int idx) {
	int idx2(0);
	if (idx == N - 1 && visit.size() != 0) {
		int sum(0);
		for (idx2 = 0; idx2 < visit.size(); ++idx2)
			sum += visit[idx2];
		if (sum == S) ++answer;
		return;
	}
	if (idx + 1 < N) {
		visit.push_back(seq[idx + 1]);
		DFS(idx + 1);
		visit.pop_back();
		DFS(idx + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;
	int idx(0);
	seq = vector<int>(N, 0);
	for (idx = 0; idx < N; ++idx)
		cin >> seq[idx];

	DFS(0);
	visit.push_back(seq[0]);
	DFS(0);
	cout << answer;
}