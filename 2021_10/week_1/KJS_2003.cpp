//문제풀이: https://githubseob.tistory.com/127

#include <iostream>
#include <vector>
using namespace std;
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	int idx(0);
	int idx2(0);
	int answer(0);
	vector<int>seq(N, 0);

	for (idx = 0; idx < N; ++idx)
		cin >> seq[idx];

	for (idx = 0; idx < N; ++idx) {
		int sum(0);
		for (idx2 = idx; idx2 < N; ++idx2) {
			sum += seq[idx2];
			if (sum == M) {
				++answer;
				break;
			}
			else if (sum > M) break;
		}
	}
	cout << answer;
}