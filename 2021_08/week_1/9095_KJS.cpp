/*
1, 2, 3의 숫자를 사용하므로 DP[4]부터 시작한다.
같은 숫자를 써도 순서만 달라도 되므로, DP[n]은 DP[n-1]에서 1을 더한 수, DP[n-2]에서 2를 더한 수, DP[n-3]에서 3을 더한 수이므로
DP[n] = DP[n-1] + DP[n-2] + DP[n-3]의 식이 나온다.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 0;
	int n = 0;
	int x = 0;
	cin >> T;

	while (T-- > 0) {
		cin >> n;
		vector<int>DP(n + 1, 0);
		DP[1] = 1;
		DP[2] = 2;
		DP[3] = 4;
		for (x = 4; x <= n; ++x) {
			DP[x] = DP[x - 1] + DP[x - 2] + DP[x - 3];
		}
		cout << DP[n] << "\n";
	}
}