#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int ans;
int n, k;
bool visited[100001];
int solve(int n, int k, int ans);

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	memset(visited, false, sizeof(visited));
	cin >> n >> k;
	if (n >= k)
		cout << n - k;
	else
		cout << solve(n, k, 0);
	return 0;
}

int solve(int n, int k, int ans) {
	queue<pair<int, int>>q;
	q.push({ n,ans });

	while (!q.empty()) {
		n = q.front().first;
		ans = q.front().second;
		q.pop();

		if (n == k)
			return ans;
		if (2 * n <= 100000 && visited[2 * n] == false) {
			q.push({ 2 * n,ans + 1 });
			visited[2 * n] = true;
		}
		if (n < k && visited[n + 1] == false) {
			q.push({ n + 1,ans + 1 });
			visited[n + 1] = true;
		}
		if (n > 0 && visited[n - 1] == false) {
			q.push({ n - 1,ans + 1 });
			visited[n - 1] = true;
		}
	}
}