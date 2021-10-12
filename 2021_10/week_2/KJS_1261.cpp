//문제풀이: https://githubseob.tistory.com/130

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>>matrix;
vector<vector<int>>visit;
vector<int> dx = { -1, 1, 0, 0 };
vector<int> dy = { 0, 0, 1, -1 };

void BFS() {
	queue<vector<int>>q;
	q.push({ 1,1,0 });
	while (!q.empty()) {
		int y = q.front()[0];
		int x = q.front()[1];
		int cnt = q.front()[2];
		q.pop();
		for (int idx = 0; idx < 4; ++idx) {
			int n_y = y + dy[idx];
			int n_x = x + dx[idx];
			if (n_y >= 1 && n_y <= N && n_x >= 1 && n_x <= M) {
				if (matrix[n_y][n_x] == 0) {
					if (visit[n_y][n_x] > cnt || visit[n_y][n_x] == -1) {
						visit[n_y][n_x] = cnt;
						q.push({ n_y,n_x,cnt });
					}
				}
				else {
					if (visit[n_y][n_x] > cnt + 1 || visit[n_y][n_x] == -1) {
						visit[n_y][n_x] = cnt + 1;
						q.push({ n_y, n_x, cnt + 1 });
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string number = "";
	int y = 0, x = 0;
	cin >> M >> N;

	matrix = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
	visit = vector<vector<int>>(N + 1, vector<int>(M + 1, -1));

	for (y = 1; y <= N; ++y) {
		cin >> number;
		for (x = 1; x <= M; ++x)
			matrix[y][x] = number[x - 1] - '0';
	}

	BFS();

	if (visit[N][M] == -1) visit[N][M] = 0;
	cout << visit[N][M];
}