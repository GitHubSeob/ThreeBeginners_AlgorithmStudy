//문제풀이: https://githubseob.tistory.com/120

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string word = "";
	string code = "";
	int L(0), C(0);
	int consonant(0), vowel(0);
	int idx(0), idx2(0);
	set<string>answer;
	set<string>::iterator it;
	cin >> L >> C;
	char character = ' ';
	for (idx = 0; idx < C; ++idx) {
		cin >> character;
		word += character;
	}

	sort(word.begin(), word.end());
	
	for (idx = 1; idx < (1 << C); ++idx) {
		consonant = 0;
		vowel = 0;
		code = "";
		for (idx2 = 0; idx2 < C; ++idx2) {
			if (idx & (1 << idx2)) {
				cout << idx2 << ' ';
				if (word[idx2] == 'a' || word[idx2] == 'e' || word[idx2] == 'i' || word[idx2] == 'o' || word[idx2] == 'u')
					++vowel;
				else ++consonant;
				code += word[idx2];
			}			
		}
		cout << '\n';
		if (vowel >= 1 && consonant >= 2 && vowel + consonant == L)
			answer.insert(code);
	}

	for (it = answer.begin(); it != answer.end(); ++it)
		cout << *it << '\n';
}