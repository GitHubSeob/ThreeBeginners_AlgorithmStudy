#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int N, x;
	string command;
	queue<int> q;
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> command;

		if (command == "push"){
			cin >> x;
			q.push(x);
		}
		else if (command == "pop"){
			if (!q.empty()){
				cout << q.front() << '\n';
				q.pop();
			}
			else cout << -1 << '\n';

		}
		else if (command == "size"){
			cout << q.size() << '\n';
		}
		else if (command == "empty"){
			cout << q.empty() << '\n';
		}
		else if (command == "front"){
			if (!q.empty()) cout << q.front() << '\n';
			else cout << -1 << '\n';
		}
		else if ( command== "back"){
			if (!q.empty()) cout << q.back() << '\n';
			else cout << -1 << '\n';
		}
	}

}