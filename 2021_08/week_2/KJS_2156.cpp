//문제풀이: https://githubseob.tistory.com/19

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n = 0;
	int i = 0;
	cin >> n;
	vector<int>DP(n + 4, 0);
	vector<int>Arr(n + 4, 0);

	for (i = 4; i < n + 4; ++i) {
		cin >> Arr[i];
	}

	for (i = 4; i < n + 4; ++i) {
		DP[i] = DP[i - 2];
		DP[i] = max(DP[i], DP[i - 3]);
		DP[i] = max(DP[i], DP[i - 3] + Arr[i - 1]);
		DP[i] = max(DP[i], DP[i - 4] + Arr[i - 1]);
		DP[i] += Arr[i];
	}
	int answer = 0;
	for (i = 4; i < n + 4; ++i)
		answer = max(answer, DP[i]);
	cout << answer;
}