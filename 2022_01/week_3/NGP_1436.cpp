/*
10씩 나누면서 1의자리수가 맞으면 저장하는 형태로 진행하면 좋을듯?
ex)666이면 그냥 출력 6661같은거면 10으로 나누면 666이 된다.
만약 부합한다면 111666111이 있으면 세번의 과정을 거치면 나머지 1000을 했을때 666이라는 숫자가 나오게 된다면 다시 원래 while문을 돌리면 되는것.

*/
#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);


	int n;
	cin >> n;

	int cnt = 0, ans = 0, tmp;
	while (cnt != n) {
		ans++;
		tmp = ans;
		while (tmp != 0) {
			if (tmp % 1000 == 666) {
				cnt++;
				break;
			}
			else {
				tmp = tmp / 10;
			}
		}
	}

	cout << ans;

	return 0;
}