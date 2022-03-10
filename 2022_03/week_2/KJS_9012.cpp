//문제풀이: https://githubseob.tistory.com/154

#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T(0), idx(0);
	cin >> T;
	
	while (T--) {
		stack<int>bracket;
		string input("");
		cin >> input;
		for (idx = 0; idx < input.size(); ++idx) {
			if (!bracket.empty() && bracket.top() == '(' && input[idx] == ')')
				bracket.pop();
			else bracket.push(input[idx]);
		}
		if (bracket.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
}