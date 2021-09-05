#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	vector<int> number;
	bool zero=false;
	int sum = 0;
	string s;

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int tmp = s[i] - '0';
		number.push_back(tmp);
		sum += tmp;
		if (tmp == 0) zero = true;
	}

	if (sum % 3 == 0&& zero==true) {
		sort(number.begin(), number.end());
		for (int i = number.size() - 1; i >= 0; i--) {
			cout << number[i];
		}
	}
	else {
		cout << "-1";
	}
}


/*
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string s;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	vector<int> number;
	int sum = 0;
	
	cin >> s;

	if (findzero(s)) {
		for (int i = 0; i < s.size(); i++) {
			number.push_back(s[i]);
			sum += s[i];
		}
		if (sum % 3 == 0) {
			sort(number.begin(), number.end(), greater<>());
			for (int i = 0; i < number.size(); i++) {
				cout << number[i];
			}
		}
		else
			cout << "-1";
	}

}

bool findzero(string s) {
	int tmp;
	for (int i = 0; i < s.length(); i++) {
		tmp = s[i] - '0';
		if (tmp == 0) return true;
	}
	return false;
}
*/