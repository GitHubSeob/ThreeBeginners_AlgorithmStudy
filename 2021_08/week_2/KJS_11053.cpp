//문제풀이: https://githubseob.tistory.com/17

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N = 0;
	cin >> N;
	vector<int>Arr(N, 0);
	vector<int>DP(N, 1);
	int y = 0, x = 0;
	for (x = 0; x < N; ++x) {
		cin >> Arr[x];
	}
	int answer = 0;
	for (y = 0; y < N; ++y) {
		for (x = 0; x < y;++x) {
			if (Arr[x] < Arr[y]) {
				DP[y] = max(DP[y], DP[x] + 1);
			}
		}
		answer = max(answer, DP[y]);
	}
	cout << answer;
}