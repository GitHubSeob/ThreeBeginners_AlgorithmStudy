#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int A, B;
char DSLR[4] = { 'D','S','L','R' };
bool visited[10001];

int change(int num, char c) {
	int res(0);
	switch (c) {
	case 'D':
		res = 2 * num;
		if (res > 9999) res %= 10000;
		break;
	case 'S':
		if (num == 0)
			res = 9999;
		else
			res = num - 1;
		break;
	case 'L':
		res = (num % 1000) * 10 + (num / 1000);
		break;
	case 'R':
		res = (num / 10) + (num % 10) * 1000;
		break;
	}
	return res;
}
void BFS(int a) {
	queue<pair<int, string>>q;
	q.push({ a,"" });
	visited[a] = true;
	while (!q.empty()) {
		int now = q.front().first;
		string nowstr = q.front().second;
		q.pop();
		if (now == B) {
			cout << nowstr << endl;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nextnum = change(now, DSLR[i]);
			if (nextnum >= 0 && nextnum < 10000 && !visited[nextnum]) {
				visited[nextnum] = true;
				q.push({ nextnum,nowstr + DSLR[i] });
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		BFS(A);
		memset(visited, false, sizeof(visited));
	}
	return 0;
}