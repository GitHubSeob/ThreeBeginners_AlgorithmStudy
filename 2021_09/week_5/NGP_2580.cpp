/*
모든 함수에 숫자가 채워지면 즉, 숫자가 채워진것이 81이상이면 함수를 이탈하여 종료한다.
1. 행에서 숫자가 다 다른지 판별
2. 열에서 숫자가 다 다른지 판별
3. 3*3사각형에서 숫자들이 다 다른지 판별.
위의 세가지를 충족하면 숫자를 대입시키고 cnt==81이 된다면 종료가 된다.
모든 함수의 위치에 1,2,3번을 모두 확인하후 넣어준다.
결국 1,2,3의 숫자가 겹치는것이 없는게 판별이 된다면 다음 dfs(cnt+1)을 재귀로 진행해준다.

행[행][열값들]
열[열][행값들]
사각형[사각형 범위][값들]

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[10][10];
bool row[10][10]; //행 맞추기
bool col[10][10]; //열 맞추기
bool square[10][10]; //3*3 직사각형 맞추기
void dfs(int cnt);


int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				row[i][arr[i][j]] = true;
				col[j][arr[i][j]] = true;
				square[(i / 3) * 3 + (j / 3)][arr[i][j]] = true;
			}
		}
	}

	dfs(0);

	return 0;
}

void dfs(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	int y = cnt / 9;
	int x = cnt % 9;

	if (arr[y][x] != 0)
		dfs(cnt + 1);
	else {
		for (int i = 1; i <= 9; i++) { //야이 자식아 여기서 숫자가 1~9인데 왜 i=0으로 하냐.. 정신차리자.
			if (row[y][i] == false && col[x][i] == false && square[(y/3)*3+(x/3)][i] == false) {
				row[y][i] = true;
				col[x][i] = true;
				square[(y / 3) * 3 + (x / 3)][i] = true;
				arr[y][x] = i;
				dfs(cnt + 1);
				arr[y][x] = 0;
				row[y][i] = false;
				col[x][i] = false;
				square[(y / 3) * 3 + (x / 3)][i] = false;

			}
		}
	}

}