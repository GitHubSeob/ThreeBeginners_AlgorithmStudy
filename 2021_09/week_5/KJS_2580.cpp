//문제풀이: https://githubseob.tistory.com/121

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>board(9, vector<int>(9, 0));
vector<bool>number(10, false);
vector<pair<int, int>>zero;

void check(int y, int x, int idx) {
	int num(0);
	int row(0), col(0);
	for (num = 1; num <= 9; ++num) {
		board[y][x] = num;
		for (row = 0; row < 9; ++row)
			if (board[y][row] == num && row != x) {
				board[y][x] = 0;
				break;
			}
		for (col = 0; col < 9; ++col)
			if (board[col][x] == num && col != y) {
				board[y][x] = 0;
				break;
			}
		for (col = y / 3 * 3; col < y / 3 * 3 + 3; ++col)
			for (row = x / 3 * 3; row < x / 3 * 3 + 3; ++row)
				if (board[col][row] == num && col != y && row != x) {
					board[y][x] = 0;
					break;
				}

		if (board[y][x] != 0) {
			if (idx == zero.size() - 1) {
				for (col = 0; col < 9; ++col) {
					for (row = 0; row < 9; ++row)
						cout << board[col][row] << ' ';
					cout << '\n';
				}
				exit(0);
			}
			else check(zero[idx + 1].first, zero[idx + 1].second, idx + 1);
		}
	}	
	board[y][x] = 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int y(0), x(0);

	for (y = 0; y < 9; ++y)
		for (x = 0; x < 9; ++x) {
			cin >> board[y][x];
			if (board[y][x] == 0)
				zero.push_back({ y,x });
		}

	check(zero[0].first, zero[0].second, 0);
}