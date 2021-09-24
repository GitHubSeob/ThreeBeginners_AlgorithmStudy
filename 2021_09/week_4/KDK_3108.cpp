#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 2002

int N;
int result = 0;
int check_x1, check_x2, check_y1, check_y2;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool arr[MAX][MAX];
bool visit[MAX][MAX] = { false, };
vector <int> x_sort;
vector <int> y_sort;

void DFS(int init_x, int init_y) {
	for (int i = 0; i < 4; i++) {
		int nx = init_x + dx[i];
		int ny = init_y + dy[i];

		if (nx < check_x1 || nx > check_x2 || ny < check_y1 || ny > check_y2) continue;
		if (visit[nx][ny] || !arr[nx][ny]) continue;
		visit[nx][ny] = true;
		DFS(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	memset(arr, false, sizeof(arr));
	while (N--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 = (x1 + 500) * 2; x2 = (x2 + 500) * 2;
		y1 = (y1 + 500) * 2; y2 = (y2 + 500) * 2;

		x_sort.push_back(x1); x_sort.push_back(x2);
		y_sort.push_back(y1); y_sort.push_back(y2);

		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				if ((i == x1 || i == x2) && (j >= y1 && j <= y2))
					arr[i][j] = 1;

				if ((j == y1 || j == y2) && (i >= x1 && i <= x2))
					arr[i][j] = 1;
			}
		}
	}

	sort(x_sort.begin(), x_sort.end());
	sort(y_sort.begin(), y_sort.end());

	check_x1 = x_sort[0]; check_x2 = x_sort[x_sort.size() - 1];
	check_y1 = y_sort[0]; check_y2 = y_sort[y_sort.size() - 1];

	for (int i = check_x1; i <= check_x2; i++) {
		for (int j = check_y1; j <= check_y2; j++) {
			if (!visit[i][j] && arr[i][j]) {
				result++;
				visit[i][j] = true;
				DFS(i, j);
			}
		}
	}

	if (arr[1000][1000]) result--;
	cout << result;
	return 0;
}
