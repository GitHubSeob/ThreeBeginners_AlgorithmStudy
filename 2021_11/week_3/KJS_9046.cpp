#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int T(0);
	vector<int>Alp(26, 0);
	string code("");
	char answer(' ');
	int max_code(0);
	int idx(0);
	cin >> T;
	getline(cin, code);
	while (T--) {
		getline(cin, code);
		Alp = vector<int>(26, 0);
		max_code = 0;
		answer = 'a';
		for (idx = 0; idx < code.size(); ++idx)
			if(code[idx]!=' ')
				Alp[code[idx] - 97]++;
		for (idx = 0; idx < 26; ++idx) {
			if (Alp[idx] > max_code) {
				answer = 'a' + idx;
				max_code = Alp[idx];
			}
			else if (Alp[idx] == max_code)
				answer = '?';			
		}
		cout << answer << '\n';
	}
}