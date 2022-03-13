//문제풀이: https://githubseob.tistory.com/158

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T(0), N(0), M(0);
	cin >> T;
	int num(0), idx(0);

	while (T--) {
		cin >> N >> M;
		vector<int>priority(N, 0);
		queue<pair<int, int>>q;

		for (idx = 0; idx < N; ++idx) {
			cin >> priority[idx];
			q.push({ idx,priority[idx] });
		}

		sort(priority.begin(), priority.end(), greater<>());

		idx = 0;

		while (1) {
			if (q.front().second == priority[idx]) {
				if (q.front().first == M) {
					cout << idx + 1 << '\n';
					break;
				}
				else {
					q.pop();
					++idx;
				}
			}
			else {
				q.push({ q.front().first,q.front().second });
				q.pop();
			}
		}
	}
}