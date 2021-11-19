#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<string>s(5,"");
	int idx(0);
	string s1("");
	int max_size(0);
	for (idx = 0; idx < 5; ++idx) {
		cin >> s1;
		s[idx] = s1;
		int s_size(s1.size());
		max_size = max(max_size, s_size);
	}
	int idx2(0);
	
	idx = 0;
	while (idx2<max_size) {		
		for (idx = 0; idx < 5; ++idx) {
			
				cout << s[idx][idx2];
		}
		idx2++;
	}
}