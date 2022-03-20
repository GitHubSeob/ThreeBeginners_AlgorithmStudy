//문제풀이: https://githubseob.tistory.com/167

#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int idx(0);
	string input("");
	stack<char>s;
	cin >> input;


	for (idx = 0; idx < input.size(); ++idx) {
		if (input[idx] >= 'A' && input[idx] <= 'Z') {
			cout << input[idx];
		}
		else if (input[idx] == '(') {
			s.push('(');
		}
		else if (input[idx] == '*' || input[idx] == '/') {
			if (input[idx + 1] != '(') {
				cout << input[idx + 1] << input[idx];
				++idx;
			}
			else {
				s.push(input[idx]);
			}
		}
		else if (input[idx] == ')') {
			while (!s.empty()) {				
				if (s.top() != '(') {
					cout << s.top();
					s.pop();
				}
				else {
					s.pop();
					while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
						cout << s.top();
						s.pop();
					}
					break;
				}
			}
		}
		else {			
			if (!s.empty() && (s.top() == '+' || s.top() == '-')) {
				while (!s.empty() && s.top() != '(') {
					cout << s.top();
					s.pop();
				}
				s.push(input[idx]);
			}
			else s.push(input[idx]);
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}