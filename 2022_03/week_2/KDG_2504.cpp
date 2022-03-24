#include<iostream>
#include<stack>
using namespace std;

int main(void) {
	string s;
	cin >> s;

	stack<char> st;

	int temp(1);
	int result(0);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			temp *= 2;
			st.push('(');
		}//(일 경우 *2 하고 st값에 '(' push
		else if (s[i] == '[') {
			temp *= 3;
			st.push('[');
		}//'['일경우 *3 하고 st값에 '[' push
		else if (s[i] == ')') {
			if (st.empty() || (st.top() != '(')) {
				cout << 0 << '\n';
				return 0;
			}//닫은 괄호가 나왔는데 비어 있거나 그전에 '('가 안나왔을경우

			if (s[i - 1] == '(') {
				result += temp;
			}//그전이 바로 '('일경우 현재값을 마무리 하기위해 임시값을 넣는다. ex) (())

			temp /= 2;
			st.pop();//그 이후 *2를 미리 실행했으므로 나눠준다. 
		}
		else if (s[i] == ']') {
			if (st.empty() || (st.top() != '[')) {
				cout << 0 << '\n';
				return 0;
			}

			if (s[i - 1] == '[') {
				result += temp;
			}

			temp /= 3;
			st.pop();
		}
	}

	if (!st.empty())
		result = 0;
	cout << result << endl;
}