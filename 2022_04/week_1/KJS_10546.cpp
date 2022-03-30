//문제풀이: https://githubseob.tistory.com/175

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), idx(0);
	cin >> N;

	unordered_map<string, int>runner;

	string name;
	for (idx = 0; idx < N; ++idx) {
		cin >> name;
		runner[name]++;
	}

	for (idx = 0; idx < N - 1; ++idx) {
		cin >> name;
		runner[name]--;
	}

	unordered_map<string, int>::iterator iter;
	for (iter = runner.begin(); iter != runner.end(); ++iter) {
		if (iter->second != 0) {
			cout << iter->first;
			return 0;
		}
	}
}