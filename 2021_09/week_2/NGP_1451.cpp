#include<iostream>
using namespace std;
int arr[101][101];
long long sum(int starty, int startx, int endy, int endx);
long long get_max(long a, long b) { return a > b ? a : b; }
long long ans = 0;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n, m;
	long long s1, s2, s3;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string num = "";
		cin >> num;
		for (int j = 0; j < m; j++) {
			arr[i][j] = num[j] - '0';
		}
	}
	
	//1)가로가로가로, 2)세로세로세로, 3)위쪽가로1세로2,4)아래가로1세로2, 5)왼쪽세로1가로2, 6)오른쪽세로1가로2
	for (int i = 0; i < m - 2; i++) {
		for (int j = i + 1; j < m - 1; j++) {
			s1 = sum(0, 0, n - 1, i);
			s2 = sum(0, i + 1, n - 1, j);
			s3 = sum(0, j + 1, n - 1, m - 1);
			ans = get_max(ans, s1 * s2 * s3);
		}
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			s1 = sum(0, 0, i, m - 1);
			s2 = sum(i + 1, 0, j, m - 1);
			s3 = sum(j + 1, 0, n - 1, m - 1);
			ans = get_max(ans, s1 * s2 * s3);
		}
	}
	
	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < n - 1; j++) {
			s1 = sum(0, i, n - 1, m - 1);
			s2 = sum(0, 0, j, i - 1);
			s3 = sum(j + 1, 0, n - 1, i - 1);
			ans = get_max(ans, s1 * s2 * s3);
		}
	}

	for (int i = 0; i < m - 1;i++) {
		for (int j = 0; j < n - 1; j++) {
			s1 = sum(0, 0, n - 1, i);
			s2 = sum(0, i + 1, j, m - 1);
			s3 = sum(j + 1, i + 1, n - 1, m - 1);
			ans = get_max(ans, s1 * s2 * s3);
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			s1 = sum(0, 0, i, m - 1);
			s2 = sum(i + 1, 0, n - 1, j);
			s3 = sum(i + 1, j + 1, n - 1, m - 1);
			ans = get_max(ans, s1 * s2 * s3);
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m - 1; j++) {
			s1 = sum(i, 0, n - 1, m - 1);
			s2 = sum(0, 0, i - 1, j);
			s3 = sum(0, j + 1, i - 1, m - 1);
			ans = get_max(ans, s1 * s2 * s3);
		}
	}
	cout << ans;

	return 0;
}

long long sum(int starty, int startx, int endy, int endx) {
	long long area = 0;
	for (int i = starty; i <= endy; i++) {
		for (int j = startx; j <= endx; j++) {
			area+= arr[i][j];
		}
	}
	return area;
}