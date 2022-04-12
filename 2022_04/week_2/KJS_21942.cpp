//문제풀이: https://githubseob.tistory.com/179

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), F(0);

	string L("");	
	string input("");
	string name(""), part("");

	int idx(0);
	long long month(0), day(0), hour(0), min(0);	
	
	vector<long long>cal = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (idx = 1; idx <= 12; ++idx)
		cal[idx] += cal[idx - 1];

	cin >> N >> L >> F;

	map<pair<string, string>, long long>list;
	map<string, long long>answer;

	long long period(0);	
	long long start(0), end(0), time(0);

	period = stoll(L.substr(0, 3)) * 24 * 60 + stoll(L.substr(4, 2)) * 60 + stoll(L.substr(7, 2));	

	for (idx = 0; idx < N; ++idx) {
		cin >> input;
		month = stoll(input.substr(5, 2));
		day = stoll(input.substr(8, 2));

		cin >> input;
		hour = stoll(input.substr(0, 2));
		min = stoll(input.substr(3, 2));

		cin >> part;
		cin >> name;

		time = cal[month - 1] * 24 * 60 + day * 24 * 60 + hour * 60 + min;		
		
		if (list[{name, part}] == 0) {
			list[{name, part}] = time;			
		}
		else {			
			end = time;
			start = list[{name, part}];
			list[{name, part}] = 0;
			if (end - start > period) {
				answer[name] += ((end - start - period) * F);
			}
		}
	}

	if (answer.empty()) cout << -1;
	else {
		for (auto iter = answer.begin(); iter != answer.end(); ++iter) {
			cout << iter->first << " " << iter->second << '\n';
		}
	}
}