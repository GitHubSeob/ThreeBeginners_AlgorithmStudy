#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	vector<string> v;

	while (1) {
		string s,tmp;
		getline(cin, s);

		if (s == "END")
			break;
		else {
			for (int i = s.length() - 1; i >=0; i--) {
				tmp += s[i];
			}
		}
		v.push_back(tmp);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}