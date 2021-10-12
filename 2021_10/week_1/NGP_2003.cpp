#include<iostream>

using namespace std;
int n, m, ans = 0;
int arr[10000];


int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	
	int sum=0;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			if (sum == m)
				ans++;
		}
	}

	cout << ans;
}
