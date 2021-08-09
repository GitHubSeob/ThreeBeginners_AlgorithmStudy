#include<iostream>
using namespace std;
long long dp[91];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	int cnt;
	cin >> cnt;

	dp[1] = 1, dp[2] = 1, dp[3] = 2;
	for (int i = 4; i <= cnt; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[cnt] << "\n";
}