//문제풀이: https://githubseob.tistory.com/45

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K = 0, N = 0;
	cin >> K >> N;
	vector<int>lan(K, 0);
	int idx = 0;
	for (idx = 0; idx < K; ++idx)
		cin >> lan[idx];

	long long min_lan = 1;
	long long max_lan = 2147483647;

	while (min_lan <= max_lan) {
		long long mid_lan = (max_lan + min_lan) / 2;
		long long lan_cnt = 0;
		for (idx = 0; idx < K; ++idx)
			lan_cnt += (lan[idx] / mid_lan);
		if (lan_cnt < N)
			max_lan = mid_lan - 1;
		else
			min_lan = mid_lan + 1;
	}
	cout << max_lan;
}