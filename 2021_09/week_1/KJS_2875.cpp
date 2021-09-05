//문제풀이: https://githubseob.tistory.com/71

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0, M = 0, K = 0;	
	cin >> N >> M >> K;

	int team = min(N / 2, M);
	int alone = N + M - (3 * team);
	
	K -= alone;
	
	if (K <= 0) cout << team;	
	else cout << team - (K + 2) / 3;
}