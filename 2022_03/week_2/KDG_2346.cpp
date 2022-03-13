#include <iostream>
#include <queue>
#include<deque>

using namespace std;
int main() {
	int N;
	cin >> N;
	deque<pair<int, int>> dq1; //풍선번호,안의 숫자

	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		dq1.push_back({ i,x }); //1~N번
	}

	while (!dq1.empty()) {
		auto num = dq1.front(); // 번호
		cout << num.first << ' ';
		int now = num.second; // 안의 숫자
		dq1.pop_front();//터트리기

		if (now > 0) {//양수이면
			now--;
			while (!now ==0) {
				dq1.push_back(dq1.front());
				dq1.pop_front();
				now--;
			}//터트린것이 앞의 숫서를 바꾸는거니까
		}
		else {//역방향이면
			while (!now == 0) {
				dq1.push_front(dq1.back());
				dq1.pop_back();
				now++;
			}
		}
	}
}