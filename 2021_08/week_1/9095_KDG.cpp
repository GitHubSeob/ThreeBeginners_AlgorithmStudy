#include<iostream>
using namespace std;
int d[11] = { 0,1,2,4 };  // dp[0] dp[1] dp[2] dp[3]
int DP(int n) {
	if (d[n])return d[n];

	return d[n] = DP(n - 1) + DP(n - 2) + DP(n - 3);
}
int main() {
	int t;
	int n;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << DP(n) << endl;
	}
	return 0;
}