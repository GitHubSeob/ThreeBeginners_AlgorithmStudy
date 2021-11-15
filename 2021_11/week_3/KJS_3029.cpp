#include <iostream>
#include <iomanip> // setw, setfill
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string start("");
	string end("");
	cin >> start >> end;
	int time_s(0);
	int time_e(0);
	time_s = (start[0] * 10 + start[1]) * 3600 + (start[3] * 10 + start[4]) * 60 + start[6] * 10 + start[7];
	time_e = (end[0] * 10 + end[1]) * 3600 + (end[3] * 10 + end[4]) * 60 + end[6] * 10 + end[7];
	// 시, 분을 모두 초로 환산하여 계산함.
	if (time_e < time_s) time_e += 24 * 3600;
	int time_t(time_e - time_s);
	int hour(0), minute(0), sec(0);
	hour = time_t / 3600;
	minute = time_t % 3600 / 60;
	sec = time_t % 3600 % 60;
	if (time_t == 0) cout << "24:00:00"; // 최소 1초이기 때문에 같으면 24시간
	else cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << sec;	
}