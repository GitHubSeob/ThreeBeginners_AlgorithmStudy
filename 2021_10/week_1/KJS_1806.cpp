//문제풀이: https://githubseob.tistory.com/128

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N(0), S(0);	
	cin >> N >> S;

	int idx(0),idx2(0);	

	vector<int>seq(N + 1, 0);
	for (idx = 0; idx < N; ++idx)
		cin >> seq[idx];

	idx = 0;
	int sum(0);
	int answer(100001);

	while (idx2 < seq.size()) {
		if (sum >= S) {
			answer = min(answer, idx2 - idx);
			sum -= seq[idx];
			++idx;
		}
		else if (sum < S) {
			sum += seq[idx2];
			++idx2;
		}
	}
	if (answer == 100001) answer = 0;
	cout << answer;
}
