#include<iostream>
using namespace std;
int d[1001] = { 0,1,3 };  // dp[0] dp[1] dp[2]
int DP(int n) {
	if (d[n])return d[n];

	return d[n] = (DP(n - 1) % 10007 + 2 * DP(n - 2) % 10007)%10007;
}
int main() {
	int n;

	cin >> n;
	cout << DP(n) << endl;
	return 0;
}