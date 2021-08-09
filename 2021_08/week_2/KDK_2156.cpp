#include <iostream>
#include <algorithm>
using namespace std;
int DP[10001];
int a[10001];

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) cin >> a[i];

	DP[0] = a[0];
	DP[1] = a[1] + a[0];
	DP[2] = max(a[0] + a[1], a[0] + a[2]);
	DP[2] = max(DP[2], a[1] + a[2]);



	for (int i = 3; i < T; i++) {
		DP[i] = max(DP[i - 2] + a[i], DP[i - 3] + a[i - 1] + a[i]);

		DP[i] = max(DP[i - 1], DP[i]);
		
	}//DP3의 경우 가지수가 나뉜다
	//1번과 DP 3번 와인을 마시는경우, VS 1번과 2번을 마시는경우 
	//그전경우와 3번 와인을 마시는경우

	cout << DP[T-1] << '\n';
}
