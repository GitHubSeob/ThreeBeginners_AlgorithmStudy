#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	string a, b,c;
	cin >> a;
	cin >> b;

	for (int i = 0; i < a.length(); i++) {
		if (a[i] - '0' >= 0 && a[i] - '0' <= 9) {
			a.erase(i, 1);
			i--;
		}
		else
			continue;
	}



	if (a.find(b) == string::npos)
		cout << '0';
	else
		cout << '1';
}