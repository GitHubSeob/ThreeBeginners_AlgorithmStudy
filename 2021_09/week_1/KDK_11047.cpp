#include<iostream>

using namespace std;

int main() {
	int n, k, count = 0;
	cin >> n >> k;
	int arr[10];
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = n - 1; i >= 0; i--) {
		while (k / arr[i]) {
			count += k / arr[i];         //구하고 싶은 값을 나누는 돈에 최대값으로 나누고 카운트 업
			k %= arr[i];                //나눈 나머지를 반환
		}
	}
	cout << count << endl;
	return 0;
}