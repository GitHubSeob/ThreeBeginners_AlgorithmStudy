//문제풀이: https://githubseob.tistory.com/160

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string input("");
	cin >> input;
	int pipe(0), idx(0);
	int answer(0);

	for (idx = 0; idx < input.size(); ++idx) {
		if (input[idx] == '(') {
			if (input[idx + 1] == ')') {
				answer += pipe;
				++idx;
			}
			else {
				pipe++;
			}
		}
		else {
			if (pipe > 0)
				pipe--;
			answer += 1;
		}
	}
	cout << answer;
}