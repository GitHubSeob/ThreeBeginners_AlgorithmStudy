//문제풀이: https://githubseob.tistory.com/153

#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), num(0);
	string cmd("");
	stack<int>s;
	cin >> N;
	while (N--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> num;
			s.push(num);
		}
		else if (cmd == "pop") {
			if (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			else cout << -1;
		}
		else if (cmd == "size")
			cout << s.size();
		else if (cmd == "empty")
			cout << s.empty();
		else if (cmd == "top") {
			if (!s.empty())
				cout << s.top();							
			else cout << -1;
		}
		if (cmd != "push")
			cout << '\n';
	}
}