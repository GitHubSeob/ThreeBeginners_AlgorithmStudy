#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
int i, j;
int main() {
	string startT;
	string endT;

	cin >> startT >> endT;

	int sh = (startT[0] - '0') * 10 + startT[1] - '0';
	int sm = (startT[3] - '0') * 10 + startT[4] - '0';
	int ss = (startT[6] - '0') * 10 + startT[7] - '0';

	int eh = (endT[0] - '0') * 10 + endT[1] - '0';
	int em = (endT[3] - '0') * 10 + endT[4] - '0';
	int es = (endT[6] - '0') * 10 + endT[7] - '0';

	if (ss > es) {
		es += 60;
		em -= 1;
	}
	if (em < sm) {
		em += 60;
		eh -= 1;
	}
	if (sh > eh) {
		eh += 24;
	}

	int time, min, sec;


	time = eh - sh;
	min = em - sm;
	sec = es - ss;


	if (startT == endT) {
		time = 24;
	}

	//Ãâ·Â
	cout << setw(2) << setfill('0') << time << ":" << setw(2) << setfill('0') << min << ":" << setw(2) << setfill('0') << sec;

	return 0;
}