//문제풀이: https://githubseob.tistory.com/70

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0, K = 0;
	cin >> N >> K;

	vector<int>coin(N + 1, 0);

	int idx = 0;
	for (idx = 0; idx < N; ++idx)
		cin >> coin[idx];

	int won_min = 100000000;

	for (idx = N - 1; idx >= 0; --idx) {
		int won = K;
		int won_cnt = 0;
		int temp = idx;
		while (won > 0 && temp >= 0) {
			if (won >= coin[temp]) {
				won_cnt += (won / coin[temp]);
				won %= coin[temp];
			}
			else temp--;
			if (won_cnt >= won_min) break;
		}
		if (won == 0) won_min = min(won_min, won_cnt);
	}
	cout << won_min;
}