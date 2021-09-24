#include<iostream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
char arr[101][101], input[81];
//string input;
int dp[101][101][81];
int n, m, k, len=0, ans = 0;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int dfs(int y, int x, int loc);

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> input;
	len = strlen(input);
	memset(dp, -1, sizeof(dp));
	
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += dfs(i, j, 0);
		}
	}
	cout << ans;
}

int dfs(int y, int x, int loc) {

	if (y < 0 || x < 0 || y >= n || x >= m)
		return 0;
	if (arr[y][x] != input[loc]) 
		return dp[y][x][loc] = 0;
	if (dp[y][x][loc] != -1)
		return dp[y][x][loc];
	else
		dp[y][x][loc] = 0;

	for (int a = 0; a < 4; a++) {
		for (int b = 1; b <= k; b++) {
			int ny = y + dy[a] * b;
			int nx = x + dx[a] * b;
			if (loc + 1 == len)
				return dp[y][x][loc] = 1;
			else
				dp[y][x][loc] += dfs(ny, nx, loc + 1);
		}
	}
	return dp[y][x][loc];
}