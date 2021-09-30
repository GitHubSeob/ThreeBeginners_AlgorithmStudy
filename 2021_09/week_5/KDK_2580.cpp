/*[0][0] ~ [0][9] 까지 1~9 숫자가 들어가야함  행에서 반복
[0][0] ~[9][0] 까지 1~9 숫자가 들어가야함 열에서 반복
[3n][3n] ~[n + 2][n + 2] 까지 1~9 숫자가 들어가야함 단.0 <= n < 3 구간에서 반복*/

#include<iostream>
#include<vector>
using namespace std;
int sudoku[9][9];
int cnt = 0; //채워야할 곳에 갯수.0의갯수
bool check = false;
vector<pair<int, int>>v;
bool numcheck(int c, int d) {
	int target = sudoku[c][d];

	for (int i = 0; i < 9; i++) {
		if (target == sudoku[c][i] && i != d) return false;//행에서 반복?
		if (target == sudoku[i][d] && i != c) return false;//열에서 반복?
	}
	int p = c / 3;
	int q = d / 3;
	for (int i = p * 3; i < p * 3 + 3; i++) {
		for (int j = q * 3; j < q * 3 + 3; j++) {
			if (target == sudoku[i][j] && i != c && j != d) return false;
		}
	}//구간에서 반복
	return true;
}
void find(int t) {
	if (check) return; //결과값이 있다면?
	if (t == cnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << "\n";
		}
		check = true;
		return;
	}

	//1~9 까지 넣을게
	for (int i = 1; i <= 9; i++) {
		//선택
		auto a = v[t];
		int x = a.first;
		int y = a.second;
		//구현하기

		sudoku[x][y] = i;
		if (numcheck(x, y)) {
			find(t + 1);
		}
		sudoku[x][y] = 0;
	}
	return;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0) {
				v.push_back({ i,j });
				cnt++;
			}
		}
	}//입력하기
	find(0);
}
