#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n(0);
	cin >> n;
	priority_queue <int> pq;//우선순위 q
	while (n--) {
		int idx(0);
		cin >> idx;
		if (idx == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(idx);
		}
	}
}