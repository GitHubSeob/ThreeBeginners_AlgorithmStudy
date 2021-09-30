//문제풀이: https://githubseob.tistory.com/122

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>>loc = { {-1,0},{1,0},{0,-1},{0,1} };
vector<vector<char>>board;
vector<bool>alp(26, false);
int R, C;
int answer;

void DFS(int y,int x,int cnt) {
	answer = max(answer, cnt);
	int idx(0);
	for (idx = 0; idx < 4; ++idx) {
		int n_y(y + loc[idx][0]);
		int n_x(x + loc[idx][1]);
		if (n_y >= 0 && n_y < R && n_x >= 0 && n_x < C) {
			if (!alp[board[n_y][n_x] - 65]) {
				alp[board[n_y][n_x] - 65] = true;
				DFS(n_y, n_x, cnt + 1);
				alp[board[n_y][n_x] - 65] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C;
	board = vector<vector<char>>(R, vector<char>(C, ' '));
	int y(0), x(0);
	for (y = 0; y < R; ++y)
		for (x = 0; x < C; ++x)
			cin >> board[y][x];
	
	alp[board[0][0]-65] = true;
	DFS(0,0,1);
	cout << answer;
}