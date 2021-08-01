#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	int x = 0;
	cin >> n;
	vector<int>DP(n + 1, 0);
	DP[1] = 1;
	DP[2] = 2;

	for (x = 3; x <= n; ++x) {
		DP[x] = (DP[x - 1] + DP[x - 2]) % 10007;
	}
	cout << DP[n];
}