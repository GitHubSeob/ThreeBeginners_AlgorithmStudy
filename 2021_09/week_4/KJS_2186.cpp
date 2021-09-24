//문제풀이: https://githubseob.tistory.com/116

#include <iostream>
#include <vector>
using namespace std;
int N, M, K;
string answer;
vector<vector<char>>board;
vector<vector<vector<int>>>DP;
vector<vector<int>>loc = { {-1,0},{1,0},{0,-1},{0,1} };

int DFS(int y, int x, string word, int word_loc) {
	int idx = 0;
	int idx2 = 0;
	if (word == answer)	return 1;
	else if (DP[y][x][word_loc] != -1) return DP[y][x][word_loc];
	else {
		DP[y][x][word_loc] = 0;
		for (idx = 0; idx < 4; ++idx)
			for (idx2 = 1; idx2 <= K; ++idx2) {
				int n_y = y + idx2 * loc[idx][0];
				int n_x = x + idx2 * loc[idx][1];
				if (n_y >= 0 && n_y < N && n_x >= 0 && n_x < M) {
					if (answer[word_loc + 1] == board[n_y][n_x]) {
						DP[y][x][word_loc] += DFS(n_y, n_x, word + board[n_y][n_x], word_loc + 1);
					}
				}
			}
	}
	return DP[y][x][word_loc];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int y = 0, x = 0;
	cin >> N >> M >> K;
	board = vector<vector<char>>(N, vector<char>(M, ' '));
	DP = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(80, -1)));
	for (y = 0; y < N; ++y)
		for (x = 0; x < M; ++x)
			cin >> board[y][x];

	cin >> answer;
	string first = "";
	first = answer[0];
	int ret = 0;
	for (y = 0; y < N; ++y)
		for (x = 0; x < M; ++x)
			if (board[y][x] == answer[0])
				ret += DFS(y, x, first, 0);

	cout << ret;
}