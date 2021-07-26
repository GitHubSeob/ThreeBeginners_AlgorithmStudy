/*
num-2에서 = (1x2 타일 두개)를 추가하거나,
num-1에서 | (2x1 타일 한개)를 추가하면 타일을 num만큼 사용한 모양이 나온다.
따라서 DP[num] = DP[num-2] + DP[num-1]라는 식이 나온다.
*/

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