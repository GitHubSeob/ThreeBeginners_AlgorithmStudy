//문제풀이: https://githubseob.tistory.com/174

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	map<string, double>m;
	map<string, double>::iterator iter;
	string tree;
	double tree_cnt(0);

	while (getline(cin, tree)) {
		tree_cnt++;
		m[tree]++;
	}

	cout << fixed;
	cout.precision(4);

	for (iter = m.begin(); iter != m.end(); ++iter) {
		cout << iter->first << ' ' << iter->second / tree_cnt * 100 << '\n';
	}
}