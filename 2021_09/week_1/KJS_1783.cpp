//문제풀이: https://githubseob.tistory.com/73

#include <iostream>
using namespace std;

int main() {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;

	if (N == 1) cout << 1;
	else if (N == 2) {
		if (M < 7)	cout << (M + 1) / 2;
		else cout << 4;
	}
	else {
		if (M <= 4) cout << M;
		else if (M >= 7) cout << M - 2;
		else cout << 4;
	}
}