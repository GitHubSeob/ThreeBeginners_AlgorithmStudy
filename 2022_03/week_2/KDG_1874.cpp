#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int n(0);
int cnt(0);
int seq[100001];
int main() {
	stack<int>s;
	vector<char> ans;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> seq[i];
	
	
	for (int i = 1; i <= n; i++) {
		s.push(i);
		ans.push_back('+');

		//스택이 비어있지 않고,cnt번째 수열이 백터의 마지막 원소가 같을경우
		while (!s.empty() && s.top() == seq[cnt]) {
			s.pop();
			ans.push_back('-');
			cnt++;
		}
	}

	if 
		(!s.empty()) cout << "NO";//수열이 만들어졌다면 벡터가 비어있어야 한다.
	else 
		for (int i = 0; i < ans.size(); i++)cout << ans[i] << '\n';
}