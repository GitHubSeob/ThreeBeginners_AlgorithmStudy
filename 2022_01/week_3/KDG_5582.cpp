#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int dp[4001][4001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	string s1, s2;

	cin >> s1;
	cin >> s2;
	int ans(0);



	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j < s2.length(); j++) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				ans = max(ans, dp[i + 1][j + 1]);
			}
		}
	}


	cout << ans;
}
