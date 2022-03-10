//문제풀이: https://githubseob.tistory.com/156

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), num(0);
	cin >> N;
	string cmd("");
	deque<int>dq;

	while (N--) {
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (cmd == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (cmd == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front();
				dq.pop_front();
			}
			else cout << -1;
		}
		else if (cmd == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back();
				dq.pop_back();
			}
			else cout << -1;
		}
		else if (cmd == "size") {
			cout << dq.size();
		}
		else if (cmd == "empty") {
			cout << dq.empty();
		}
		else if (cmd == "front") {
			if (!dq.empty()) {
				cout << dq.front();				
			}
			else cout << -1;
		}
		else if (cmd == "back") {
			if (!dq.empty()) {
				cout << dq.back();				
			}
			else cout << -1;
		}
		if (cmd.substr(0, 4) != "push")
			cout << '\n';
	}
}