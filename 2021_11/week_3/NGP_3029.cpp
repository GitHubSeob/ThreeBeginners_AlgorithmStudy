#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	string start, finish;
	cin >> start >> finish;

	int total;
	int sh, sm, ss, ssum;
	int eh, em, es, esum;
	int th, tm, ts;
	string answer;

	sh = stoi(start.substr(0, 2)), sm = stoi(start.substr(3, 4)), ss = stoi(start.substr(6, 7));
	eh = stoi(finish.substr(0, 2)), em = stoi(finish.substr(3, 4)), es = stoi(finish.substr(6, 7));

	ssum = (sh * 60 + sm) * 60 + ss;
	esum = (eh * 60 + em) * 60 + es;


	if (esum > ssum) {
		total = esum - ssum;
	}
	else {
		total = 60 * 60 * 24 - ssum;
		total += esum;
	}

	ts = total % 60;
	tm = (total / 60) % 60;
	th = (total / 60) / 60;
	if (th < 10) { answer = '0' + to_string(th); }
	else answer = to_string(th);
	if (tm < 10)  answer = answer + ':' + '0' + to_string(tm);
	else answer = answer + ':' + to_string(tm);
	if (ts < 10)answer = answer + ':' + '0' + to_string(ts);
	else answer = answer + ':' + to_string(ts);

	cout << answer;
}
//น้มุ :-)