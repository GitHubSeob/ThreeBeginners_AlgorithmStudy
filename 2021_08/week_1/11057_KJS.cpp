/*
DP[y][x]에서 y는 자릿수, x는 첫 번째 수를 의미한다.
한 자릿수일 경우 모두 1,

두 자릿수:
DP[2][0] = 0? = (? = DP[0][0] + DP[0][1] + DP[0][2] + ... + DP[0][9])
DP[2][1] = 1? = (? = DP[1][1] + DP[1][2] + DP[1][3] + ... + DP[1][9])

세 자릿수:
DP[3][0] = 0?? = (?? = DP[2][0] + DP[2][1] + DP[2][2] + ... + DP[2][9])
DP[3][1] = 1?? = (?? = DP[2][1] + DP[2][2] + DP[2][3] + ... + DP[2][9])
...

y!=1일 때, DP[y][x] = DP[y-1][x]~DP[y-1][9]까지의 합이다.
정답을 10,007으로 나눈 나머지를 출력해야 하므로 더할 때마다 10,007으로 나눈 나머지 값을 저장한다.
*/


#include <iostream>
#include <vector>
#define MOD 10007
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	int y = 0, x = 0;
	cin >> N;
	vector<vector<long long>>DP(N + 1, vector<long long>(10, 0));
	for (x = 0; x < 10; ++x)
		DP[1][x] = 1;
	for (y = 2; y <= N; ++y) {
		for (x = 0; x < 10; ++x) {
			for (int x2 = x; x2 <10 ; ++x2) {
				DP[y][x] += (DP[y - 1][x2]%MOD);
			}
		}
	}

	int sum = 0;
	for (x = 0; x < 10; ++x) {
		sum = (sum + DP[N][x]) % MOD;
	}
	cout << sum;
}