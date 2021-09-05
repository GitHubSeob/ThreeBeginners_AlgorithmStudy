//문제풀이: https://githubseob.tistory.com/75

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	int idx = 0;
	int acc = 0;
	int answer = 0;

	cin >> N;
	vector<int>time(N, 0);

	for (idx = 0; idx < N; ++idx)
		cin >> time[idx];
	sort(time.begin(), time.end());

	for (idx = 0; idx < N; ++idx) {
		acc += time[idx];
		answer += acc;
	}
	cout << answer;
}