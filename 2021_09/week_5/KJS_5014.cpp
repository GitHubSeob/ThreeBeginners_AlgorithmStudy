//문제풀이: https://githubseob.tistory.com/119

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<bool>visit;
int F, S, G, U, D;
vector<int>button;

void BFS() {
	queue<pair<int, int>>q;
	q.push({ S, 0 });
	visit[S] = true;
	while (!q.empty()) {
		int floor = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for (int idx = 0; idx < 2; ++idx) {
			int next_floor = floor + button[idx];
			if (next_floor == G) {
				cout << cnt + 1;
				return;
			}
			else if (next_floor >= 1 && next_floor <= F && !visit[next_floor]) {
				visit[next_floor] = true;
				q.push({ next_floor,cnt + 1 });
			}
		}
	}
	cout << "use the stairs";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> F >> S >> G >> U >> D;
	visit = vector<bool>(F + 1, false);
	button = vector<int>{ U,-D };

	if (S == G) cout << 0;
	else BFS();
}