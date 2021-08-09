#include<iostream>
using namespace std;
int dp[10010];
int arr[10010];
int more(int a, int b) { return a > b ? a : b; }

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i+2];
		dp[i+2] = arr[i+2];
	}
	/*
	dp[2] = arr[1] + arr[2];
	dp[3] = more(arr[1] + arr[3], arr[2] + arr[3]);
	//이거 위에 두개 코드를 없애고 그냥 그 배열앞에 0을 두개 추가하자
	*/
	for (int i = 4; i <= n+2; i++) {
		dp[i] = more(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
		dp[i] = more(dp[i], dp[i - 1]); //반례 110011때문에 추가해야함.
	}

	cout << dp[n+2] << "\n";

}
