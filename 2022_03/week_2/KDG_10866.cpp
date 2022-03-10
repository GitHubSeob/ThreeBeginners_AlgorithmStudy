#include<iostream>
#include<deque>
using namespace std;

int main()
{
	int N, x;
	string command;
	deque<int> dq;
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> command;

		if (command == "push_front") {
			cin >> x;
			dq.push_front(x);
		}
		else if (command == "push_back") {
			cin >> x;
			dq.push_back(x);
		}
		else if (command == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else cout << -1 << '\n';
		}
		else if (command == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else cout << -1 << '\n';
		}
		else if (command == "size") {
			cout << dq.size() << '\n';
		}
		else if (command == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (command == "front") {
			if (!dq.empty()) cout << dq.front() << '\n';
			else cout << -1 << '\n';
		}
		else if (command == "back") {
			if (!dq.empty()) cout << dq.back() << '\n';
			else cout << -1 << '\n';
		}
	}

}