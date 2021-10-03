#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int f, s, g, u, d;
bool visited[1000002];
int ans[1000002];
int bfs(int tmp);

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> f >> s >> g >> u >> d;
	memset(visited, false, sizeof(visited));
	memset(ans, 0, sizeof(ans));

	int value = bfs(s);
	if (value == -1)
		cout << "use the stairs" << "\n";
	else
		cout << value << "\n";
}

int bfs(int tmp) {
	queue<int> q;
	q.push(tmp);
	visited[tmp] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == g)
			return ans[now];

		int next[2] = { now + u,now - d };
		for (int i = 0; i < 2; i++) {
			if ( 1 <= next[i] && next[i] <= f) {
				if (visited[next[i]] == false) {
					visited[next[i]] = true;
					ans[next[i]] = ans[now] + 1;
					q.push(next[i]);
				}
			}
		}
	}
	return -1;
}