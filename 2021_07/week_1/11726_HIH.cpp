#include <iostream>

using namespace std;



int main(void) {
	int n;
	int dp[1001] = {};


	cin >> n;
	
	dp[1] = 1; dp[2] = 2; 
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n] << endl;
}

//세로의 길이는 무조건 2
//가로의 길이는 n

//해야할 것 넓이 2n의 직사각형을 1*2 or 2*1 직사각형으로 채울 수 있는 경우를 체큰
//dp는 기억하는 프로그래밍 큰 문제를 해결하기 위해 작은 문제부터 풀어나가는 것이 핵심
//규칙을 알아내야함
// ex 넓이 4의 정사각형을 채우는 방법은 2개임 