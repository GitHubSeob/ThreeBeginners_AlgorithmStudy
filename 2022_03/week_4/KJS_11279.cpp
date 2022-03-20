//문제풀이: https://githubseob.tistory.com/170

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), idx(0), num(0);
	cin >> N;

	priority_queue<int>pq;

	for (idx = 0; idx < N; ++idx) {
		cin >> num;
		if (num) {
			pq.push(num);
		}
		else {
			if (!pq.empty()) {
				cout << pq.top();
				pq.pop();
			}
			else {
				cout << 0;
			}
			cout << '\n';
		}
	}
}