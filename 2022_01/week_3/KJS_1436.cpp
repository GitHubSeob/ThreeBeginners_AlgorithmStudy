//문제풀이: https://githubseob.tistory.com/145

#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N(0);
	int idx(0);
	int cnt(0);
	cin >> N;	
	string s_num("666");	

	while (cnt<N) {
		for (idx = 0; idx+2 < s_num.size(); ++idx) {
			if (s_num[idx] == '6'&&s_num[idx+1]=='6'&&s_num[idx+2]=='6') {
				cnt++;
				break;
			}
		}
		if(cnt!=N) s_num = to_string(stoi(s_num) + 1);
	}
	cout << s_num;
}