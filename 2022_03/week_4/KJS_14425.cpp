//문제풀이: https://githubseob.tistory.com/169

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_map<string, int>set;
	int N(0), M(0), idx(0), answer(0);
	cin >> N >> M;

	string s;
	for (idx = 0; idx < N; ++idx) {
		cin >> s;
		set.insert({ s,1 });
	}

	for (idx = 0; idx < M; ++idx) {
		cin >> s;
		answer += set[s];
	}

	cout << answer;
}