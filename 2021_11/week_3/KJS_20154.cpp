#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int>cnt = { 3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1 };
	string s("");
	cin >> s;
	int idx(0);
	int sum(0);
	for (idx = 0; idx < s.size(); ++idx)
		sum += cnt[s[idx]-65];
	
	if (sum % 2 == 1) cout << "I'm a winner!";
	else cout << "You're the winner?";
}