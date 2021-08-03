/*
n-2 타일에서 2x2 타일 1개, 1x2 타일 2개를 두는 총 2가지 방법이 있다.
n- 1타일에서 2x1 타일 1개를 두는 1가지 방법이 있다.
따라서 DP[n] = DP[n-2] * 2 + DP[n-1]의 식이 나오게 된다.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	vector<int>DP(n + 1, 0);
	DP[1] = 1;
	DP[2] = 3;
	int x = 0;
	for (x = 3; x <= n; ++x) {
		DP[x] = (DP[x - 2] * 2 + DP[x - 1]) % 10007;
	}

	cout << DP[n];
}