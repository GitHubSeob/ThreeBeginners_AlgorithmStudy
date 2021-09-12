#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdlib.h>

using namespace std;

int arr[101][101];

int n, m;
long long ans = -1;
long long r1, r2, r3;

int s(int i, int j, int x, int y) {
	int sum = 0;
	for (int a = i; a <= x; a++) {
		for (int b = j; b <= y; b++) {
			sum += arr[a][b];
		}
	}

	return sum;
}

int main() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= m - 2; i++) {
		for (int j = 1; j <= m - 1; j++) {
			r1 = s(1, 1, n, i);
			r2 = s(1, i + 1, n, j);
			r3 = s(1, j + 1, n, m);
			if (ans < r1 * r2 * r3)
				ans = r1 * r2 * r3;
		}
	}

	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			r1 = s(1, 1, i, m);
			r2 = s(i + 1, 1, j, m);
			r3 = s(j + 1, 1, n, m);
			if (ans < r1 * r2 * r3)
				ans = r1 * r2 * r3;
		}
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 1; j++) {
			r1 = s(1, 1, n, j);
			r2 = s(1, j + 1, i, m);
			r3 = s(i + 1, j + 1, n, m);
			if (ans < r1 * r2 * r3)
				ans = r1 * r2 * r3;
		}
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 1; j++) {
			r1 = s(1, 1, i, j);
			r2 = s(i + 1, 1, n, j);
			r3 = s(1, j + 1, n, m);
			if (ans < r1 * r2 * r3)
				ans = r1 * r2 * r3;
		}
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 1; j++) {
			r1 = s(1, 1, i, m);
			r2 = s(i + 1, 1, n, j);
			r3 = s(i + 1, j + 1, n, m);
			if (ans < r1 * r2 * r3)
				ans = r1 * r2 * r3;
		}
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 1; j++) {
			r1 = s(1, 1, i, j);
			r2 = s(1, j + 1, i, m);
			r3 = s(i + 1, 1, n, m);
			if (ans < r1 * r2 * r3)
				ans = r1 * r2 * r3;
		}
	}

	cout << ans << "\n";

	return 0;
}