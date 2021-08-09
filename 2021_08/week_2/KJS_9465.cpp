//문제풀이: https://githubseob.tistory.com/16

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 0;
	int n = 0;
	int y = 0, x = 0;
	cin >> T;
	while (T--) {
		cin >> n;
		vector<vector<int>>DP(2, vector<int>(n, 0));
		vector<vector<int>>Arr(2, vector<int>(n, 0));
		for (y = 0; y < 2; ++y) {
			for (x = 0; x < n; ++x) {
				cin >> Arr[y][x];
			}
		}
		DP[0][1] = Arr[0][1] + Arr[1][0];
		DP[1][1] = Arr[0][0] + Arr[1][1];
		DP[0][0] = Arr[0][0];
		DP[1][0] = Arr[1][0];

		for (x = 2; x < n; ++x) {
			DP[0][x] = Arr[0][x] + max(DP[1][x - 2], DP[1][x-1]);
			DP[1][x] = Arr[1][x] + max(DP[0][x - 2], DP[0][x-1]);
		}
		
		cout <<  max(DP[0][n-1], DP[1][n-1]) << "\n";		
	}

}