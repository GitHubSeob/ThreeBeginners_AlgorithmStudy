#include<iostream>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
void bfs(int a,int b);
bool visited[10000];

int main() {
	ios_base::sync_with_stdio(false);

	int t, start, finish;
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(visited, false, sizeof(visited));
		cin >> start >> finish;

		bfs(start,finish);
	}


}

void bfs(int a,int b) {
	queue<pair<int, string>> q;
	q.push(make_pair(a, ""));
	visited[a] = true;
	
	while (!q.empty()) {
		int x = q.front().first;
		string y = q.front().second;
		q.pop();

		if (x == b) {
			cout << y << endl;
			break;
		}
		

		int tmp = (2 * x) % 10000;
		if (visited[tmp]==false) {
			visited[tmp] = true;
			q.push(make_pair(tmp, y + "D"));
		}
		
		//if (x - 1 < 0) {tmp = 9999;}else tmp = x - 1;
		tmp = x - 1 < 0 ? 9999 : x - 1;
		if (visited[tmp]==false) {
			visited[tmp] = true;
			q.push(make_pair(tmp, y + "S"));
		}

		tmp = (x % 1000) * 10 + (x / 1000);
		if (visited[tmp]==false) {
			visited[tmp] = true;
			q.push(make_pair(tmp, y + "L"));
		}

		tmp = (x % 10) * 1000 + (x / 10);
		if (visited[tmp]==false) {
			visited[tmp] = true;
			q.push(make_pair(tmp, y + "R"));
		}
	}

}