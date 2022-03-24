#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str, result;
	stack<char> stack;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			result += str[i];
			continue;
		} //A~Z값 입력
		if (str[i] == '(') {
			stack.push(str[i]);
			continue;
		} // 괄호 여는거 생기면? 일단 push
		if (str[i] == ')') {
			while (stack.top() != '(') {
				result += stack.top();
				stack.pop();
			}
			stack.pop();
			continue;
		}//닫는데, 만약 그전 stack 에서 '('가 아닐경우 정답에 현재 stack top을 넣고 pop 해서 찾는다
		if (str[i] == '*' || str[i] == '/') {
			while (!stack.empty() && (stack.top() == '*' || stack.top() == '/'))
				result += stack.top(), stack.pop();
		}// '*'과 '/'은 공통적으로 어쩌피 먼저 계산 한다.
		else {
			while (!stack.empty() && stack.top() != '(')
				result += stack.top(), stack.pop();
		} // '+'와 '-'는 괄호가 없을 경우 그다음
		stack.push(str[i]);
	}

	while (!stack.empty()) {
		result += stack.top();
		stack.pop();
	}
	cout << result << "\n";
	return 0;
}