//문제풀이: https://githubseob.tistory.com/111

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

vector<bool>prime;

void BFS(int start, string target, vector<bool>visit) {
	int idx = 0;
	int idx2 = 0;
	queue<pair<int, int>>q;
	q.push({ start,0 });
	visit[start] = true;
	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (idx = 0; idx < 4; ++idx) {
			for (idx2 = 0; idx2 <= 9; ++idx2) {
				string s_num = to_string(num);
				s_num[idx] = (char)(idx2 + 48);
				if (s_num == target) {
					cout << cnt + 1 << '\n';
					return;
				}
				else {
					int n_num = stoi(s_num);
					if (n_num / 1000 != 0 && !visit[n_num] && prime[n_num]) {
						visit[n_num] = true;
						q.push({ n_num, cnt + 1 });
					}
				}
			}
		}
	}
	cout << "Impossible" << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 0;
	cin >> T;

	int idx = 0;
	prime = vector<bool>(10000, true);
	int num = 2;

	for (num = 2; num <= 100; ++num) {
		for (idx = 1000 / num; num * idx < 10000; ++idx)
			prime[idx * num] = false;
	}
	vector<bool>visit(10000, false);

	while (T--) {
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		if (num1 == num2) cout << "0\n";
		else
			BFS(num1, to_string(num2), visit);
	}
}