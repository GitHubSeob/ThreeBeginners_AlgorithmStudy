#include <iostream>
#include <deque>
using namespace std;

int n, m;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int maze[101][101];	 //미로 정보
int visit[101][101]; //방문 확인 및 벽을 부신 횟수

deque<pair<int, int>> q;


void bfs() {
	visit[0][0] = 0;
	q.push_back(make_pair(0, 0));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (visit[nx][ny] == -1) {
					//만약 벽이 없는 곳이면 벽을 부실 필요 없으므로
					//다음 좌표의 visit값은 현재 좌표의 visit값과 동일
					if (maze[nx][ny] == 0) {
						visit[nx][ny] = visit[x][y];
						q.push_front(make_pair(nx, ny));
					}
					//만약 벽이 있는 곳이면 벽을 부셔야 하므로
					//다음 좌표의 visit값은 현재 좌표의 visit값 + 1
					else {
						visit[nx][ny] = visit[x][y] + 1;
						q.push_back(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;
			cin >> temp;
			maze[i][j] = temp - 48;
			visit[i][j] = -1;
		}
	}    //미로에 대한 정보를 입력

	bfs();

	cout << visit[n - 1][m - 1] << "\n";
}
