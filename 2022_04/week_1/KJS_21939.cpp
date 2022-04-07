//문제풀이: https://githubseob.tistory.com/177

#include <iostream>
#include <set>
#include <map>
using namespace std;

struct cmp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
		if (a.second == b.second)
			return a.first > b.first;

		else
			return a.second > b.second;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0);
	int idx(0);

	map<int, int>m;
	multiset<pair<int, int>, cmp>problem;
	multiset<pair<int, int>, cmp>::iterator iter;

	int number(0), level(0);
	string cmd("");

	cin >> N;

	for (idx = 0; idx < N; ++idx) {
		cin >> number >> level;
		problem.insert({ number, level });
		m.insert({ number, level });
	}

	cin >> M;

	for (idx = 0; idx < M; ++idx) {
		cin >> cmd;
		if (cmd == "recommend") {
			cin >> number;
			if (number == 1) {
				iter = problem.begin();
				cout << iter->first;
			}
			else {
				iter = --problem.end();
				cout << iter->first;
			}
			cout << '\n';
		}
		else if (cmd == "add") {
			cin >> number >> level;
			problem.insert({ number, level });
			m.insert({ number,level });
		}
		else {
			cin >> number;
			level = m[number];
			problem.erase({ number, level });
			m.erase(number);
		}
	}
}