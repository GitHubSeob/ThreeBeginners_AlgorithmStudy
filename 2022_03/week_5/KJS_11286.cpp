//문제풀이: https://githubseob.tistory.com/171

#include <iostream>
#include <queue>
using namespace std;

struct compare {
	bool operator()(int a,int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		else  return abs(a) > abs(b);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	

	int N(0), idx(0);
	int num(0);
	priority_queue<int,vector<int>,compare>pq;
	cin >> N;
	for (idx = 0; idx < N; ++idx) {
		cin >> num;
		if (!num) {
			if (pq.empty())
				cout << 0;
			else {
				cout << pq.top();
				pq.pop();
			}
			cout << '\n';
		}
		else {
			pq.push(num);
		}
	}
}