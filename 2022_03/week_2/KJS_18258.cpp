//문제풀이: https://githubseob.tistory.com/152

#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), num(0);
	string cmd("");

	cin >> N;
	
	queue<int>q;	

	while (N--) {
		cin >> cmd;
		if (cmd == "push") {			
			cin >> num;
			q.push(num);
		}
		else if (cmd == "pop") {
			if (!q.empty()) {
				cout << q.front();
				q.pop();
			}
			else cout << -1;			
		}
		else if (cmd == "size") {
			cout << q.size();			
		}
		else if (cmd == "empty") {
			cout << q.empty();
		}
		else if (cmd == "front") {
			if (!q.empty())
				cout << q.front();
			else cout << -1;			
		}
		else if (cmd == "back") {
			if (!q.empty())
				cout << q.back();
			else cout << -1;			
		}
		if (cmd != "push")
			cout << '\n';
	}
}