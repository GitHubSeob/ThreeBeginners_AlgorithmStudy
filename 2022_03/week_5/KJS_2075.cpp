//문제풀이: https://githubseob.tistory.com/173

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int idx(0), N(0), num(0);
	priority_queue<int, vector<int>, greater<int>>pq;
	cin >> N;

	for (idx = 0; idx < N; ++idx) {
		cin >> num;
		pq.push(num);
	}
	for (idx; idx < N * N; ++idx) {
		cin >> num;
		pq.push(num);
		pq.pop();
	}

	cout << pq.top();
}