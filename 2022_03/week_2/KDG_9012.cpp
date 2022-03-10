#include <iostream>
#include <stack>
#include<string>
using namespace std;
int main() {
	string s;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		stack<char> st;
		stack<char> st2;

		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')st.push(s[i]);
			else if (s[i] == ')') {
				st2.push(s[i]);
				if (st.empty()) break;
				st.pop();
				st2.pop();
			}
		}
		if (st.empty() && st2.empty())cout << "YES" << '\n';
		else if (!st.empty() || !st2.empty())cout << "NO" << '\n';
	}
}