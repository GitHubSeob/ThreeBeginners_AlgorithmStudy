#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
bool isprime(int a);
void bfs(int a, int b);
bool prime[10000];
bool visited[10000];
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int  t, start, end;
	cin >> t;

	for (int i = 0; i < t; i++) {
		memset(visited, false, sizeof(visited));
		cin >> start >> end;
		bfs(start, end);
	}

}
bool isprime(int a) {
	for (int i = 2; i <= (a / 2); i++) {
		if (a % i == 0)return false;
	}
	return true;
}

void bfs(int a, int b) {
	
	queue<pair<int, int>>q;
	visited[a] = true;
	q.push(make_pair(a, 0));
	while (!q.empty()) {
		int tmp = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (tmp == b) {
			cout << cnt << "\n";
			break;
		}
		int arr[4], copy[4];
		//여기 부분 참조. 너무 더러워서 바꿔서 함. ,continue로 거르는 것도 앞으로 써보자.
		for (int i = 0; i < 4; i++) {
			arr[i] = tmp % 10;
			copy[i] = arr[i];
			tmp = tmp / 10;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				arr[i] = j;

				int next = arr[3] * 1000 + arr[2] * 100 + arr[1] * 10 + arr[0];
				if (visited[next] == true || next == tmp || arr[3] == 0)continue;
				if (isprime(next)) {
					q.push({ next,cnt + 1 });
					visited[next] = true;
				}
			}
			arr[i] = copy[i];
		}

	}
}
