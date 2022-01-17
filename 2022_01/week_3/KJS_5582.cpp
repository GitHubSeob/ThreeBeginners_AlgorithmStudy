//문제풀이: https://githubseob.tistory.com/144

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s1(""), s2("");	
	string s("");
	cin >> s1 >> s2;
	int answer(0);
	int idx1(0), idx2(0);
	
	int start(0);
	int end(0);

	s = s1[0];
	while (end <= s1.size() && start<s1.size()) {		
		if (start > end) {
			end = start;			
			s = s1[start];
		}
		else if (s2.find(s) != string::npos) {
			answer = max(answer, end - start + 1);
			end++;
			s += s1[end];
		}
		else {
			start++;
			if (!s.empty())
				s.erase(0, 1);
		}
	}
	cout << answer;
}