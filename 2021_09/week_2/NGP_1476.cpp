#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int e, s, m;
	int ans = 1;

	cin >> e >> s >> m;
	while (1) {
		if ((ans - e) % 15 == 0 && (ans - s) % 28 == 0 && (ans - m) % 19 == 0) {
			break;
		}
		ans++;
	}
	cout << ans << endl;

}