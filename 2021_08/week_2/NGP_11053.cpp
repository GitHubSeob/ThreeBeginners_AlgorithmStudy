#include<iostream>
using namespace std;
int arr[1001];
int dp[1001];
int more(int a, int b) { return a > b ? a : b; }

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int max=0;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = more(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		max = more(max, dp[i]);
	}
	cout << max << "\n";
}