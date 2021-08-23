//문제풀이: https://githubseob.tistory.com/46

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0, M = 0;
	int idx = 0;

	cin >> N >> M;
	
	vector<int>tree(N, 0);

	for (idx = 0; idx < N; ++idx)
		cin >> tree[idx];

	long long min_saw = 1;
	long long max_saw = 1000000000;
	long long tree_total = 0;

	while (min_saw <= max_saw) {
		tree_total = 0;
		long long mid_saw = (min_saw + max_saw) / 2;
		for (idx = 0; idx < N; ++idx)
			if (tree[idx] - mid_saw > 0)
				tree_total += (tree[idx] - mid_saw);
		if (tree_total < M)
			max_saw = mid_saw - 1;
		else
			min_saw = mid_saw + 1;
	}
	cout << max_saw;
}