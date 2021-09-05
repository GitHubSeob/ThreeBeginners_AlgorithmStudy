#include<iostream>
using namespace std;

int main() {

	int n, m, k, ans = 0;
	cin >> n >> m >> k;

	while (n>=2&&m>=1&&n+m>=k+3) {
		n -= 2;
		m -= 1;
		ans++;
	}
	cout << ans;
}