#include <iostream>
#include <map>
#include <string>
#include <ctype.h> //알파뱃인가염?

using namespace std;
map<string, int> m1;
map<int, string> m2;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		m1.insert(make_pair(s, i)); 
		m2.insert(make_pair(i, s));
	}
	for (int i = 1; i <= m; i++) {
		cin >> s;
		if (isalpha(s[0])) { //알파벳인지 확인하는 것
			cout << m1[s] << '\n';
		}//걍 출력
		else {
			cout << m2[stoi(s)] << '\n';
		} //인트형 함수로 
	}
}