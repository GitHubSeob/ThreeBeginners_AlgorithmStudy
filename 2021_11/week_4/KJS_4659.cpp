#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string input("");
	int idx(0);

	while (1) {
		cin >> input;
		if (input == "end") break;
		int min_vowel(0);
		int consonant(0);
		int vowel(0);
		cout << "<" << input << "> is ";
		for (idx = 0; idx < input.size(); ++idx) {
			if (input[idx] == 'a' || input[idx] == 'e' || input[idx] == 'i' || input[idx] == 'o' || input[idx] == 'u') {
				min_vowel = 1;
				vowel++;
				consonant = 0;
			}
			else {
				consonant++;
				vowel = 0;
			}
			if (vowel >= 3 || consonant >= 3) {
				cout << "not acceptable.";
				break;
			}
			if (idx != 0 && input[idx - 1] == input[idx]) {
				if (!(input[idx] == 'e' || input[idx] == 'o')) {
					cout << "not acceptable.";
					break;
				}
			}
			if (idx + 1 == input.size()) {
				if (min_vowel == 0) cout << "not acceptable.";
				else cout << "acceptable.";
			}
		}

		cout << '\n';
	}
}