#include<iostream>
using namespace std;
int d[101][10];//앞은 1~100 뒤는 0~9
int main() {
	int n,j,i,ans;
	cin >> n;

	d[1][0] = 0;          //0은 초기화
	for (i = 1; i <= 9; i++) {
		d[1][i] = 1;//n이 1일 때
	}
	for (int i = 2; i <= n; i++) {
		d[i][0] = d[i - 1][1]; //0으로 끝날 땐 항상 앞자리수는 1이다.
		for (j = 1; j < 9; j++) {
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % 1000000000; // 1~8 사이에 경우 맨 뒷자리에는 앞뒤 숫자가 들어감
		}
		d[i][9] = d[i - 1][j - 1];//9로 끝날 땐 항상 앞자리는 8
	}
	ans = 0;
	for (i = 0; i < 10; i++) {
		ans = (ans + d[n][i]) % 1000000000;
	}
	cout << ans;
	return 0;
}