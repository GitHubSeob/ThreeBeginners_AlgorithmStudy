#include <iostream>
using namespace std;

int main() {
	int N = 0;
	cin >> N;
	long DP[91] = { 0, };
	DP[0] = DP[1] = DP[2] = 1;

	for (int i = 3; i <= N; ++i) {
		DP[i] = DP[i - 1] + DP[i - 2];                  //피보나치 수열
	}
	cout << DP[N];
}


