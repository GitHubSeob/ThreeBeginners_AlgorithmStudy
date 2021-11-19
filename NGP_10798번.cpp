#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	string s[15][5];
	int longest = 0;

	for (int i = 0; i < 5; i++) {
		string tmp;
		cin >> tmp;
		if (longest < tmp.length())
			longest = tmp.length();

		for (int j = 0; j < tmp.length(); j++) {
			s[j][i] = tmp[j];
		}
	}

	for (int i = 0; i < longest; i++) {
		for (int j = 0; j < 5; j++) {
			cout << s[i][j];
		}
	}

	
}