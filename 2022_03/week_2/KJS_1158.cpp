//문제풀이: https://githubseob.tistory.com/137

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), K(0);
	int idx(0);

	cin >> N >> K;

	vector<int>number(N, 0);
	vector<int>answer;

	for (idx = 0; idx < N; ++idx)
		number[idx] = idx + 1;
	idx = -1;

	while (!number.empty()) {
		idx += K;
		if (idx >= number.size()) {
			idx %= number.size();
		}
		answer.push_back(number[idx]);
		number.erase(number.begin() + idx);
		idx--;
	}

	cout << '<';
	for (idx = 0; idx < N; ++idx) {
		cout << answer[idx];
		if (idx < N - 1) cout << ", ";
	}
	cout << '>';
}