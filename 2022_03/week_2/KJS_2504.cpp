//문제풀이: https://githubseob.tistory.com/163

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string input("");
	cin >> input;
	stack<char>bracket;
	vector<string>s;
	int idx(0);

	for (idx = 0; idx < input.size(); ++idx) {
		if (input[idx] == ')' || input[idx] == ']') {
			if (bracket.empty()) {
				cout << 0;
				return 0;
			}
			else if (input[idx] == ')') {
				if (bracket.top() == '(') {
					bracket.pop();
				}
				else {
					cout << 0;
					return 0;
				}
			}
			else {
				if (bracket.top() == '[') {
					bracket.pop();
				}
				else {
					cout << 0;
					return 0;
				}
			}
		}
		else {
			bracket.push(input[idx]);
		}
	}
	if (!bracket.empty()) {
		cout << 0;
		return 0;
	}

	int round(0), square(0);

	while (1) {
		round = input.find("()");
		square = input.find("[]");
		if (round == -1 && square == -1) {
			s = vector<string>(input.size() + 2, "");
			for (idx = 0; idx < input.size(); ++idx) {
				s[idx] = input[idx];
			}
			break;
		}
		if (round != -1)
			input.replace(round, 2, "2");
		else if (square != -1)
			input.replace(square, 2, "3");
	}

	while (s.size() > 3) {
		for (idx = 0; idx + 2 < s.size(); ++idx) {
			if (s[idx] == "(" && s[idx + 1] != "(" && s[idx + 2] == ")") {
				s[idx] = to_string(stoi(s[idx + 1]) * 2);
				s.erase(s.begin() + idx + 1);
				s.erase(s.begin() + idx + 1);
				break;
			}
			else if (s[idx] == "[" && s[idx + 1] != "[" && s[idx + 2] == "]") {
				s[idx] = to_string(stoi(s[idx + 1]) * 3);
				s.erase(s.begin() + idx + 1);
				s.erase(s.begin() + idx + 1);
				break;
			}
			else if (s[idx] != "[" && s[idx] != "(" && s[idx + 1] != "[" && s[idx + 1] != "(") {
				s[idx] = to_string(stoi(s[idx]) + stoi(s[idx + 1]));
				s.erase(s.begin() + idx + 1);
				break;
			}
		}
	}
	cout << s[0];
}