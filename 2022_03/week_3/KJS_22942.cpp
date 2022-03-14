//문제풀이: https://githubseob.tistory.com/164

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), idx(0), idx2(0);
	cin >> N;

	vector<pair<int, int>>data(N, { 0,0 });
	int x(0), r(0);

	for (idx = 0; idx < N; ++idx) {
		cin >> x >> r;
		data[idx].first = x - r;
		data[idx].second = x + r;
	}
	sort(data.begin(), data.end());

	for (idx = 0; idx + 1 < N; ++idx) {
		for (idx2 = idx + 1; idx2 < N; ++idx2) {
			if (data[idx].first == data[idx2].first) {
				if (data[idx].second != data[idx2].second) {
					cout << "NO";
					return 0;
				}
				else continue;
			}
			else if (data[idx].second < data[idx2].first) {
				break;
			}
			else if (data[idx2].second < data[idx].second) {
				continue;
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}