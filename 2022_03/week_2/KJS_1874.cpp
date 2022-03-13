//문제풀이: https://githubseob.tistory.com/161

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n(0), idx(0);
	cin >> n;

	vector<char>answer;
	vector<int>input(n, 0);
	stack<int>s;

	int num(0);

	for (idx = 0; idx < n; ++idx)
		cin >> input[idx];

	for (idx = 0; idx < n; ++idx) {
		while (s.empty() || s.top() != input[idx]) {
			if (num >= n) break;
			s.push(++num);
			answer.push_back('+');
		}
		if (s.top() == input[idx]) {
			s.pop();
			answer.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	for (idx = 0; idx < answer.size(); ++idx)
		cout << answer[idx] << '\n';
}