#include <iostream>
#include <string>
using namespace std;

int main() {
	int idx(0);
	string code("");

	getline(cin, code);
	while (code != "END") { // END를 입력할 때까지 반복
		for (idx = 0; idx < code.size(); ++idx)
			cout << code[code.size() - (idx + 1)];
		cout << '\n';
		getline(cin, code);
	}
}