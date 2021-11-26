
#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	// 1.모음 하나를 반드시 포함
	// 2.모음이 3개 혹은 자음이 3개 연속으로 오면 안된다.
	// 3. 같은 글자가 연속적으로 두번 오면 안되나, ee와 oo는 허용한다.

	while (1) {
		//vowel 모음 constant 자음 ans->조건을 만족하는지
		int vowel = 0, constant = 0,  ans = 0;
		string s;
		cin >> s;

		if (s == "end") break;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') { //모음일경우
				ans = 1;
				vowel++;
				constant=0;
			}
			else {  //자음일경우
				vowel = 0;
				constant++;
			}

			if (vowel == 3 || constant == 3) {
				ans = 0;
				break;
			}

			if (i < s.length() - 1) {
				if (s[i] == 'e' && s[i + 1] == 'e')
					continue;
				else if (s[i] == 'o' && s[i + 1] == 'o')
					continue;
				else if(s[i] == s[i + 1]) {
					ans = 0;
					break;
				}
			}
		}

		if (ans == 1)
			cout << "<" << s << ">" << " is acceptable.\n";
		else
			cout << "<" << s << ">" << " is not acceptable.\n";

	}
}



