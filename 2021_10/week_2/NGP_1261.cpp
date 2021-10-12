/*
bfs로 풀면 간단한 문제인듯 싶다.
다만 여기서 문이 있다면 카운트를하고 문이 없다면 카운트를 안하면 되지 않을까?
음.. 최솟값을 추출한다는것은 오른쪽혹은 아래로 내려갈때 값에 +1이 되게된다.
우리는 결국 (m-1,n-1)의 좌표를 가야하기 때문이다.
음 근데 반례를 그려봤는데 그건 아닌듯 그냥 bfs로 모든 값을 추출할때 하는게 나은듯?

음 그러니깐 모든 경로를 탐색하는데 마지막에 숫자가 낫다면 계속 값을 갱신하면 되지 않을까?
이거는 그냥 다음값이 크면 갱신시키면 되는문제..!

*/
#include<iostream>
#include<string>
#include<queue>
using namespace std;
int n, m;
int arr[101][101];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int value[101][101];
void bfs(int a, int b);
queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> m >> n;
	

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = tmp[j] - '0';
			value[i][j] = 111111111;
		}
	}

	bfs(0, 0);
	printf("%d", value[n - 1][m - 1]);

}

void bfs(int a, int b) {
	q.push(make_pair(a, b));
	value[a][b] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		//if (y == n - 1 && x == m - 1) continue; //break가 아니라 continue다 이놈아! ->그리고 굳이 이걸 왜적어 어차피 다 bfs가 끝나면 알아서 이탈하는데!!

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			
			if (arr[ny][nx] == 0) {
				if (value[ny][nx] > value[y][x]) {
					value[ny][nx] = value[y][x];
					q.push({ ny,nx });
				}
			}
			else {
				if (value[ny][nx] > value[y][x] + 1) {
					value[ny][nx] = value[y][x] + 1;
					q.push({ ny,nx });
				}
			}

		}

	}

}