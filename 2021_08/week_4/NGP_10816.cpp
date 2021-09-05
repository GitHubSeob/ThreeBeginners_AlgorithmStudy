#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, num;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	cin >> n;
	vector<int> card(n);
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card.begin(), card.end());
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		cout << upper_bound(card.begin(), card.end(), num) - lower_bound(card.begin(), card.end(), num) << ' ';
	}

}
