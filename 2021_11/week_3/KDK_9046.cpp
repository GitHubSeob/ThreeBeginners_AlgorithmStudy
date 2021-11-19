#include <iostream> 
#include <string> 
#include <algorithm>
using namespace std;
bool cmp(pair<int, char> a, pair<int, char> b) { return a.first > b.first; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	cin.ignore(); while (t--) {
		string s;
		getline(cin, s);
		pair<int, char> List[26] = { {0,' '} };
		for (int i = 0; i < s.length(); i++) {
			if (isspace(s[i])) continue;
			List[s[i] - 'a'] = { List[s[i] - 'a'].first + 1,s[i] };
		}
		sort(List, List + 26, cmp);
		if (List[0].first != List[1].first) {
			cout << List[0].second << '\n';
		}
		else {
			cout << '?' << '\n';
		}
	}
	return 0;
}
