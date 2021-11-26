#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T(0);
	int idx(0);
	int idx2(0);
	cin >> T;
	int answer(T);
	string word("");
	vector<int>alp(26, 0);
	for (idx = 0; idx < T; ++idx) {
		cin >> word;
		alp = vector<int>(26, 0);
		alp[word[0] - 97]++;
		for (idx2 = 1; idx2 < word.size(); ++idx2) {
			if (word[idx2 - 1] != word[idx2]) {				
				if (alp[word[idx2] - 97] != 0) {
					answer--;
					break;
				}
				else alp[word[idx2] - 97]++;
			}
			else alp[word[idx2] - 97]++;
		}
	}
	cout << answer;
}