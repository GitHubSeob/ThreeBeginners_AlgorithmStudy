//문제풀이: https://githubseob.tistory.com/15

#include <iostream>
using namespace std;

int main() {
	int N = 0;
	cin >> N;
	long long DP[91] = { 0, };
	DP[0] = DP[1] = DP[2] = 1;

	for (int i = 3; i <= N; ++i) {
		for (int j = 0; j <= i - 2; ++j) {
			DP[i] += DP[j];
		}
	}		
	cout << DP[N];
}