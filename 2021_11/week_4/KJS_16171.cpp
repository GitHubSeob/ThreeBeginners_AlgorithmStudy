#include <iostream>
using namespace std;
int main() {
	int idx(0);
	string s1(""), s2("");
	cin >> s1 >> s2;
	string answer("");
	for (idx = 0; idx < s1.size(); ++idx) {
		if (s1[idx] >= '0' && s1[idx] <= '9');
		else answer += s1[idx];
	}
	if (answer.find(s2) != string::npos) cout << 1;
	else cout << 0;	
}