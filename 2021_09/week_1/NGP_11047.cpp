#include<iostream>
using namespace std;
int arr[10];
int ans;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = n-1; i >= 0; i--) {
		if (k >= arr[i]) {
			ans += (k / arr[i]);
			k %= arr[i];
		}
	}
	
	cout << ans;
}