//문제풀이: https://githubseob.tistory.com/162

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N(0), idx(0), num(0);
	cin >> N;
	vector<pair<int, int>>balloon(N, { 0,0 });

	for (idx = 0; idx < N; ++idx) {
		cin >> balloon[idx].first;
		balloon[idx].second = idx + 1;
	}
	idx = 0;


	while (balloon.size() > 1) {
		cout << balloon[idx].second << ' ';
		num = balloon[idx].first;
		balloon.erase(balloon.begin() + idx);

		if (num > 0) {
			num = (num - 1) % balloon.size();
			idx = (idx + num) % balloon.size();
		}
		else {
			num %= (int)balloon.size();
			idx += num;
			if (idx < 0) {
				idx += balloon.size();
			}
			idx %= balloon.size();
		}
	}
	cout << balloon[0].second;
}