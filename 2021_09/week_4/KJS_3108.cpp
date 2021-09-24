//문제풀이: https://githubseob.tistory.com/118

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>loc = { {-1,0},{1,0},{0,-1},{0,1} };
vector<vector<bool>>board(2001, vector<bool>(2001, false));

void DFS(int y, int x) {
	board[y][x] = false;
	int idx = 0;
	for (idx = 0; idx < 4; ++idx) {
		int n_y = y + loc[idx][0];
		int n_x = x + loc[idx][1];
		if (n_y >= 0 && n_y <= 2000 && n_x >= 0 && n_x <= 2000)
			if (board[n_y][n_x]) DFS(n_y, n_x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	int idx = 0;
	cin >> N;
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	int y = 0, x = 0;

	for (idx = 0; idx < N; ++idx) {
		cin >> x1 >> y1 >> x2 >> y2;

		x1 = (x1 + 500) * 2;
		x2 = (x2 + 500) * 2;
		y1 = (y1 + 500) * 2;
		y2 = (y2 + 500) * 2;

		for (x = x1; x <= x2; ++x) {
			board[y1][x] = true;
			board[y2][x] = true;
		}
		for (y = y1; y <= y2; ++y) {
			board[y][x1] = true;
			board[y][x2] = true;
		}
	}

	int answer = 0;

	if (board[1000][1000] == 1) answer = -1;
	for (y = 0; y <= 2000; ++y) {
		for (x = 0; x <= 2000; ++x) {
			if (board[y][x]) {
				++answer;
				DFS(y, x);
			}
		}
	}
	cout << answer;
}