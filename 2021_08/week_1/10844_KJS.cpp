/*
DP[y][x]에서 y는 자릿수, x는 첫 번째 수를 의미한다.
0으로 시작하는 수는 없지만 편의상 0으로 시작하는 수를 만든다.
한 자릿수일 경우 x=0을 제외한 모든 수는 1,

두 자릿수:
0? = (? = DP[1][1]) (0의 계단 수는 1밖에 없으므로)
1? = (? = DP[1][0] + DP[1][2])
2? = (? = DP[1][1] + DP[1][3])
...

세 자릿수:
0?? = 1? = DP[2][1]
1?? = (0? = DP[2][0] + 2? = DP[2][2])
2?? = (1? = DP[2][1] + 3? = DP[2][3])
...

이런 규칙을 식으로 세우면
x=0일 때 DP[y-1][1],
x>0일 때 DP[y-1][x-1] + DP[y-1][x+1]라는 식이 나온다.
정답을 1,000,000,000으로 나눈 나머지를 출력해야 하므로
더할 때마다 1,000,000,000으로 나눈 나머지 값을 저장한다.
*/

#include <iostream>
#include <vector>
#define MOD 1000000000
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	vector<vector<long long>>DP(N + 1, vector<long long>(11, 0));

	int y = 0, x = 0;
	for (x = 0; x <= 9; ++x) {
		DP[1][x] = 1;
	}

	for (y = 2; y <= N; ++y) {
		DP[y][0] = DP[y - 1][1];
		for (x = 1; x <= 9; ++x) {
			DP[y][x] = (DP[y - 1][x - 1] + DP[y - 1][x + 1]) % MOD;
		}
	}
	long long sum = 0;
	for (x = 1; x <= 9; ++x) {
		sum = (sum + DP[N][x]) % MOD;
	}

	cout << sum;
}