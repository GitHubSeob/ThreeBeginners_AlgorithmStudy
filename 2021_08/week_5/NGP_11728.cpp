#include<iostream>
#include<algorithm>

using namespace std;
int A[1000000], B[1000000], C[2000000];
int n, m;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		C[i] = A[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
		C[i + n] = B[i];
	}
	int a = n + m + 1;
	sort(C + 1, C + a);
	for (int i = 1; i <= a - 1; i++) {
		cout << C[i] << ' ';
	}

	return 0;
}