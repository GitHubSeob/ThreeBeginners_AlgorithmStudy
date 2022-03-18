//문제풀이: https://githubseob.tistory.com/166

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N(0), idx(0);
	cin >> N;

	vector<int>tower(N, 0);
	vector<int>answer(N, 0);
	stack<int>s;

	for (idx = 0; idx < N; ++idx)
		cin >> tower[idx];

	s.push({ 0 });
	for (idx = 1; idx < N; ++idx) {
		if (tower[s.top()] >= tower[idx]) {
			answer[idx] = s.top() + 1;
		}
		else {
			while (s.size() > 1) {
				s.pop();
				if (tower[s.top()] >= tower[idx]) {
					answer[idx] = s.top() + 1;
					break;
				}
			}
		}
		s.push(idx);
	}
	for (idx = 0; idx < N; ++idx)
		cout << answer[idx] << ' ';
}
