//문제풀이: https://githubseob.tistory.com/129

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N(0);
	cin >> N;

	vector<bool>prime(N + 1, true);
	int idx(0);
	int idx2(0);
	for (idx = 2; idx * idx <= N; ++idx)
		for (idx2 = idx; idx * idx2 <= N; ++idx2)
			prime[idx * idx2] = false;
		
	vector<int>seq;
	for (idx = 2; idx <= N; ++idx)
		if (prime[idx]) seq.push_back(idx);
	seq.push_back(0);

	int answer(0);

	idx = 0;
	idx2 = 0;
	int sum(0);
	while (idx2<seq.size()) {		
		if (sum >= N) {
			if(sum==N)
			++answer;
			sum -= seq[idx];
			++idx;
		}
		else {
			sum += seq[idx2];
			++idx2;
		}
	}
	cout << answer;
}