//문제풀이: https://githubseob.tistory.com/146

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
int home_size;
vector<vector<int>>dir;
int answer=999999;

void DFS(int idx, int cnt, vector<int>min_dir) {
	int idx2(0);
	if (cnt == M) {
		bool visit(true);
		int sum(0);
		for (idx2 = 0; idx2 < min_dir.size(); ++idx2) {
			if (min_dir[idx2] == 999999) {
				visit = false;
				break;
			}
			sum += min_dir[idx2];
		}
		if (visit)
			answer = min(answer, sum);		
	}
	else {
		if (idx + 1 <= dir.size()) {
			DFS(idx + 1, cnt, min_dir);
			for (idx2 = 0; idx2 < min_dir.size(); ++idx2)
				min_dir[idx2] = min(min_dir[idx2], dir[idx][idx2]);			
			DFS(idx + 1, cnt + 1, min_dir);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	int y(0), x(0);
	int idx(0), idx2(0);
	int num(0);
	vector<pair<int ,int>>home;
	vector<pair<int ,int>>chicken;
	
	for (y = 0; y < N; ++y) {
		for (x = 0; x < N; ++x) {
			cin >> num;
			if (num == 1)
				home.push_back({ y,x });
			else if (num == 2)
				chicken.push_back({ y,x });
		}
	}
	dir = vector<vector<int>>(chicken.size(), vector<int>(home.size(), 0));
	
	for (idx = 0; idx < chicken.size(); ++idx) {
		for (idx2 = 0; idx2 < home.size(); ++idx2) {
			dir[idx][idx2] = abs(chicken[idx].first - home[idx2].first) +
				abs(chicken[idx].second - home[idx2].second);
		}
	}
	
	vector<int>min_dir(home.size(), 999999);

	DFS(0, 0, min_dir);

	cout << answer;
}