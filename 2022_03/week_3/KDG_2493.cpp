#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, height;
	stack<pair<int, int>> sta;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> height;
		while (!sta.empty()) { //값이 있다면?
			if (sta.top().second > height) {
				cout << sta.top().first << ' ';
				break;
			}//바로 좌측값 출력
			sta.pop();
		}//아니면 반복
		if (sta.empty()) {
			cout << "0 ";
		}//공백값 즉 좌측에 값이 없을 경우 0먼저 출력
		sta.push({ i,height });//이후에 다시 값 삽입
	}
}