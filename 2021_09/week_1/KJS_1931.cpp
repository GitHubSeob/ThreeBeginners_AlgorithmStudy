//문제풀이: https://githubseob.tistory.com/74

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first)
		return a.second < b.second;
	else return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	cin >> N;

	vector<pair<int, int>>time(N, { 0,0 });
	int idx = 0;
	for (idx = 0; idx < N; ++idx)
		cin >> time[idx].first >> time[idx].second;

	sort(time.begin(), time.end(), Compare);
	int back = time[0].second;
	int answer = 1;
	for (idx = 1; idx < N; ++idx) {
		if (back > time[idx].second)
			back = time[idx].second;
		else if (back <= time[idx].first) {
			answer++;
			back = time[idx].second;
		}
	}
	cout << answer;
}