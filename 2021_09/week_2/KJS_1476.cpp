//문제풀이: https://githubseob.tistory.com/86

#include <iostream>
using namespace std;

int main() {
	int E, S, M = 0;
	cin >> E >> S >> M;

	int idx = 0;
	int year = 0;
	while (1) {
		if ((year % 15) + 1 == E && (year % 28) + 1 == S && (year % 19) + 1 == M) {
			cout << year + 1;
			break;
		}
		else year++;
	}
}