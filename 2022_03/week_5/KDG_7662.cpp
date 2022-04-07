#include <iostream>
#include<queue>
#include<map>


using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		priority_queue<int, vector<int> >max1; // 최대 힙
		priority_queue<int, vector<int>, greater<int> >min2; // 최소 힙
		map<int, int>m1;
		int k; cin >> k;
		for (int i = 0; i < k; i++) {
			char cmd; cin >> cmd;
			if (cmd == 'I') {
				int n; cin >> n;
				max1.push(n);
				min2.push(n);
				m1[n]++;
			} // "I"연산의 경우 걍 집어 넣기.
			else {
				int n; cin >> n;
				if (n == 1) {
					while (!max1.empty() && m1[max1.top()] == 0) max1.pop();
					if (max1.empty()) continue; //비어있을경우 무시
					else {
						int x = max1.top();
						max1.pop();
						m1[x]--;
					}
				}//1일경우? 최댓값 삭제
				else {
					while (!min2.empty() && m1[min2.top()] == 0) min2.pop();
					if (min2.empty()) continue;
					else {
						int x = min2.top();
						min2.pop();
						m1[x]--;
					}
				}
			}//반대의 경우 최소값 삭제
			while (!max1.empty() && m1[max1.top()] == 0) max1.pop();
			while (!min2.empty() && m1[min2.top()] == 0) min2.pop();

		}
		if (max1.empty()) cout << "EMPTY\n";
		else {
			cout << max1.top() << " " << min2.top() << "\n";
		}
	}
	return 0;
}