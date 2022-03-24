#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string S;
	cin >> S;
	int pipe(0), idx(0);
	int result(0);

	for (idx = 0; idx < S.size(); ++idx) {
		if (S[idx] == '(') {
			if (S[idx + 1] == ')') {
				result += pipe;
				++idx;
			}
			else {
				pipe++;
			}
		}
		else {
			if (pipe > 0)
				pipe--;
			result += 1;
		}
	}
	cout << result;
}