#include<iostream>
#include<algorithm>
#include <string>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector <pair<int, string>>v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].second;
		v[i].first = v[i].second.length();
	}
	//first에는 입력된 글자의 길이,second 글자
	sort(v.begin(), v.end());

	cout << v[0].second << "\n";//0번째 출력.

	for (int i = 1; i < n; i++)
		if (v[i].second != v[i - 1].second)
			cout << v[i].second << "\n";

}