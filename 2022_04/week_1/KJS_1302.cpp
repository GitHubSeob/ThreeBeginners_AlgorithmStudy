//문제풀이: https://githubseob.tistory.com/176

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), idx(0);
	int max_count(0);
	string title("");

	cin >> N;

	map<string, int>book;
	map<string, int>::iterator iter;

	for (idx = 0; idx < N; ++idx) {
		cin >> title;
		book[title]++;
		max_count = max(max_count, book[title]);
	}

	for (iter = book.begin(); iter != book.end(); ++iter) {
		if (iter->second == max_count) {
			cout << iter->first;
			return 0;
		}
	}
}