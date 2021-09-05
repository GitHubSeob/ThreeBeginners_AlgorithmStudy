//문제풀이: https://githubseob.tistory.com/72

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string N = "";
	cin >> N;

	int sum = 0;
	for (int idx = 0; idx < N.size(); ++idx)
		sum += N[idx] - '0';

	sort(N.begin(), N.end(), greater<>());

	if (N[N.size() - 1] != '0' || sum % 3 != 0)	cout << -1;
	else cout << N;

}