#include<iostream>
#include<string.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n, cnt = 0;
	int arr[26];
	cin >> n;

	string s;

	for (int i = 0; i < n; i++) {
		int tf = 1;
		cin >> s;
		memset(arr, 0, sizeof(arr));

		s = s + ' ';

		for (int j = 0; j < s.length() - 1; j++) {
			if (s[j] != s[j + 1]) {
				arr[s[j] - 'a']++;
				if (arr[s[j] - 'a'] > 1) {
					continue;
				}
			}
		}

		for (int i = 0; i < 26; i++) {
			if (arr[i] > 1)
				tf = 0;
		}

		if (tf == 1)
			cnt++;
	}

	cout << cnt;
}





/*
#include<iostream>
#include<string>
using namespace std;

int main() {
	int n, cnt = 0;
	string s;
	int arr[26] = { 0, };
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		memset(arr, 0, sizeof(arr));
		s = s + ' ';
		for (int j = 0; j < s.length()-1; j++) {
			if (arr[s[j] - 'a'] != arr[s[j + 1] - 'a']) {
				arr[s[j] - 'a'] += 1;
			}
			if (arr[s[j] - 'a'] >= 2)
				continue;
		}
		cnt++;

	}

	cout << cnt;
}
*/