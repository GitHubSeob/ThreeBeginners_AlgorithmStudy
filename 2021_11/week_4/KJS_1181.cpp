#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt(0);
	int idx(0);
	cin >> cnt;
	vector<string>word(cnt, "");
	for (idx = 0; idx < cnt; ++idx)
		cin >> word[idx];
	sort(word.begin(), word.end());	
	for (idx = 0; idx < cnt; ++idx) {
		if (idx >= 1 && word[idx] != word[idx - 1]||idx==0)
			cout << word[idx] << '\n';
	}
}