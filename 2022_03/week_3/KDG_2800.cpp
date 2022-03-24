#include<iostream>
#include<string>
#include<stack>
#include<set>
#include<vector>
using namespace std;
string s;
vector<pair<int, int>> v;
bool avail[200];
int main() {
	cin >> s;
	stack<int> st;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (c == '(') {
			st.push(i);
		}//¿©´Â °ýÈ£´Â push
		else if (c == ')') {
			v.push_back({ st.top(),i });
			st.pop();
		}
	}
	set<string> ans;
	int n = v.size();
	for(int i=1;i<(1<<n))
}