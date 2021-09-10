#include<iostream>
#include<stdlib.h>
using namespace std;
int broken[10] = { 0, };
int min(int a, int b) { return a > b ? b : a; }
int check(int a);
int minimum(int a);
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, count, ans;
	
	
	cin >> n;
	cin >> count;
	
	for (int i = 0; i < count; i++) {
		int tmp;
		cin >> tmp;
		broken[tmp] = 1;
	}
	cout << minimum(n);

	return 0;
}

int check(int a) {
	int len = 0;
	if (a == 0) {
		if (broken[0] == 1)
			return 0;
		else
			return 1;
	}
	while (a > 0) {
		if (broken[a % 10] == 1) {
			return 0;
		}
		a /= 10;
		len++;
	}
	return len;
}

int minimum(int a) {
	int ans = abs(a - 100);
	int tmp;
	for (int i = 0; i <= 1000000; i++) {
		int len = check(i);
		if (len > 0) {
			tmp = abs(a - i);
			ans = min(ans, tmp + len);
		}
	}
	return ans;
}