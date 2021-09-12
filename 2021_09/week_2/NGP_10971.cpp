#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int arr[10][10];
bool visited[10];
int n;
int  ans = 1000000000;

void dfs(int start, int go, int sum, int cnt);

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++) {
		dfs(i, i, 0, 0);
	}
	cout << ans;
}

void dfs(int start, int go, int sum, int cnt) {
	if (visited[go] == false) {
		visited[go] = true;
		for (int i = 0; i < n; i++) {
			if (arr[go][i] != 0) {
				dfs(start, i, sum + arr[go][i], cnt + 1);
			}
		}
		visited[go] = false;
	}


	if (start == go && cnt == n) {
		ans = min(sum, ans);
	}

}