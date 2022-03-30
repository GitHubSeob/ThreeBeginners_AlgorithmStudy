//문제풀이: https://githubseob.tistory.com/172

#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T(0), k(0), n(0);
	char oper(' ');
	cin >> T;

	while (T--) {
		cin >> k;
		map<int, int>m;
		map<int, int>::iterator iter;
		while (k--) {
			cin >> oper >> n;
			if (oper == 'I') {
				m[n]++;
			}
			else {
				if (!m.empty()) {
					if (n == 1) {
						iter = --m.end();						
						if (iter->second == 1)
							m.erase(iter);
						else iter->second--;
					}
					else {
						iter = m.begin();
						if (iter->second == 1)
							m.erase(iter);
						else iter->second--;
					}
				}
			}
		}

		if (m.empty()) cout << "EMPTY\n";
		else {
			cout << (--m.end())->first << " ";
			cout << m.begin()->first << '\n';
		}
	}
}