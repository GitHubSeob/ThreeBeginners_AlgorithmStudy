#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	long long n, m;
	cin >> n >> m;

	if (n >= 3) {
		if (4 <= m && m <= 6) {
			cout << 4;
		}
		else if (m < 4) {
			cout << m;
		}
		else
			cout << m - 2;
	}
	else if (n == 2) {
		if (m < 8) {
			if (m % 2 == 0)
				cout << (m / 2);
			else if (m % 2 == 1)
				cout << (m / 2) + 1;

		}
		else if (m >= 8) {
			cout << 4;
		}
		
	}
	else if(n==1)
		cout << 1;

	return 0;
}