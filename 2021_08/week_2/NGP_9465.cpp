#include<iostream>
#include<string.h>
using namespace std;
int dp[2][100001];

int more(int a, int b) { return a > b ? a : b; }

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k <= n; k++) {
				cin >> dp[j][k];
			}
		}
		
		for (int k = 2; k <= n; k++) {
			for (int j = 0; j < 2; j++) {
				if (j == 0) {
					dp[j][k] = dp[j][k] + more(dp[j + 1][k - 1], dp[j + 1][k - 2]);
				}
				else if (j == 1) {
					dp[j][k] = dp[j][k] + more(dp[j - 1][k - 1], dp[j - 1][k - 2]);
				}
			}
		}
		int max=0;
		max = more(dp[0][n], dp[1][n]);
		cout << max << "\n";
	}
}