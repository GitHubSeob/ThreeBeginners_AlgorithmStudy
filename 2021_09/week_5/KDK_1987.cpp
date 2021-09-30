#include<iostream>
#include<math.h>
using namespace std;
int R, C;
char alpha[21][21];
bool check[26];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int top = 0;

void dfs(int a, int b, int cnt) {
	top = max(top, cnt);
	for (int i = 0; i < 4; i++) {
		int nx = a + dx[i];
		int ny = b + dy[i];

		if (nx <= 0 || ny <= 0 || nx > R || ny > C)continue;

		if (!check[alpha[nx][ny] - 'A']) {
			check[alpha[nx][ny] - 'A'] = true;
			dfs(nx, ny, cnt + 1);
			check[alpha[nx][ny] - 'A'] = false;
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> alpha[i][j];
		}
	}
	check[alpha[1][1] - 'A'] = true;
	dfs(1, 1, 1);

	cout << top;
}