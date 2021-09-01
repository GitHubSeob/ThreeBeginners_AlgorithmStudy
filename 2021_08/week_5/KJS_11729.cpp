//문제풀이: https://githubseob.tistory.com/69

#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int N, char start, char via, char end) {
	if (N == 1) cout << start << ' ' << end << '\n';
	else
	{
		hanoi(N - 1, start, end, via);
		cout  << start << ' ' << end << '\n';
		hanoi(N - 1, via, start, end);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	cin >> N;
	cout << (int)pow(2, N) - 1 << '\n';
	hanoi(N, '1', '2', '3');
}