#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> s;

bool cmp(string a, string b) {
	if (a.length() == b.length()) {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i])
				return a[i] < b[i];
		}
	}
	
	return a.length() < b.length();
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
		int tf = 0;
		char tmp[51];
		cin.getline(tmp, 51, '\n');
		s.push_back(tmp);
	}

	sort(s.begin(), s.end(), cmp);

	cout << s[0] << "\n";
	for (int i = 1; i < s.size(); i++) {
		if (s[i-1] == s[i])
			continue;
		cout << s[i] << "\n";
	}
	
	
}